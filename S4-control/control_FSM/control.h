#ifndef CONTROL_H_
#define CONTROL_H_

#define CONTROL_ON 1
#define CONTROL_OFF 0
#define RELAY_ON_THRESHOLD 30
#define RELAY_OFF_THRESHOLD 27

int control_Hysteresis(float temperature, int controlOut);

#endif
