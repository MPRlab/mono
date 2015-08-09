/*
*	This class will keep the status of all microcontroller 
*	attributes.
*/

#ifndef __STATUS_H__
#define __STATUS_H__


#include "t_data.h"
#include "t_array.h"
#include <avr/stdint.h>

#define PULSE_HOLD_TIME 800 // ms between pulse and hold
#define HOLD_PWM 30 // pw at pulse
#define PULSE_PWM 0 // pw at hold

struct Status {
	
	Data solenoid_group[3];
	Data power_solenoid;
	
	Data driver_pulse_hold_time[7];
	Data pulse_pwm[7];
	Data hold_pwm[7];

	Array commNumStartDelimFail; // Start Delim Fail
	Array commNumHeaderFail; // Header Fails
	Array commNumChecksumFail; // Checksum Fails
	Array commNumChecksumPass; // Checksum Passed
	Array commPacketPerSecond;
	Array commLastChecksum;
	Array commAck;

	// Data<unsigned long> loopTime;	TBD	
};

typedef struct Status Status;


void set_comm_last_checksum(Status * status, uint8_t checksum);

uint8_t get_checksum(Status * status);

void increment_valid_checksums(Status * status);

void increment_invalid_checksums(Status * status);

void set_comm_packet_per_second_status(Status * status, uint8_t packets_per_second);

void tag_status_comm_acknowledge(Status * status);

void increment_comm_num_start_delim_fail(Status * status);

#endif