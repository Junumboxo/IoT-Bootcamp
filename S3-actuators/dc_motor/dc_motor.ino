#include "dc.h"
#define DELTA 20

void setup() {
  Serial.begin(9600);
  setupMotor();
  setPowerMotor(0);
  Serial.println("DC Motor a fost configurat");
  Serial.println("Tasta F pentru -- rotire  motorul inainte.");
  Serial.println(" Tasta D pentru -- rotire inapoi");
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();
    int power;
    switch (cmd) {
      case 'f':
        power = getPowerMotor();
        power += DELTA;
        setPowerMotor(power);
        power = getPowerMotor();
        Serial.print("Step up for motor, now it is ");
        Serial.println(power);
        break;
      case 'b':
        power = getPowerMotor();
        power -= DELTA;
        setPowerMotor(power);
        power = getPowerMotor();
        Serial.print("Step down for motor, now it is ");
        Serial.println(power);
        break;
    }
  }
}
