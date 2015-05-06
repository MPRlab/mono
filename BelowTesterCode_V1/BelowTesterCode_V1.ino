/*
*	Tests the below. Steps n times and then releases repeatedly
*	By Paulo Carvalho
*/

/* Declare Pins */
#define DRV1_PWR 11
#define DRV1_EN 10
#define DRV1_DIR 9
#define DRV1_STEP 8
#define DRV2_PWR 7
#define DRV2_EN 6
#define DRV2_DIR 5
#define DRV2_STEP 4

#define NUM_STEP 600
#define STEP_DELAY 1
#define RECOIL_DELAY 500

void setup(){
	pinMode(DRV1_PWR, OUTPUT);
	pinMode(DRV1_STEP, OUTPUT);
	pinMode(DRV1_EN, OUTPUT);
	pinMode(DRV1_DIR, OUTPUT);
	pinMode(DRV2_PWR, OUTPUT);
	pinMode(DRV2_STEP, OUTPUT);
	pinMode(DRV2_EN, OUTPUT);
	pinMode(DRV2_DIR, OUTPUT);

	// Provide Power to Driver Logic
	digitalWrite(DRV1_PWR, HIGH);
	digitalWrite(DRV2_PWR, HIGH);
}

void loop(){

	// DRIVER 1
	digitalWrite(DRV1_EN, HIGH); // TURN ON Stepper

	for (int i=0; i <NUM_STEP; i++){
		digitalWrite(DRV1_STEP, LOW);
		delay(STEP_DELAY);
		digitalWrite(DRV1_STEP, HIGH);
		delayMicroseconds(10);
	}

	digitalWrite(DRV1_EN, LOW); // TURN OFF Stepper

	// DRIVER 2
	digitalWrite(DRV2_EN, HIGH); // TURN ON Stepper
	
	for (int i=0; i <NUM_STEP; i++){
		digitalWrite(DRV2_STEP, LOW);
		delay(STEP_DELAY);
		digitalWrite(DRV2_STEP, HIGH);
		delayMicroseconds(10);
	}

	digitalWrite(DRV2_EN, LOW); // TURN OFF Stepper

}
