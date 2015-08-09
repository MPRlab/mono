/*
*	This class will keep the status of all microcontroller 
*	attributes.
*/

#ifndef __STATUS_H__
#define __STATUS_H__


#include "t_data.h"
#include "t_array.h"

#define PULSE_HOLD_TIME 800 // ms between pulse and hold
#define HOLD_PWM 30 // pw at pulse
#define PULSE_PWM 0 // pw at hold

struct Status {
	TData solenoid_group[3];
	TData power_solenoid;
	// Solenoid Parameter Related
	TData driver_pulse_hold_time[7];
	TData pulse_pwm[7];
	TData hold_pwm[7];


	// TData<unsigned long> loopTime;	TBD	
};

typedef struct Status Status;


/******* Create all necessary ******/

// Variables that stores the state of all solenoids
// Each 8 solenoid group makes up one variable
// Serial Related 
TArray<unsigned int> commNumStartDelimFail; // Start Delim Fail
TArray<unsigned int> commNumHeaderFail; // Header Fails
TArray<unsigned int> commNumChecksumFail; // Checksum Fails
TArray<unsigned int> commNumChecksumPass; // Checksum Passed
TArray<unsigned int> commPacketPerSecond;
TArray<byte> commLastChecksum;
TArray<bool> commAck;
// Debugging Related




#endif