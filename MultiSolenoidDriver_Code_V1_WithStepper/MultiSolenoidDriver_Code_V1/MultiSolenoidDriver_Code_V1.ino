/*
*	This code will be the sole firmware of the ATMEGA2560.
*	All aspects of communication, motor, control, debugging, etc
*	will be part of it.
*	By Paulo
*/

#include <Arduino.h>
#include "Status.h"
#include "Comm.h"
#include "PinDef.h"
#include "SolenoidController.h"
#include "PowerSolenoidController.h"
#include "StepperController.h"

#define BOARD_ID 0x02

// Create Required Variables
unsigned long loopTime = 0;

// Driver Enable Pins 
int enblPins[7] = {DRV_ENBL};
int faultPins[7] = {DRV_FAULT};

// Instantiate all classes
// Create instance of status class
Status status;
// Create instance of Communication Classes
Comm commFTDI(&Serial, &status, 1, BOARD_ID);
// Create instance of the solenodi Controller
SolenoidController driver1(&status, DRV1, int(enblPins[0]), int(faultPins[0]), 0);
SolenoidController driver2(&status, DRV2, int(enblPins[1]), int(faultPins[1]), 1);
SolenoidController driver3(&status, DRV3, int(enblPins[2]), int(faultPins[2]), 2);
SolenoidController driver4(&status, DRV4, int(enblPins[3]), int(faultPins[3]), 3);
SolenoidController driver5(&status, DRV5, int(enblPins[4]), int(faultPins[4]), 4);
SolenoidController driver6(&status, DRV6, int(enblPins[5]), int(faultPins[5]), 5);
PowerSolenoidController driverP(&status, DRVS, int(enblPins[6]), int(faultPins[6]));
StepperController stepper(&status, STEP_IN1, STEP_IN2, STEP_IN3, STEP_IN4, 
						  STEP_EN1, STEP_EN2, STEP_EN3, STEP_EN4, STEP_NSLEEP, STEP_NRES);

void setup(){
	/* Start-Up Delay */
	delay(1000);

	/* Begin Serial Communication */
	Serial.begin(115200); // FTDI Port

	/* Set Up all Solenoid Drivers */
  // set solenoid PWM timer frequencies to 31.374 KHz
  // http://sobisource.com/arduino-mega-pwm-pin-and-frequency-timer-control/
  TCCR1B = (TCCR1B & 0xF8) | 0x01 ; // set last 3 bits to 0 and or with 1
  TCCR2B = (TCCR2B & 0xF8) | 0x01 ;
  TCCR4B = (TCCR4B & 0xF8) | 0x01 ;
	driver1.begin();
	driver2.begin();
	driver3.begin();
	driver4.begin();
	driver5.begin();
	driver6.begin();
	driverP.begin();

	/* Set up the stepper driver */
	stepper.begin();
}

void loop(){
	// Save time the loop has begun running 
	loopTime = micros();
	
	/* Call Updates to All Classes */
	// Communication classes
	commFTDI.update();
	driver1.update();
	driver2.update();
	driver3.update();
	driver4.update();
	driver5.update();
	driver6.update();
	driverP.update();
	stepper.update();
	
	// Save the loop time in status structure
	status.loopTime.set(micros() - loopTime);

}
