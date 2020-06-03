#include "myservo.h"
#include "Servo.h"

int servoCurrentAngle;
Servo myservo;

void setupServo(){
  myservo.attach(SERVO_PIN);
}

void setAngleServo(int value){
  if (value > SERVO_MAX) {
    value = SERVO_MAX;
  }
  else if (value < SERVO_MIN) {
    value = SERVO_MIN;
  }

  myservo.write(value);
  servoCurrentAngle = value;
}

int getAngleServo(void){
  return servoCurrentAngle;
}
