/*
*	Handles controlling aerophone valves
*
*	This code will be the sole firmware of the ATMEGA2560.
*	All aspects of communication, motor, control, debugging, etc
*	will be part of it.
*	By Paulo
*
*	Adapted by Andrew
*/

#include <Arduino.h>
#include "Status.h"
#include "Comm.h"
#include "PinDef.h"
#include "AerophoneController.h"

#define BOARD_ID 0x03

// Create Required Variables
unsigned long loopTime = 0;

// Instantiate all classes
// Create instance of status class
Status status;
// Create instance of Communication Classes
Comm commFTDI(&Serial, &status, 1, BOARD_ID);
// Create instance of the solenoid Controller
AerophoneController driver1(&status, DRV1, 0);
AerophoneController driver2(&status, DRV2, 1);

void setup(){
	/* Start-Up Delay */
	delay(1000);

	/* Begin Serial Communication */
	Serial.begin(115200); // FTDI Port

	/* Set Up all Solenoid Drivers */
	driver1.begin();
	driver2.begin();
}

void loop(){
	// Save time the loop has begun running 
	loopTime = micros();
	
	/* Call Updates to All Classes */
	// Communication classes
	commFTDI.update();
	driver1.update();
	driver2.update();
	// Save the loop time in status structure
	status.loopTime.set(micros() - loopTime);
}
