/*
*	Tests the below. Steps n times and then releases repeatedly
*	By Paulo Carvalho
*/

#define STEP 10
#define EN 8

#define NUM_STEP 1300
#define STEP_DELAY 1
#define RECOIL_DELAY 3000

void setup(){
	pinMode(STEP, OUTPUT);
	pinMode(EN, OUTPUT);
}

void loop(){
	digitalWrite(EN, LOW); // Turn OFF Stepper
	delay(RECOIL_DELAY);
	digitalWrite(EN, HIGH); // TURN ON Stepper

	for (int i=0; i <NUM_STEP; i++){
		digitalWrite(STEP, LOW);
		delay(STEP_DELAY);
		digitalWrite(STEP, HIGH);
		delayMicroseconds(100);
	}
}
