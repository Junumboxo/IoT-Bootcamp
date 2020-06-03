#include "dc.h"
#include "Arduino.h"

int motorCurrentPower;

void setupMotor() {
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(EN_PIN, OUTPUT);
}

void setPowerMotor(int power) {
  int direction = 0;
  if (power > 0) {
    direction = MOTOR_DIR_FWD;
  }
  else if (power < 0) {
    direction = MOTOR_DIR_BWD;
  }
  power *= direction;
  if (power > MOTOR_POWER_MAX) {
    power = MOTOR_POWER_MAX;
  }
  else if (power < MOTOR_POWER_MIN) {
    power = MOTOR_POWER_MIN;
  }
  int pwmPower = map(power, MOTOR_POWER_MIN, MOTOR_POWER_MAX, MOTOR_PWM_MIN, MOTOR_PWM_MAX);
  if (direction == MOTOR_DIR_FWD) {
    digitalWrite(IN1_PIN, HIGH);
    digitalWrite(IN2_PIN, LOW);
  }
  else if (direction == MOTOR_DIR_BWD) {
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, HIGH);
  }
  else if (direction == 0) {
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, LOW);
  }
  analogWrite(EN_PIN, power);
  motorCurrentPower = power;
}

int getPowerMotor(void){
  return motorCurrentPower;
}
