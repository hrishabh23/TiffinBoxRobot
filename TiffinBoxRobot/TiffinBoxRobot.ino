#include <AFMotor.h>

int input = 0;
int mSpeed = 255;
char btInput[5];

AF_DCMotor motor1(1);
AF_DCMotor motor2(4);

void setup() {
  Serial.begin(9600);
  Serial.println("Turned ON!");

  //Turn on the motors
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void loop() {

  int index = 0;
  while(Serial.available()>0) {
    input = Serial.read();
    btInput[index++] = input;
  }

  if(input=='u') {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor1.speed(mSpeed);
    motor.speed(mSpeed);
  }
  else if(input=='d') {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor1.speed(mSpeed);
    motor.speed(mSpeed);
  }
  else if(input=='l') {
    motor1.run(RELEASE);
    motor2.run(FORWARD);
    motor1.speed(mSpeed);
    motor.speed(mSpeed);
  }
  else if(input=='r') {
    motor1.run(FORWARD);
    motor2.run(RELEASE);
    motor1.speed(mSpeed);
    motor.speed(mSpeed);
  }
  else if(input=='A') {
    index=0;
    mSpeed=0;
    while(btInput[index]!='A') {
      mSpeed*=10;
      mSpeed+=btInput[index]-48;
      index++;
    }
    else {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
    }
  }
}
