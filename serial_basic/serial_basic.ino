
int pitch = 0;         // incoming serial byte
int vel = 0;
int LED = 13;

void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  pinMode(13, OUTPUT);   // digital sensor is on digital pin 2
}

void readSerial() {
  // if we get a valid byte, read input:
  if (Serial.available() > 0) {
    // get incoming byte:
    pitch = Serial.read();
    // read first analog input, divide by 4 to make the range 0-255:
    vel = Serial.read();
    digitalWrite(LED, HIGH);
    delay (100);
    digitalWrite(LED, LOW);
    Serial.print(pitch);
    Serial.println();
    Serial.print(vel);
  }
}


void loop() {
readSerial();  
}



