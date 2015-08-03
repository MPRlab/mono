/*
* Test Code V1 for the Multi Solenoid Driver Board V1
* Tests all onboard peripherals
* Pin Definition File
* By Paulo, Jan 16, 2015
* Modified by Nathan to incorporate AVR-c library
*/

#ifndef __PINDEF_H__
#define __PINDEF_H__

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
/* Other Pins */
#define LED_OK 42

#endif
// __PINDEF_H__