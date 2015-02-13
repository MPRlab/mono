void setup() {
    Serial.begin(9600);
}

void drumGo() {
  if (Serial.available() > 0) {
    byte inByte1 = Serial.read();
      digitalWrite(inByte1, HIGH);
      delay(107);
      digitalWrite(inByte1, LOW);
  }
}

void loop() { 
  drumGo();
}
