#include <AFMotor.h>

int input = 0;
int mSpeed = 255;
char btInput[5];
int trigPin = 13;
int echoPin = 9;

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

    if(input=='u') {                  //moving ahead
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor1.setSpeed(mSpeed);
        motor2.setSpeed(mSpeed);
    }
    else if(input=='d') {             //moving backwards
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        motor1.setSpeed(mSpeed);
        motor2.setSpeed(mSpeed);
    }
    else if(input=='l') {             //turning left
        motor1.run(RELEASE);
        motor2.run(FORWARD);
        motor1.setSpeed(mSpeed);
        motor2.setSpeed(mSpeed);
    }
    else if(input=='r') {             //turning right
        motor1.run(FORWARD);
        motor2.run(RELEASE);
        motor1.setSpeed(mSpeed);
        motor2.setSpeed(mSpeed);
    }
    else if(input=='A') {             //speed control by slider
        index=0;
        mSpeed=0;
        while(btInput[index]!='A') {
            mSpeed*=10;
            mSpeed+=btInput[index]-48;
            index++;
        }
    }
    else if(input=='o') {             //object avoiding
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(5);
        digitalWrite(trigPin, LOW);

        long duration = pulseIn(echoPin, HIGH);
        long distance = duration/29/2;    //distance in cm
      
        if(distance<25) {
            motor1.run(FORWARD);
            motor2.run(BACKWARD);
            delayMicroseconds(500);
        }
        else {
            motor1.run(FORWARD);
            motor2.run(FORWARD);
        }
    }
    else if(input=='w') {               //wall follower
        //TODO: Code this
    }
    else {
        motor1.run(RELEASE);
        motor2.run(RELEASE);
    }
}
