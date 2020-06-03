#ifndef MYSERVO_H_
#define MYSERVO_H_

#define SERVO_MIN 30
#define SERVO_MAX 135
#define SERVO_PIN 9


void setupServo();
void setAngleServo(int value);
int getAngleServo(void);

#endif
