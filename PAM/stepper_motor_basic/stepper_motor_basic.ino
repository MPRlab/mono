int StepPin = 7;
//int Dir = 8;
int StepDelay = 400;
int pause = 125;

void setup() {
  pinMode(StepPin, OUTPUT);
  digitalWrite(StepPin, LOW);
  Serial.begin(115200);
  //pinMode(Dir, OUTPUT);
  //digitalWrite(Dir, LOW);
}

void loop() {
  /*for (int i = 0; i < 50; i++) {
    PORTB |= _BV(PB7);
    PORTB &= ~_BV(PB7);
    }
  delay(125);
*/
  int initial = 0;
  int final = 0;
  initial = millis();
  for(int i = 0; i < 50; i++)
  {
    digitalWrite(StepPin, HIGH);
    delayMicroseconds(StepDelay);
    digitalWrite(StepPin, LOW);
    delayMicroseconds(StepDelay);
  }
  final = millis();
  Serial.print("Time for digitalWrite(): ");
  Serial.print(final-initial);
  Serial.println("");
  delay(pause);
  initial = millis();
  for(int i = 0; i < 50; i++)
  {
    PORTD |= _BV(PD7);
    delayMicroseconds(StepDelay);
    PORTD &= ~_BV(PD7);
    delayMicroseconds(StepDelay);
  }
  final = millis();
  Serial.print("Time for true c command: ");
  Serial.print(final-initial);
  Serial.println("");
  delay(pause);
  //while(1);
} 

 
