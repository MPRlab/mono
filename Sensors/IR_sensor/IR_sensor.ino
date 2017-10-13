<<<<<<< HEAD
int x;
void setup() {
 Serial.begin(38400);
=======
int distance;

void setup() {
  Serial.begin(9600);
>>>>>>> origin/master

}

void loop() {
<<<<<<< Updated upstream
<<<<<<< HEAD
  x = analogRead(1);
  Serial.println(x);  
=======
  distance = analogRead(1);
  Serial.println(distance);
>>>>>>> origin/master
=======
  for (int i=0; i<100; i++) {
    Serial.println(i);
    delay(1000);
  }
>>>>>>> Stashed changes
}
