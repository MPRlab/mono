//MPR Processing Client

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

//Called every time audio is available for processing
int
process (jack_nframes_t nframes, void *arg)
{
	jack_default_audio_sample_t *in
	int k;
	
	in = jack_port_get_buffer (input_port, nframes);
	for (k=0; k<nframes; k++) {
		*in_buffer[buffer_index] = in[k];
		buffer_index = (buffer_index + 1) % buffer_size;
	}	
	return 0;      
}

void
jack_shutdown (void *arg)
{
	fprintf(stderr, "JACK shut down, exiting ...\n"); //if server disappears
	exit (1);
}

int
main (int argc, char *argv[])
{
	const char **ports;
	const char *client_name = "mpr_client";
	const char *server_name = NULL;
	jack_options_t options = JackNullOption;
	jack_status_t status;

	*in_buffer = malloc( buffer_size * sizeof(jack_default_audio_sample_t));
	if *in_buffer == NULL) {
		fprintf (stderr, "no memory");
		exit(1);
	}

	memset *in_buffer, 0, buffer_size * sizeof(jack_default_audio_sample_t));

	//error checking and initializing
	client = jack_client_open (client_name, options, &status, server_name);
	if (client == NULL) {
		fprintf (stderr, "jack_client_open() failed, "
			 "status = 0x%2.0x\n", status);
		if (status & JackServerFailed) {
			fprintf (stderr, "Unable to connect to JACK server\n");
		}
		exit (1);
	}
	if (status & JackServerStarted) {
		fprintf (stderr, "JACK server started\n");
	}
	if (status & JackNameNotUnique) {
		client_name = jack_get_client_name(client);
		fprintf (stderr, "unique name `%s' assigned\n", client_name);
	}

	jack_set_process_callback (client, process, 0); //start everything
	jack_on_shutdown (client, jack_shutdown, 0); //setup shutting down the client
	printf ("engine sample rate: %" PRIu32 "\n", jack_get_sample_rate (client)); //get audio sampling rate

	input_port = jack_port_register (client, "input", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0); //make input
	
	//error checking
	if (input_port == NULL) {
		fprintf(stderr, "no more JACK ports available\n");
		exit (1);
	}

	//more error checking
	if (jack_activate (client)) {
		fprintf (stderr, "cannot activate client");
		exit (1);
	}

	sleep (-1); //run forever
	jack_client_close (client); //if sleep causes a problem
	exit (1);
}

