/*
*	This class will keep the status of all microcontroller 
*	attributes.
*/

#ifndef Status_H
#define Status_H

#include <Arduino.h>
#include "TData.h"
#include "TArray.h"

#define PULSE_HOLD_TIME 800 // ms between pulse and hold
#define HOLD_PWM 30 // pw at pulse
#define PULSE_PWM 0 // pw at hold

class Status{
	public:
		// Constructor
		Status(){
			// Set the default pulse hold time for the drivers
			for (int i=0; i<6; i++){
				driverPulseHoldTime[i].set(PULSE_HOLD_TIME);
				holdPWM[i].set(HOLD_PWM);
				pulsePWM[i].set(PULSE_PWM);
			}
		}

		/******* Create all necessary ******/
		
		// Variables that stores the state of all solenoids
		// Each 8 solenoid group makes up one variable
		TData<byte> solenoidGroup[3];
		TData<bool> powerSolenoid;
		// Solenoid Parameter Related
		TData<unsigned int> driverPulseHoldTime[7];
		TData<byte> pulsePWM[7];
		TData<byte> holdPWM[7];
		// Serial Related 
		TArray<unsigned int> commNumStartDelimFail; // Start Delim Fail
		TArray<unsigned int> commNumHeaderFail; // Header Fails
		TArray<unsigned int> commNumChecksumFail; // Checksum Fails
		TArray<unsigned int> commNumChecksumPass; // Checksum Passed
		TArray<unsigned int> commPacketPerSecond;
		TArray<byte> commLastChecksum;
		TArray<bool> commAck;
		// Keeps the number of steps left for the stepper motor
		TData<signed int> stepperStepsLeft;
		// Debugging Related
		TData<unsigned long> loopTime;
};


#endif
