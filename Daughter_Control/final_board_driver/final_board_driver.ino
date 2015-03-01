#include "PinDef.h"
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

byte pinSolOn[] = {DRV1, DRV2, DRV3, DRV4, DRV5, DRV6, DRVS};
byte pinSolEnbl[] = {DRV_ENBL}; // Active LOW
byte pinSolFault[] = {DRV_FAULT}; // Fault when LOW

byte BEGIN_FLAG = 0x00;
byte FRAME_ID = 0x00;
byte LENGTH = 0x00;
byte INCOMING = 0x00;
byte MESSAGE_COUNT = 0x00;
byte CHECKSUM_VALUE = 0x00;
byte STEPPER_MODE_FLAG = ALWAYS_ENABLED;
byte message_bytes[NUM_SOLENOIDS];

int step_position = 0;

void step(byte stepNum){
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
		case 3: 
			digitalWrite(STEP_IN1, LOW);
			digitalWrite(STEP_IN2, HIGH);
			digitalWrite(STEP_IN3, LOW);
			digitalWrite(STEP_IN4, HIGH);
			break;
		case 4: 
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

void turn_all_on() {
	for (byte i = 0; i < NUM_SOLENOIDS; i ++) {
		digitalWrite(pinSolOn[i], HIGH);
	}
}

void turn_all_off() {
	for (byte i = 0; i < NUM_SOLENOIDS; i ++) {
		digitalWrite(pinSolOn[i], LOW);
	}
}

void set_enables(byte incoming) {
	if (0x01 && incoming) {
		analogWrite(pinSolEnbl[0], 123);
	}
	else {
		analogWrite(pinSolEnbl[0], 0);	
	}
	if (0x02 && incoming) {
		analogWrite(pinSolEnbl[1], 123);
	}
	else {
		analogWrite(pinSolEnbl[1], 0);	
	}
	if (0x04 && incoming) {
		analogWrite(pinSolEnbl[2], 123);
	}
	else {
		analogWrite(pinSolEnbl[2], 0);	
	}
	if (0x0F && incoming) {
		analogWrite(pinSolEnbl[3], 123);
	}
	else {
		analogWrite(pinSolEnbl[3], 0);	
	}
	if (0x10 && incoming) {
		analogWrite(pinSolEnbl[4], 123);
	}
	else {
		analogWrite(pinSolEnbl[4], 0);	
	}
	if (0x20 && incoming) {
		analogWrite(pinSolEnbl[5], 123);
	}
	else {
		analogWrite(pinSolEnbl[5], 0);	
	}
}

void set_single_on(byte incoming) {
	if (0 < incoming && incoming < NUM_SOLENOIDS) {
		digitalWrite(pinSolOn[incoming], HIGH); 
	}
}

void set_single_off(byte incoming) {
	if (0 < incoming && incoming < NUM_SOLENOIDS) {
		digitalWrite(pinSolOn[incoming], LOW);
	}
}

void set_solenoids_on() {
	for (int i = 0; i < MESSAGE_COUNT-1; i++) {
		digitalWrite(pinSolOn[message_bytes[i]], HIGH);
	}
}

void set_solenoids_off() {
	for (int i = 0; i < MESSAGE_COUNT-1; i++) {
		digitalWrite(pinSolOn[message_bytes[i]], LOW);
	}
}

void stepper_move(int steps) {
	step_position += steps;
  	if (steps < 0) {
		steps = -1 * steps;
		for (int i = 0; i < steps; i ++) {
			for (byte j = 4; j > 0; j--) {
				step(j);
			}
			delay(STEPPER_DELAY);
		}
	}
	else {
		for (int i = 0; i < steps; i ++) {
			for (int j = 1; j <= 4; j++) {
				step(j);
			}
			delay(STEPPER_DELAY);
		}
	}

}

void process_checksum(byte incoming, byte checksum_value) {
	if (incoming == 0xFF - checksum_value) {
		Wire.write(ACKNOWLEDGEMENT);
	}
	else {
		Wire.write(CHECKSUM_ERROR);
	}
}

void process_message(byte incoming, byte frame_id, byte final) {
	switch (frame_id) {
		case SOLENOID_ENABLE:
			set_enables(incoming);
			break;
		case SOLENOID_MULTIPLE_ON:
			if (final) {
				message_bytes[MESSAGE_COUNT-1] = incoming;
				set_solenoids_on();
			}
			else {
				message_bytes[MESSAGE_COUNT-1] = incoming;
			}
			break;
		case SOLENOID_SINGLE_ON:
			set_single_on(incoming);
			break;
		case SOLENOID_ALL_ON:
			turn_all_on();
			break;
		case SOLENOID_MULTIPLE_OFF:
			if (final) {
				message_bytes[MESSAGE_COUNT-1] = incoming;
				set_solenoids_off();
			}
			else {
				message_bytes[MESSAGE_COUNT-1] = incoming;
			}
			break;
		case SOLENOID_SINGLE_OFF:
			set_single_off(incoming);
			break;
		case SOLENOID_ALL_OFF:
			turn_all_off();
			break;
		case STEPPER_MOVE:
			if (final) {
				stepper_move( ( ( (int) message_bytes[0] ) << 8 ) + incoming - step_position );
			}
			else {
				message_bytes[0] = incoming;
			}
			break;
		case STEPPER_MODE:
			if (incoming == 0x01) {
				STEPPER_MODE_FLAG = ALWAYS_ENABLED;
			}
			if (incoming == 0x02) {
				STEPPER_MODE_FLAG = ENABLED_WHILE_MOVING;
			}
			break;
		default:
			break;
	}
}

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
				if (MESSAGE_COUNT < LENGTH) {
					process_message(INCOMING, FRAME_ID, 0);
					CHECKSUM_VALUE += INCOMING;
				}	
				if (MESSAGE_COUNT == LENGTH) {
					process_message(INCOMING, FRAME_ID, 1);
				}
				else {
					process_checksum(INCOMING, CHECKSUM_VALUE);
				}
				MESSAGE_COUNT++;
				break;
		}
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
