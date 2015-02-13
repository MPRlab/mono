/*
	Copyright Nathan Hughes 2015

    This file is part of code developed for the Music Perception and Robotics 
	Labrotory at Worcester Polytechnic Institute.

    This file is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This file is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    somewhere in this repository.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
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

struct timespec start_time;

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
	static char onset_flag = 0x00;
	int k;
	int i;
	
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
	
	for (i = 0; i < ACF_SIZE; i++) {
		acf_results[i] = acf(i);
	}

	int peak = detect_peak(1, ACF_SIZE);
	int freq = 0;
	
	if (peak != -1) {
		freq = get_freq(peak);
	}

	struct timespec result;

	clock_gettime(CLOCK_REALTIME, &result);
	time_t seconds = result.tv_sec - start_time.tv_sec;
	long nano_seconds = result.tv_nsec - start_time.tv_nsec;
	if (nano_seconds < 0) {
		seconds--;
		nano_seconds += 1000000000;
	}
	if (freq != 0) {
		if (!onset_flag) {
			onset_flag = 0x01;
			printf("Frequency: %d began at time: %lld s %ld ns\n", freq, (long long) seconds, nano_seconds);
		}
	}

	if (freq == 0) {
		if (onset_flag) {
			onset_flag = 0x00;
			printf("Frequency: %d ended at time: %lld s %ld ns\n", freq, (long long) seconds, nano_seconds);
		}
	}

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

	clock_gettime(CLOCK_REALTIME, &start_time);

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
