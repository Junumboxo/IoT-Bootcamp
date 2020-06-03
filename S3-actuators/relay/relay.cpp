#include "relay.h"
#include "Arduino.h"

int relayCurrentState;

void setupRelay(){
  pinMode(RELAY_PIN, OUTPUT);
}

void setValueRelay(int value){
  if (value < RELAY_MIN) {
    value = RELAY_MIN;
  } 
  else if (value > RELAY_MAX) {
    value = RELAY_MAX;
  }

  if (value != RELAY_OFF) {
    digitalWrite(RELAY_PIN, HIGH);
  }
  else {
    digitalWrite(RELAY_PIN, LOW);
  }
  relayCurrentState = value;
}

int getValueRelay(void){
  return relayCurrentState;
}
