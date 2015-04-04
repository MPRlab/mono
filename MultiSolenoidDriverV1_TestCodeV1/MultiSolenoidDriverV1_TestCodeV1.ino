/*
* Test Code V1 for the Multi Solenoid Driver Board V1
* Tests all onboard peripherals
* Main File
* By Paulo, Jan 16, 2015
*/

#include <PinDef.h>

/* Create Solenoid List */
int pinSolOn[] = {DRV1, DRV2, DRV3, DRV4, DRV5, DRV6, DRVS};
int pinSolEnbl[] = {DRV_ENBL}; // Active LOW
int pinSolFault[] = {DRV_FAULT}; // Fault when LOW

/* Declare Variables */
int iSolOn = -1; // Keeps track of which solenoid was last toggled
int iStep = 1; // Keeps track of the step for the stepper motor

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
		analogWrite(pinSolEnbl[i], 30);
	}

	/* Enable all Outputs of Stepper Driver */
	analogWrite(STEP_EN1, 255);
	analogWrite(STEP_EN2, 255);
	analogWrite(STEP_EN3, 255);
	analogWrite(STEP_EN4, 255);

	/* Enable Stepper Driver */
	digitalWrite(STEP_NSLEEP, HIGH);
	digitalWrite(STEP_NRES, HIGH);
}

void loop(){
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
}

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


