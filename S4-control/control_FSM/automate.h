#ifndef AUTOMATE_H_
#define AUTOMATE_H_

#define READY 0
#define PERMIT 1
#define DENY 2

typedef struct {
  unsigned int Out;
  char OutName[10];
  unsigned int Time;
  unsigned int Next[8];
} State;

extern State myStates[3];

int automateGetNewState(int controlOut, int TimeOutOnFlag, int TimeOutOffFlag);
int automateUpdate(int controlOut, int TimeOutOnFlag, int TimeOutOffFlag);

#endif
