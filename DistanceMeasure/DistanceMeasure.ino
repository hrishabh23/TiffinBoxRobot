int trig = 11;
int echo = 10;
int state = 0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0)
  {
    state = Serial.read();
    if(state=='R')
    {
      digitalWrite(trig, LOW);
      delayMicroseconds(2);
      digitalWrite(trig, HIGH);
      delayMicroseconds(5);
      digitalWrite(trig, LOW);

      long duration = pulseIn(echo, HIGH);
      Serial.print("*P");
      Serial.print("The Distance is ");
      Serial.print(duration/29/2);
      Serial.print("cm.");
      Serial.print("*");
    }
  }
}
