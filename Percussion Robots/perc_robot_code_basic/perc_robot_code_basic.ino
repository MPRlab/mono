int drumMapping[] = {27, 25, 28, 29, 26, 24, 52, 53};
 
void setup()
{
    for(int i = 0; i < 8; i++) {
     pinMode(drumMapping[i], OUTPUT);
     digitalWrite(drumMapping[i], LOW);
    } 

}
 
void loop() 
{ 
  for(int i = 0; i<8; i++){
    digitalWrite(drumMapping[i], HIGH);
    delay(50);
    digitalWrite(drumMapping[i], LOW);
    delay(500);  
  }
  while(1);
}

