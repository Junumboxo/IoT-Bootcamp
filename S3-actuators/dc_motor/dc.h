#ifndef DC_H_
#define DC_H_

#define IN1_PIN 12
#define IN2_PIN 13
#define EN_PIN 11
#define MOTOR_POWER_MIN 0
#define MOTOR_POWER_MAX 100
#define MOTOR_PWM_MIN 0
#define MOTOR_PWM_MAX 255
#define MOTOR_DIR_FWD 1
#define MOTOR_DIR_BWD (-1)

void setupMotor();
void setPowerMotor(int power);
int getPowerMotor(void);


#endif
