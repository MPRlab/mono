#include "status.h"

// Constructor
init_status(Status * s) {

	// Set the default pulse hold time for the drivers
	for (uint8_t i = 0; i < 6; i++) {

		set_data(&(s->driver_pulse_hold_time) + i, PULSE_HOLD_TIME);
		set_data(&(s->hold_pwm) + i, HOLD_PWM);
		set_data(&(s->pulse_pwm) + i, PULSE_PWM);

	}

}

void set_comm_last_checksum(Status * status, uint8_t checksum) {

}

uint8_t get_checksum(Status * status) {
	return 0x00;
}

void increment_valid_checksums(Status * status) {

}

void increment_invalid_checksums(Status * status) {

}

void set_comm_packet_per_second_status(Status * status, uint8_t packets_per_second) {

}

void tag_status_comm_acknowledge(Status * status) {

}

void increment_comm_num_start_delim_fail(Status * status){
	
}

