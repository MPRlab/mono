int distance;

void setup() {
  Serial.begin(38400);

}

void loop() {
  distance = analogRead(1);
  Serial.print(distance);
}
