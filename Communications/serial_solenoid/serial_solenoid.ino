char serialvalue;
unsigned long off_time;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(8 , OUTPUT);
  off_time = millis();
}

void loop() {
  if (Serial.available() >= 2) {
    int x = Serial.available();
    char buff[100];
    Serial.readBytes(buff, x);
    for (int i = 0; i < x ; i += 2) {
      //buff[i] od volume, buff[i+1] is note number

      if (buff[i] == 0) {
        //solenoid off
        if (buff[i + 1] == 60) {
          analogWrite(13, LOW);
        }
        else {
          analogWrite(8, LOW);
        }
      }
      else {
        //solenoid on
        int power = map(buff[i], 1, 127, 120, 255);

        Serial.print("note power: ");
        Serial.print(power);
        if (buff[i + 1] == 60) {
          analogWrite(13, power);
        }
        else {
          analogWrite(8, power);
        }

      }
    }
  }
}


