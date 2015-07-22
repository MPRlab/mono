// Arduino timer CTC interrupt example
// www.engblaze.com
 
// avr-libc library includes
#include <avr/io.h>
#include <avr/interrupt.h>
#include <MIDI.h>

int MappingBase = 70; 
int drumMapping[] = {27, 25, 28, 29, 26, 24, 52, 53};
int Perc_channel = 2;
volatile int armGo = 0;
int onTimeMin = 470;
int drumOn = 0; 
 
void setup()
{
    for(int i = 0; i < 8; i++) {
     pinMode(drumMapping[i], OUTPUT);
     digitalWrite(drumMapping[i], LOW);
    } 
    MIDI.begin(2);
    MIDI.setHandleNoteOn(handle_NoteOn);
             
    // initialize Timer1
    cli();          // disable global interrupts
    TCCR1A = 0;     // set entire TCCR1A register to 0
    TCCR1B = 0;     // same for TCCR1B
    TCNT1 = 0; //initialize counter value to 0 
    // set compare match register to desired timer count:
    OCR1A = onTimeMin; //(stepTime * 10^-6)/6.25e-8;
    // turn on CTC mode:
    TCCR1B |= (1 << WGM12);
    TCCR1B |= (1 << CS10);
    TCCR1B |= (1 << CS12); // Set CS10 and CS12 bits for 1024 prescaler
    //TCCR1B |= (1 << CS11);
    // enable timer compare interrupt:
    TIMSK1 |= (1 << OCIE1A);
    // enable global interrupts:
    sei();
    

}

 
void handle_NoteOn (byte channel, byte note, byte velocity) {
  drumOn = note - MappingBase;
  if (drumOn >= 0 && drumOn < 8  && velocity > 0) {
    OCR1A = (((velocity  * (730-onTimeMin)) / 127) + onTimeMin);
    TCNT1 = 0;
    armGo = 1;  
    digitalWrite(drumMapping[drumOn], HIGH);
  }
}

 
ISR(TIMER1_COMPA_vect)
{
  if (armGo == 1) {
    digitalWrite(drumMapping[drumOn], LOW);
    armGo = 0;
  }
  if (armGo == 0) {
  }
}


void loop() 
{ 
  MIDI.read();
}

