
int byte1 = 0; // incoming serial byte
int initial = 0;
int final = 0;

void setup()
{
  // start serial port at 115200 bps:
  Serial.begin(115200); // open the arduino serial port
  pinMode(7, OUTPUT);   // pin connected to solenoid
  initial = millis();
}

void readSerial() {
  while(Serial.available() == 0); //loop until there is serial data in the buffer
    byte1 = Serial.read(); // get incoming byte
  final = millis();
  //Serial.print("Time for message ");
  Serial.print(final-initial);
  Serial.println("");
  initial = final;
}

void loop() {
readSerial();  
}



