//
//  PAM.cpp
//  
//
//  Created by Rayce Stipanovich on 3/21/13.
//
//

#include "PAM.h"
#include <MIDI.h>

const int latchPin = 4;
const int clockPin = 3;
const int dataPin = 2;
const int debugPin = 14;
byte debug_state = 0;
long int debug_led_time = 0;

//software defines
PlaybackMode globalMode = basicMode;

#define TAN_START 1
#define TAN_END 16
#define PICK_PIN1 17
#define PICK_PIN2 18
#define DAMP_SOL 19
#define BLINK_TIME 500
#define pluck_sol_hold_duration 700
#define MAX_PLUCK_SPEED 30
#define EXTRA_SOL 24

long int debug_blink_time = 0;
bool debug_blink_state = false;
bool pluck_direction = false;
long int pluck_kill_timer = 0;

bool SOLENOID_STATES[24];
bool _prev_SOLENOID_STATES[24];

int TANGENT_PITCH_MAP[36];

bool super_pluck = false;
int Pluck_rate = MAX_PLUCK_SPEED + 2*127;
bool is_plucking = false;
long int last_pluck = 0;

bool basic_auto_pluck = false;

#define C4	0
#define Db4 1
#define D4	2
#define Eb4 3
#define E4	4
#define F4	5
#define Gb4	6
#define G4	7
#define Ab4 8
#define A4	9
#define Bb4 10
#define B4	11
#define C5	12
#define Db5 13
#define D5	14
#define Eb5 15
#define E5	16
#define F5	17
#define Gb5	18
#define G5	19
#define Ab5 20
#define A5	21
#define Bb5 22
#define B5	23
#define C6	24
#define Db6 25
#define D6	26
#define Eb6 27
#define E6	28
#define F6	29
#define Gb6	30
#define G6	31
#define Ab6 32
#define A6	33
#define Bb6 34
#define B6	35

void debug_led() {
	if (globalMode==basicMode) {
		if (debug_led_time <= millis()) {
			if (debug_state == 0) {
				debug_led_time = millis() + 30;
				if (!debug_blink_state) digitalWrite(debugPin, HIGH);
				debug_state = 1;
			} else if (debug_state == 1) {
				debug_led_time = millis() + 70;
				if (!debug_blink_state) digitalWrite(debugPin, LOW);
				debug_state = 2;
			} else if (debug_state == 2) {
				debug_led_time = millis() + 30;
				if (!debug_blink_state) digitalWrite(debugPin, HIGH);
				debug_state = 3;
			} else if (debug_state == 3) {
				debug_led_time = millis() + 510;
				if (!debug_blink_state) digitalWrite(debugPin, LOW);
				debug_state = 0;
			}
		}
	} else {
		if (debug_led_time <= millis()) {
			if (debug_state == 0) {
				debug_led_time = millis() + 50;
				if (!debug_blink_state) digitalWrite(debugPin, HIGH);
				debug_state = 1;
			} else if (debug_state == 1) {
				debug_led_time = millis() + 50;
				if (!debug_blink_state) digitalWrite(debugPin, LOW);
				debug_state = 2;
			} else if (debug_state == 2) {
				debug_led_time = millis() + 50;
				if (!debug_blink_state) digitalWrite(debugPin, HIGH);
				debug_state = 3;
			} else if (debug_state == 3) {
				debug_led_time = millis() + 50;
				if (!debug_blink_state) digitalWrite(debugPin, LOW);
				debug_state = 0;
			}
		}
	}

	if (debug_blink_state) {
		if (millis() >= debug_blink_time) {
			debug_blink_state = false;
			digitalWrite(debugPin, LOW);
		}
	}
}

void KillAllTangents() {
	int i;
	for (i=TAN_START; i<TAN_END; i++) {
		SOLENOID_STATES[ i - 1 ] = false;
	}
}

void triggerSolenoid(short int ProcessedNote) {
	byte solenoidNumber = TANGENT_PITCH_MAP[ ProcessedNote ];
	SOLENOID_STATES[solenoidNumber - 1] = true;
}

