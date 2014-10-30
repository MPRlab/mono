#define AMPLITUDE_CONSTANT 1024
#define FREQUENCY_CONSTANT 0.07
#define BUFFER_SIZE 1024
#define ACF_SIZE 512
#define SAMPLE_FREQUENCY 44100

#include <math.h>
#include <stdio.h>

long long buffer[BUFFER_SIZE];
long long acf_results[ACF_SIZE];

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

int detect_last_peak(int start, int end) {
	int i;
	for (i = end-1; i > start +1; i--) {
		if (acf_results[i] > 0 && acf_results[i+1] < acf_results[i] && acf_results[i] > acf_results[i+1]) {
			return i;
		}
	}
	return -1;
}

int get_freq(peak1, peak2) {
	int gap = peak2 - peak1;
	return SAMPLE_FREQUENCY / gap;
}

int get_freq_correct(peak) {
	return SAMPLE_FREQUENCY / peak;
}

int create_signal() {
	int i; 
	for (i = 0; i < BUFFER_SIZE; i ++) {
		buffer[i] = (long)(AMPLITUDE_CONSTANT * sin(i*FREQUENCY_CONSTANT));
	}
}

int acf(int lag) {
	int i;
	long long sum = 0;
	for (i = 0; i < BUFFER_SIZE/2; i ++) {
		sum += buffer[i]*buffer[i+lag];
	}
	return sum;
}

int main() {
	create_signal();
	int i;
	int lag;
	for (i = 0; i < BUFFER_SIZE; i++) {
		//printf("%d, %lld\n", i, buffer[i]);
	}
	for (i = 0; i < ACF_SIZE; i++) {
		acf_results[i] = acf(i);
		//printf("%d, %lld\n", i, acf_results[i]);
	}
	int count = 0; 
	while (count != -1) {
		count = detect_peak(count+1, ACF_SIZE);
		if (count != -1) {
			printf("Peak at %d Corresponding Frequency: %d\n", count, get_freq_correct(count));
		}
	}
	return 0;
}