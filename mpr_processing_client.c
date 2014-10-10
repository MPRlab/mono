#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include <jack/jack.h>

jack_port_t *input_port;
jack_client_t *client;

jack_default_audio_sample_t *in_buffer;
jack_nframes_t buffer_index;
jack_nframes_t buffer_size = 1024;

int count = 0;
long session_count = 0;
//Called every time audio is available for processing
int processAvailable (jack_nframes_t nframes, void *arg) {
	jack_default_audio_sample_t *in;
	int k;

	in = jack_port_get_buffer (input_port, nframes);
	for (k=0; k<nframes; k++) {
		in_buffer[buffer_index] = in[k];
		if (in[k] != 0) {
			count++;
		}
		buffer_index = (buffer_index + 1) % buffer_size;

	}	
	printf("Index: %ld Values over zero: %d\n", session_count, count);
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