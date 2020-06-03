#ifndef RELAY_H_
#define RELAY_H_

#define RELAY_MIN 0
#define RELAY_MAX 1
#define RELAY_OFF 0
#define RELAY_ON 1
#define RELAY_PIN 7

void setupRelay();
void setValueRelay(int value);
int getValueRelay(void);

#endif
