char state = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  if(Serial.available()>0)
  {
    state = Serial.read();
    Serial.println("*P");
   Serial.print("You Pressed ");
   Serial.println(state);
   Serial.print("*");
  }
}
