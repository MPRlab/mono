// written by Scott Barton May 29,30 2013

#include <MIDI.h>

int MappingBase = 70; 
int drum1 = 27;
int drum2 = 25;
int drum3 = 28;
int drum4 = 29;
int drum5 = 26;
int drum6 = 24;
int drum7 = 52;
int drum8 = 53;
int LED1 = 48;
int LED2 = 46;

int drumMapping[] = {27, 25, 28, 29, 26, 24, 52, 53};
int Perc_channel = 2;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize MIDI and the digital pins as outputs.
  pinMode(drum1, OUTPUT);     
  pinMode(drum2, OUTPUT);     
  pinMode(drum3, OUTPUT);     
  pinMode(drum4, OUTPUT);     
  pinMode(drum5, OUTPUT);     
  pinMode(drum6, OUTPUT);     
  pinMode(drum7, OUTPUT);     
  pinMode(drum8, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(drum1, LOW);
  digitalWrite(drum2, LOW);
  digitalWrite(drum3, LOW);
  digitalWrite(drum4, LOW);
  digitalWrite(drum5, LOW);
  digitalWrite(drum6, LOW);
  digitalWrite(drum7, LOW);
  digitalWrite(drum8, LOW);
  MIDI.begin(Perc_channel);
  MIDI.setHandleNoteOn(handle_NoteOn);
  MIDI.setHandleNoteOff(handle_NoteOff);
}

void handle_NoteOn (byte channel, byte note, byte velocity) {
    digitalWrite(48, HIGH);
    int drumOn = note - MappingBase;
    if (drumOn >= 0 && drumOn < 8  && velocity > 0) {
      digitalWrite(drumMapping[drumOn], HIGH);
    }
    if (velocity == 0) {
      digitalWrite(drumMapping[drumOn], LOW);
    }
      digitalWrite(48, LOW);  
}

void handle_NoteOff (byte channel, byte note, byte velocity) {
  int drumOff = note - MappingBase;
  digitalWrite(drumMapping[drumOff], LOW);
  digitalWrite(48, LOW);
}

void loop() {
  MIDI.read();
}
