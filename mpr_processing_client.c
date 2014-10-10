#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>


#include <jack/jack.h>

#define AMPLITUDE_CONSTANT 1024
#define FREQUENCY_CONSTANT 0.07
#define BUFFER_SIZE 2048
#define ACF_SIZE 1024
#define SAMPLE_FREQUENCY 96000

long long acf_results[ACF_SIZE];
long long buffer[BUFFER_SIZE];

jack_port_t *input_port;
jack_client_t *client;

jack_default_audio_sample_t *in_buffer;
jack_nframes_t buffer_index;
jack_nframes_t buffer_size = 2048;

int count = 0;
long session_count = 0;


int detect_peak(int start, int end) {
	int i;
	for (i = start+1; i < end-1; i++ )
	{
		if (acf_results[i] > 0 && acf_results[i-1] < acf_results[i] && acf_results[i] > acf_results[i+1]) {
			return i;
		}
	}
	return -1;
}

int get_freq(peak) {
	return SAMPLE_FREQUENCY / peak;
}

int acf(int lag) {
	int i;
	long long sum = 0;
	for (i = 0; i < BUFFER_SIZE/2; i ++) {
		sum += buffer[i]*buffer[i+lag];
	}
	return sum;
}


//Called every time audio is available for processing
int processAvailable (jack_nframes_t nframes, void *arg) {
	jack_default_audio_sample_t *in;
	int k;

	in = jack_port_get_buffer (input_port, nframes);
	for (k=0; k<nframes; k++) {
		in_buffer[buffer_index] = in[k];
		buffer[buffer_index] = (int)AMPLITUDE_CONSTANT*in[k];
		if (in[k] != 0) {
			// printf("%lld\n", buffer[buffer_index]);
			count++;
		}
		buffer_index = (buffer_index + 1) % buffer_size;

	}
	int i;
	int val_count = 0;

	for (i = 0; i < ACF_SIZE; i++) {
		acf_results[i] = acf(i);
		// printf("%lld\n", acf_results[i]);
	}
	while (val_count != -1) {
		val_count = detect_peak(val_count+1, ACF_SIZE);
		if (val_count != -1) {
			printf("Peak at %d Corresponding Frequency: %d\n", val_count, get_freq(val_count));
		}
	}
	
	// printf("Index: %ld Values over zero: %d Frames Processed: %d\n", session_count, count, nframes);
	session_count += 1;
	return 0;      
}

void onShutdown (void *arg) {exit (1);}

int main (int argc, char *argv[]) {
	const char **ports;
	const char *client_name = "mpr_client";
	jack_status_t status;

	in_buffer = (jack_default_audio_sample_t *) malloc( buffer_size * sizeof(jack_default_audio_sample_t));
	
	if (in_buffer == NULL) { exit(1); }

	memset(in_buffer, 0, buffer_size * sizeof(jack_default_audio_sample_t));

	client = jack_client_open (client_name, JackNoStartServer, &status);
	
	if (client == NULL) { exit(1); }
	
	if (status & JackNameNotUnique) {client_name = jack_get_client_name(client);fprintf (stderr, "unique name `%s' assigned\n", client_name);}

	jack_set_process_callback (client, processAvailable, 0); //start everything
	jack_on_shutdown (client, onShutdown, 0); //setup shutting down the client

	printf ("engine sample rate: %d" PRIu32 "\n", jack_get_sample_rate (client)); //get audio sampling rate

	input_port = jack_port_register (client, "input", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0); //make input
	
	if (input_port == NULL) {exit (1);}

	if (jack_activate (client)) {exit (1);}

	sleep (-1); //run forever
	jack_client_close (client); //if sleep causes a problem
	exit (1);
}