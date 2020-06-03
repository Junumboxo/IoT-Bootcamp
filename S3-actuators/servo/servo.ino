#include "myservo.h"

void setup() {
  Serial.begin(9600);
  setupServo();
  setAngleServo(0);
}

const int deltaAngle = 10;
void loop() {
//  for(int i = 0; i <= 180; i++){
//    setAngleServo(i);
//    delay(20);
//  }
//  for(int i = 180; i >= 0; i--){
//    setAngleServo(i);
//    delay(20);
//  }
if (Serial.available()) {
    char cmd = Serial.read();
    int myAngle;
    switch (cmd) {
      case 'w':
        myAngle = getAngleServo();
        myAngle += deltaAngle;
        setAngleServo(myAngle);
        Serial.println("Actuator step up");
        delay(200);
        break;
      case 's':
        myAngle = getAngleServo();
        myAngle -= deltaAngle;
        setAngleServo(myAngle);
        Serial.println("Actuator step down");
        delay(200);
        break;
    }
  }
}
