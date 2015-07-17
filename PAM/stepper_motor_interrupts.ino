// Arduino timer CTC interrupt example
// www.engblaze.com
 
// avr-libc library includes
#include <avr/io.h>
#include <avr/interrupt.h>
 
int StepPin = 7;
int StepDir = 8;
volatile int pickerMode = 0;
int pickDelay = 100;
volatile int StepNum = 0;

 
void setup()
{
    pinMode(StepPin, OUTPUT);
    pinMode(StepDir, OUTPUT);
    digitalWrite(StepDir, HIGH);
 
    // initialize Timer1
    cli();          // disable global interrupts
    TCCR1A = 0;     // set entire TCCR1A register to 0
    TCCR1B = 0;     // same for TCCR1B
    TCNT1 = 0; //initialize counter value to 0 
    // set compare match register to desired timer count:
    OCR1A = 2000; //(stepTime * 10^-6)/6.25e-8;
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
 
 
ISR(TIMER1_COMPA_vect)
{
  if (pickerMode == 1) {
    TCNT1 = 0;
    digitalWrite(StepPin, !digitalRead(StepPin));
    StepNum++;
    if (StepNum == 200) {
      pickerMode = 0;
      StepNum = 0;
    }
  }
  if (pickerMode == 0) {
  }
}

void loop() 
{ 
  pickerMode = 1;
  delay(10000);
}

