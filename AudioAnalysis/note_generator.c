#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <signal.h>
#include <getopt.h>
#include <string.h>
#include <jack/jack.h>
#include <jack/transport.h>

#define BPM 120 //number of notes per minute to generate
#define DURATION 1000 //duration in ms

typedef jack_default_audio_sample_t sample_t;
const double PI = 3.14;
jack_client_t *client;
jack_port_t *output_port;

unsigned long sr;
int freq = 880;

jack_nframes_t tone_length, wave_length;
sample_t *wave;
long offset = 0;
int transport_aware = 0;
jack_transport_state_t transport_state;

static void signal_handler(int sig) {jack_client_close(client);exit(0);}

static void process_silence (jack_nframes_t nframes)
{
	sample_t *buffer = (sample_t *) jack_port_get_buffer (output_port, nframes);
	memset (buffer, 0, sizeof (jack_default_audio_sample_t) * nframes);
}


jack_nframes_t last_time;
jack_time_t last_micro_time;
static void process_audio (jack_nframes_t nframes)
{
	sample_t *buffer = (sample_t *) jack_port_get_buffer (output_port, nframes);
	jack_nframes_t frames_left = nframes;
	while (wave_length - offset < frames_left) {
		memcpy (buffer + (nframes - frames_left), wave + offset, sizeof (sample_t) * (wave_length - offset));
		frames_left -= wave_length - offset;
		offset = 0;
	}
	if (frames_left > 0) {
		memcpy (buffer + (nframes - frames_left), wave + offset, sizeof (sample_t) * frames_left);
		offset += frames_left;
	}
}

static int process (jack_nframes_t nframes, void *arg)
{
	if (transport_aware) {
		jack_position_t pos;
		if (jack_transport_query (client, &pos) != JackTransportRolling) {
			process_silence (nframes);
			return 0;
		}
		offset = pos.frame % wave_length;
	}
	process_audio (nframes);
	return 0;
}

int main (int argc, char *argv[])
{
	/*sample_t scale;
	int i, attack_length, decay_length;
	double *amp;
	double max_amp = 0.5;
	int option_index;
	int opt;
	int got_bpm = 0;
	int attack_percent = 1, decay_percent = 10, dur_arg = 100;
	char *client_name = 0;
	char *bpm_string = "bpm";
	int verbose = 0;
	jack_status_t status;

	 Initial Jack setup, get sample rate 
	if (!client_name) {
		client_name = (char *) malloc (9 * sizeof (char));
		strcpy (client_name, "generator");
	}
	if ((client = jack_client_open (client_name, JackNoStartServer, &status)) == 0) {
		fprintf (stderr, "JACK server not running?\n");
		return 1;
	}

	jack_set_process_callback (client, process, 0);
	output_port = jack_port_register (client, bpm_string, JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);
	sr = jack_get_sample_rate (client);
	
	wave_length = 60 * sr / bpm;
	tone_length = sr * dur_arg / 1000;
	attack_length = tone_length * attack_percent / 100;
	decay_length = tone_length * decay_percent / 100;
	scale = 2 * PI * freq / sr;
	if (tone_length >= wave_length) {
		fprintf (stderr, "invalid duration (tone length = %u, wave length = %u\n", tone_length, wave_length);
			return -1;
		}
		if (attack_length + decay_length > (int)tone_length) {
			fprintf (stderr, "invalid attack/decay\n");
			return -1;
		}
 Build the wave table 
		wave = (sample_t *) malloc (wave_length * sizeof(sample_t));
		amp = (double *) malloc (tone_length * sizeof(double));
		for (i = 0; i < attack_length; i++) {
			amp[i] = max_amp * i / ((double) attack_length);
		}
		for (i = attack_length; i < (int)tone_length - decay_length; i++) {
			amp[i] = max_amp;
		}
		for (i = (int)tone_length - decay_length; i < (int)tone_length; i++) {
			amp[i] = - max_amp * (i - (double) tone_length) / ((double) decay_length);
		}
		for (i = 0; i < (int)tone_length; i++) {
			wave[i] = amp[i] * sin (scale * i);
		}
		for (i = tone_length; i < (int)wave_length; i++) {
			wave[i] = 0;
		}
		if (jack_activate (client)) {
			fprintf (stderr, "cannot activate client\n");
			goto error;
		}
		signal(SIGQUIT, signal_handler);
		signal(SIGTERM, signal_handler);
		signal(SIGHUP, signal_handler);
		signal(SIGINT, signal_handler);
		sleep(-1);
		jack_client_close(client);
		error:
		free(amp);
		free(wave);
		exit (0);*/
	}