void killSolenoid(short int ProcessedNote) {
	byte solenoidNumber = TANGENT_PITCH_MAP[ ProcessedNote ];
	SOLENOID_STATES[solenoidNumber - 1] = false;
}

void _handler_MIDI_Note_On(byte channel, byte note, byte velocity) {
	blink();
	if (globalMode == basicMode) {
		if (note != 72) KillAllTangents();
		note = note - 72;
		triggerSolenoid(constrain(note, G4, G4 + 16));
		if (basic_auto_pluck) pluck();
		else if (note == 0) pluck();
	} else {
		//individual plucking
		if (note == 72) {
			if (super_pluck) {
				last_pluck = millis() + Pluck_rate;
				is_plucking = true;
			}
			pluck();
		} else {
			//individual solenoid control
			note = note - 72;
			note = constrain(note, G4, G4 + 16);
			triggerSolenoid(note);
		}
	}
}


//timer based auto plucking
void autoPluck() {
	if (super_pluck && globalMode==advanceMode && is_plucking){
		if (millis() >= last_pluck) {
			last_pluck = millis() + Pluck_rate;
			pluck();
		}
	}
}

void _handler_MIDI_Note_Off(byte channel, byte note, byte velocity) {
	blink();

	if (note == 72) {
		is_plucking = false;
		//if (super_pluck && globalMode == advanceMode) pluck();
	} else {
		note = note - 72;
		note = constrain(note, G4, G4 + 16);
		killSolenoid(note);
	}
}

void _handler_MIDI_Control_Change(byte channel, byte number, byte value) {
	blink();
	if (number == 39) {
		if (value >= 64) {
			globalMode = advanceMode;
		} else {
			globalMode = basicMode;
			if (is_plucking){
				is_plucking = false;
				pluck();
			}
		}
	}

	if (number == 36) {
		if (value >= 64) {
			dampOn();
		} else {
			dampOff();
		}
	}

	if (number == 37) {
		if (value >= 64) {
			basic_auto_pluck = true;
		} else {
			basic_auto_pluck = false;
		}
	}

	if (number == 1) { //mod weel advanced mode plucking
		if (value > 0 && globalMode == advanceMode ) super_pluck = true;
		else super_pluck = false;
		Pluck_rate = ((127-value)*4) + MAX_PLUCK_SPEED;
	}
}

void dampOn() {
	SOLENOID_STATES[ DAMP_SOL - 1 ] = true;
}

void dampOff() {
	SOLENOID_STATES[ DAMP_SOL - 1 ] = false;
}

void pluck() {
	int i;
	for (i=0; i<50; i++) {
		digitalWrite(MOSI, HIGH);
		delayMicroseconds(1);
		digitalWrite(MOSI, LOW);
		delayMicroseconds(1);
		
	}
}

void handlePluck() {
	if (millis() >= pluck_kill_timer){
		SOLENOID_STATES[ PICK_PIN1 - 1 ] = false;
		SOLENOID_STATES[ PICK_PIN2 - 1 ] = false;
	}
}

void blink() {
	digitalWrite(debugPin, HIGH);
	debug_blink_state = true;
	debug_blink_time = millis() + BLINK_TIME;
}

