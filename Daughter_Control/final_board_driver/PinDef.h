/*
	Copyright Paulo Cavahlo 2015
			  Nathan Hughes 2015

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

#ifndef PinDef_H
#define PinDef_H

/* Stepper Motor Related Pins */
#define STEP_EN1 13
#define STEP_EN2 5
#define STEP_EN3 2
#define STEP_EN4 3
#define STEP_IN1 A7
#define STEP_IN2 A6
#define STEP_IN3 A5
#define STEP_IN4 A4
#define STEP_NRES A3
#define STEP_NSLEEP A2
#define STEP_NFAULT A1

/* Solenoid Driver Related */
#define DRV1 36,37,40,41 // IN1, IN2, IN3, IN4
#define DRV2 32,33,34,35
#define DRV3 14,15,30,31
#define DRV4 27,28,29,39
#define DRV5 23,24,25,26
#define DRV6 A13,A14,A15,22
#define DRVS A12
#define DRV_FAULT 49,48,47,46,45,44,A11 // DRV1,...,DRV6,DRVS
#define DRV_ENBL 12,11,10,9,8,7,6 // DRV1,...,DRV6,DRVS
#define NUM_SOLENOIDS 25

/* Other Pins */
#define LED_OK 42

/* Device Address Number */
#define DEV_ADDR 1

/* Frame ID identifiers */
#define SOLENOID_ENABLE 0x10
#define SOLENOID_MULTIPLE_ON 0x20
#define SOLENOID_SINGLE_ON 0x21
#define SOLENOID_ALL_ON 0x2F
#define SOLENOID_MULTIPLE_OFF 0x30
#define SOLENOID_SINGLE_OFF 0x31
#define SOLENOID_ALL_OFF 0x3F
#define STEPPER_MOVE 0x40
#define STEPPER_MODE 0x41

/* Stepper Mode identifiers */
#define ALWAYS_ENABLED 0x00
#define ENABLED_WHILE_MOVING 0x01

/* Stepper Motor Speed */
#define STEPPER_DELAY 10

/* Status Messages */
#define ACKNOWLEDGEMENT 0xFD
#define CHECKSUM_ERROR 0x00
// more statuses go here

#endif