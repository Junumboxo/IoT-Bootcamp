#include <timer-api.h>
#include <timer_setup.h>

#include "relay.h"
#include "TMP36.h"
#include "control.h"
#include "automate.h"

float currentTemp;
int relayState;
int controlOut;
int automateOut;


void setup() {
  Serial.begin(9600);
  setupTMP36();
  setupRelay();
  timer_init_ISR_1KHz(TIMER_DEFAULT);
}

#define SECOND 1000
#define TIMEOUT_ON (10*SECOND)
#define TIMEOUT_OFF (5*SECOND)
volatile unsigned long TimeOutOn = TIMEOUT_ON;
volatile unsigned long TimeOutOff = TIMEOUT_OFF;
int TimeOutOnFlag = 0;
int TimeOutOffFlag = 0;

void timer_handle_interrupts(int timer){

  //if time has not run out yet, decrement it
  if (TimeOutOn > 0) TimeOutOn--;
  if (TimeOutOff > 0) TimeOutOff--;

  //if time has run out, put a flag
  TimeOutOnFlag = (TimeOutOn == 0) ? 1 : 0;
  TimeOutOffFlag = (TimeOutOff == 0) ? 1 : 0;

  //if FSM enters one of these states, initialize the timer
  if (automateOut == READY) {
    TimeOutOn = TIMEOUT_ON;
  }
  if (automateOut == PERMIT) {
    TimeOutOff = TIMEOUT_OFF;
  }
  
}

void loop() {
  // 1. Get the Temperature
  currentTemp = getTemperature();

  // 2. Check if we ought to turn on the relay by the conditions of environment
  controlOut = control_Hysteresis(currentTemp, controlOut);

  // but first we have to check if our automation model permits us to do this
  automateOut = automateUpdate(controlOut, TimeOutOnFlag, TimeOutOffFlag);

  //and if yes now we can change the state of relay
  if (automateOut == PERMIT) {
    setValueRelay(RELAY_ON);
  }
  else {
    setValueRelay(RELAY_OFF);
  }

  Serial.println("Temperature: ");
  Serial.println(currentTemp);
  Serial.println("Current state of relay: ");
  Serial.println(getValueRelay());
  int input = automateGetNewState(controlOut, TimeOutOnFlag, TimeOutOffFlag);
  Serial.print("FSM current state: ");
  Serial.println(myStates[automateOut].OutName);
  Serial.print("FSM next state: ");
  int nextState = myStates[automateOut].Next[input];
  Serial.println(myStates[nextState].OutName);
  Serial.println();
  delay(1000);

}