void updateOutput() {
	if (memcmp(_prev_SOLENOID_STATES, SOLENOID_STATES, sizeof(SOLENOID_STATES))!=0) {
		memcpy(_prev_SOLENOID_STATES, SOLENOID_STATES, sizeof(SOLENOID_STATES));
		
		byte temp_byte = 0;
		if (SOLENOID_STATES[0]) temp_byte += 0x01;
		if (SOLENOID_STATES[1]) temp_byte += 0x02;
		if (SOLENOID_STATES[2]) temp_byte += 0x04;
		if (SOLENOID_STATES[3]) temp_byte += 0x08;
		if (SOLENOID_STATES[4]) temp_byte += 0x10;
		if (SOLENOID_STATES[5]) temp_byte += 0x20;
		if (SOLENOID_STATES[6]) temp_byte += 0x40;
		if (SOLENOID_STATES[7]) temp_byte += 0x80;

		byte temp_byte2 = 0;
		if (SOLENOID_STATES[8])  temp_byte2 += 0x01;
		if (SOLENOID_STATES[9])  temp_byte2 += 0x02;
		if (SOLENOID_STATES[10]) temp_byte2 += 0x04;
		if (SOLENOID_STATES[11]) temp_byte2 += 0x08;
		if (SOLENOID_STATES[12]) temp_byte2 += 0x10;
		if (SOLENOID_STATES[13]) temp_byte2 += 0x20;
		if (SOLENOID_STATES[14]) temp_byte2 += 0x40;
		if (SOLENOID_STATES[15]) temp_byte2 += 0x80;

		byte temp_byte3 = 0;
		if (SOLENOID_STATES[16]) temp_byte3 += 0x01;
		if (SOLENOID_STATES[17]) temp_byte3 += 0x02;
		if (SOLENOID_STATES[18]) temp_byte3 += 0x04;
		if (SOLENOID_STATES[19]) temp_byte3 += 0x08;
		if (SOLENOID_STATES[20]) temp_byte3 += 0x10;
		if (SOLENOID_STATES[21]) temp_byte3 += 0x20;
		if (SOLENOID_STATES[22]) temp_byte3 += 0x40;
		if (SOLENOID_STATES[23]) temp_byte3 += 0x80;

		digitalWrite(latchPin, LOW);
		shiftOut(dataPin, clockPin, MSBFIRST, temp_byte3);
		shiftOut(dataPin, clockPin, LSBFIRST, temp_byte2);
		shiftOut(dataPin, clockPin, MSBFIRST, temp_byte);
		digitalWrite(latchPin, HIGH);
	}
}

void setup() {

	// [MIDI_PITCH] = SOLENOID NUMBER
	TANGENT_PITCH_MAP[G4] = EXTRA_SOL;//reserved for open
	TANGENT_PITCH_MAP[Ab4] = 16;
	TANGENT_PITCH_MAP[A4] = 15;
	TANGENT_PITCH_MAP[Bb4] = 14;
	TANGENT_PITCH_MAP[B4] = 13;
	TANGENT_PITCH_MAP[C5] = 12;
	TANGENT_PITCH_MAP[Db5] = 11;
	TANGENT_PITCH_MAP[D5] = 10;
	TANGENT_PITCH_MAP[Eb5] = 9;
	TANGENT_PITCH_MAP[E5] = 8;
	TANGENT_PITCH_MAP[F5] = 7;
	TANGENT_PITCH_MAP[Gb5] = 6;
	TANGENT_PITCH_MAP[G5] = 5;
	TANGENT_PITCH_MAP[Ab5] = 4;
	TANGENT_PITCH_MAP[A5] = 3;
	TANGENT_PITCH_MAP[Bb5] = 2;
	TANGENT_PITCH_MAP[B5] = 1;
	
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin,  OUTPUT);
	pinMode(debugPin, OUTPUT);
	pinMode(MOSI, OUTPUT);

	digitalWrite(MOSI, LOW);

	//handle initialization of shift registers
	digitalWrite(latchPin, LOW);
	delay(1);
	shiftOut(dataPin, clockPin, MSBFIRST, 0);
	shiftOut(dataPin, clockPin, MSBFIRST, 0);
	shiftOut(dataPin, clockPin, MSBFIRST, 0);
	delay(1);
	digitalWrite(latchPin, HIGH);

	MIDI.begin(1);
	MIDI.setHandleNoteOn(_handler_MIDI_Note_On);
	MIDI.setHandleNoteOff(_handler_MIDI_Note_Off);
	MIDI.setHandleControlChange(_handler_MIDI_Control_Change);

	//fun blinky blinky
	int i;
	for (i=0; i<10; i++) {
		digitalWrite(14, HIGH);
		delay(30);
		digitalWrite(14, LOW);
		delay(30);
	}

	//startup delay for debugging
	delay(200);
}

void loop() {
	MIDI.read();
	//debug_led();
	//handlePluck();
	updateOutput();
	//autoPluck();
}
