//
//  PAM.h
//  
//
//  Created by Rayce Stipanovich on 3/21/13.
//
//

#ifndef ____PAM__
#define ____PAM__

#include <Arduino.h>
#include <MIDI.h>

typedef enum {
	basicMode,
	advanceMode,
} PlaybackMode;

void debug_led();
void blink();
void dampOn();
void dampOff();
void pluck();
void handlePluck();
void updateOutput();
void KillAllTangents();
void triggerSolenoid(short int ProcessedNote);
void killSolenoid(short int ProcessedNote);
void autoPluck();


#endif /* defined(____PAM__) */
