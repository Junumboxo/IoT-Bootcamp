#include "control.h"
#include "Arduino.h"

int control_Hysteresis(float temperature, int controlOut) {
  if (temperature > RELAY_ON_THRESHOLD) {
    controlOut = CONTROL_ON;
    Serial.println("Relay turns on");
  }
  else if (temperature < RELAY_OFF_THRESHOLD) {
    controlOut = CONTROL_OFF;
    Serial.println("Relay turns off");
  }
  else {
    
  }
  return controlOut;
}
