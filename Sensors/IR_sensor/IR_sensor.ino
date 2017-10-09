int x;
void setup() {
 Serial.begin(38400);

}

void loop() {
  x = analogRead(1);
  Serial.println(x);  
}
