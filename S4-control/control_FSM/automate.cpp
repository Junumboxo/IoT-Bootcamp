#include "automate.h"
#include "Arduino.h"

State myStates[3] = {
  {0, "READY", 10, {READY, READY, READY, READY, PERMIT, PERMIT, PERMIT, PERMIT}},
  {1, "PERMIT", 10, {DENY, DENY, DENY, DENY, PERMIT, PERMIT, DENY, DENY}},
  {2, "DENY", 10, {DENY, READY, DENY, READY, DENY, READY, DENY, READY}}
};

int FSM_state = READY;


int automateGetNewState(int controlOut, int TimeOutOnFlag, int TimeOutOffFlag) {
  int newState;
  if (controlOut == 0 && TimeOutOnFlag == 0 && TimeOutOffFlag == 0) {
    newState = 0;
  }
  else if (controlOut == 0 && TimeOutOnFlag == 0 && TimeOutOffFlag == 1) {
    newState = 1;
  }
  else if (controlOut == 0 && TimeOutOnFlag == 1 && TimeOutOffFlag == 0) {
    newState = 2;
  }
  else if (controlOut == 0 && TimeOutOnFlag == 1 && TimeOutOffFlag == 1) {
    newState = 3;
  }
  else if (controlOut == 1 && TimeOutOnFlag == 0 && TimeOutOffFlag == 0) {
    newState = 4;
  }
  else if (controlOut == 1 && TimeOutOnFlag == 0 && TimeOutOffFlag == 1) {
    newState = 5;
  }
  else if (controlOut == 1 && TimeOutOnFlag == 1 && TimeOutOffFlag == 0) {
    newState = 6;
  }
  else if (controlOut == 1 && TimeOutOnFlag == 1 && TimeOutOffFlag == 1) {
    newState = 7;
  }
  return newState;
}

int automateUpdate(int controlOut, int TimeOutOnFlag, int TimeOutOffFlag) {
  // 1. We calculate output depending ONLY on our current state - Moore model
  int output = myStates[FSM_state].Out;
  // 2. Wait for the time corresponding to the state
  delay(myStates[FSM_state].Time*10);
  // 3. We calculate the new state depending on controlOut, TimeOutOnFlag, TimeOutOffFlag
  int newStateOrder = automateGetNewState(controlOut, TimeOutOnFlag, TimeOutOffFlag);
  // 4. We replace the current state with the new state, and in the next iteration it will be our current state
  FSM_state = myStates[FSM_state].Next[newStateOrder];
  return output;
}
