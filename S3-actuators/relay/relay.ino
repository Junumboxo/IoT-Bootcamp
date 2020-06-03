#include "relay.h"

void setup() {
  Serial.begin(9600);
  setupRelay();
}

void loop() {
  //  setValueRelay(RELAY_ON);
  //  Serial.println("Relay is turned on");
  //  delay(2000);
  //
  //  setValueRelay(RELAY_OFF);
  //  Serial.println("Relay is turned off");
  //  delay(2000);
  if (Serial.available()) {
    Serial.println("Hello");
    char cmd = Serial.read();
    switch (cmd) {
      case 'q':
        setValueRelay(RELAY_ON);
        Serial.println("Relay is turned on");
        break;
      case 'a':
        setValueRelay(RELAY_OFF);
        Serial.println("Relay is turned off");
        break;
    }
  }
}
