#include <PinDef.h>
#include <Wire.h>
/*
	Copyright Nathan Hughes 2015
              Paulo Cavahlo 2015

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

int pinSolOn[] = {DRV1, DRV2, DRV3, DRV4, DRV5, DRV6, DRVS};
int pinSolEnbl[] = {DRV_ENBL}; // Active LOW
int pinSolFault[] = {DRV_FAULT}; // Fault when LOW

int iSolOn = -1; // Keeps track of which solenoid was last toggled
int iStep = 1; // Keeps track of the step for the stepper motor

void step(int stepNum){
	/* Set Stepper Driver to Given Full Step */
	switch (stepNum){
		case 1: 
			digitalWrite(STEP_IN1, LOW);
			digitalWrite(STEP_IN2, LOW);
			digitalWrite(STEP_IN3, HIGH);
			digitalWrite(STEP_IN4, HIGH);
			break;
		case 2: 
			digitalWrite(STEP_IN1, HIGH);
			digitalWrite(STEP_IN2, LOW);
			digitalWrite(STEP_IN3, HIGH);
			digitalWrite(STEP_IN4, LOW);
			break;
		case 4: 
			digitalWrite(STEP_IN1, LOW);
			digitalWrite(STEP_IN2, HIGH);
			digitalWrite(STEP_IN3, LOW);
			digitalWrite(STEP_IN4, HIGH);
			break;
		case 3: 
			digitalWrite(STEP_IN1, HIGH);
			digitalWrite(STEP_IN2, HIGH);
			digitalWrite(STEP_IN3, LOW);
			digitalWrite(STEP_IN4, LOW);
			break;
		default:
			digitalWrite(STEP_IN1, LOW);
			digitalWrite(STEP_IN2, LOW);
			digitalWrite(STEP_IN3, LOW);
			digitalWrite(STEP_IN4, LOW);
			break;
	}
}


byte BEGIN_FLAG = 0x00;
byte FRAME_ID = 0x00;
byte LENGTH = 0x00;
byte INCOMING;
byte MESSAGE_COUNT = 0x00;
byte CHECKSUM_VALUE = 0x00;

void process_I2C() {
	INCOMING = Wire.read();
	if (!BEGIN_FLAG) {
		if (INCOMING == 0xFD) {
			BEGIN_FLAG = 0x01;
		}
	}
	if (BEGIN_FLAG) {
		switch (MESSAGE_COUNT) {
			case 0: 
				LENGTH = INCOMING;
				MESSAGE_COUNT++;
				CHECKSUM_VALUE += INCOMING;
				break;
			case 1:
				FRAME_ID = INCOMING;
				MESSAGE_COUNT++;
				CHECKSUM_VALUE += INCOMING;
				break;
			default:
				if (MESSAGE_COUNT <= LENGTH) {
					process_message(INCOMING, FRAME_ID);
					CHECKSUM_VALUE += INCOMING;
				}	
				else {
					process_checksum(INCOMING, CHECKSUM_VALUE);
				}
				MESSAGE_COUNT++;
				break;
		}
	}
}


void process_message(byte incoming, byte frame_id) {
	switch (frame_id) {
		case SOLENOID_ENABLE:
			break;
		case SOLENOID_MULTIPLE_ON:
			break;
		case SOLENOID_SINGLE_ON:
			break;
		case SOLENOID_ALL_ON:
			break;
		case SOLENOID_MULTIPLE_OFF:
			break;
		case SOLENOID_SINGLE_OFF:
			break;
		case SOLENOID_ALL_OFF:
			break;
		case STEPPER_MODE:
			break;
		case STEPPER_MODE:
			break;
	}
}

void setup(){
	delay(250); // Start-up Delay

	/*** Set Pins as Outputs or Pull-Up ***/

	/* Solenoid Driver Related Pins */
	for (int i=0; i<sizeof(pinSolOn)/sizeof(int); i++){
		pinMode(pinSolOn[i], OUTPUT);
	}
	for (int i=0; i<sizeof(pinSolEnbl)/sizeof(int); i++){
		pinMode(pinSolEnbl[i], OUTPUT);
	}
	for (int i=0; i<sizeof(pinSolFault)/sizeof(int); i++){
		pinMode(pinSolFault[i], INPUT_PULLUP);
	}

	/* Stepper Driver Related Pins */
	pinMode(STEP_EN1, OUTPUT);
	pinMode(STEP_EN2, OUTPUT);
	pinMode(STEP_EN3, OUTPUT);
	pinMode(STEP_EN4, OUTPUT);
	pinMode(STEP_IN1, OUTPUT);
	pinMode(STEP_IN2, OUTPUT);
	pinMode(STEP_IN3, OUTPUT);
	pinMode(STEP_IN4, OUTPUT);
	pinMode(STEP_NRES, OUTPUT);
	pinMode(STEP_NSLEEP, OUTPUT);
	pinMode(STEP_NFAULT, INPUT_PULLUP);

	/* Other Pins */
	pinMode(LED_OK, OUTPUT);

	/* Turn ON all Solenoid Drivers at 50% */
	for (int i=0; i<sizeof(pinSolEnbl); i++){
		analogWrite(pinSolEnbl[i], 123);
	}

	/* Enable all Outputs of Stepper Driver */
	analogWrite(STEP_EN1, 255);
	analogWrite(STEP_EN2, 255);
	analogWrite(STEP_EN3, 255);
	analogWrite(STEP_EN4, 255);

	/* Enable Stepper Driver */
	digitalWrite(STEP_NSLEEP, HIGH);
	digitalWrite(STEP_NRES, HIGH);

	/* Setup I2C Communications */
	Wire.begin(DEV_ADDR);
}

void loop(){
	while (Wire.available() > 0) {
		process_I2C();
	}
}


	delay(100); // Determines Time Between Events
	/* Reset Solenoid Tracker if Reached End of List */
	iSolOn = 
		(iSolOn >= sizeof(pinSolOn)/sizeof(int))? 0 : iSolOn + 1;
	/* Toggle All Solenoids and OK LED */
	digitalWrite(pinSolOn[iSolOn], !digitalRead(pinSolOn[iSolOn]));

	/* Reset Step TRacker if Reached 4 */
	iStep = (iStep >= 4)? 1 : iStep + 1;
	/* Toggle All Solenoids and OK LED */
	/* Step the Stepper Driver */
	step(iStep);