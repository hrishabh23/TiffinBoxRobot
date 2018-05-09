int sensor = 12;
int state = 0;

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
 if(Serial.available()>0)
 {
    state = Serial.read();
 }
long duration = pulseIn(sensor, HIGH);

 if(state=='R')
 {
  
  long rpm = 1000000/duration;
  Serial.print("*P");
  Serial.print("RPM is ");
  Serial.print(rpm);
  Serial.print("*");
 }

}
