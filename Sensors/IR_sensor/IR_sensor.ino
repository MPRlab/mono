int distance;

void setup() {
  Serial.begin(9600);

}

void loop() {
  distance = analogRead(1);
  Serial.println(distance);
}
