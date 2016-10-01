
int pitch = 0; // incoming serial byte
int vel = 0; // incoming serial byte
int solenoid = 13;

void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600); // open the arduino serial port
  pinMode(solenoid, OUTPUT);   // pin connected to solenoid
}

void readSerial() {
  while(Serial.available() == 0); //loop until there is serial data in the buffer
    pitch = Serial.read(); // get incoming byte
  while(Serial.available() == 0); //loop until there is serial data in the buffer
    vel = Serial.read(); // get next byte
    solenoidOnOff(pitch, vel);
    Serial.print(pitch);
    Serial.print(" ");
    Serial.println(vel);
}

void solenoidOnOff(int pitch, int vel) {
  if (vel > 0) {
    digitalWrite(solenoid, HIGH);
    delay(50);
    digitalWrite(solenoid, LOW);
  }
}

void loop() {
readSerial();  
}



