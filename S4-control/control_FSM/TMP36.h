#ifndef TMP36_H_
#define TMP36_H_

#define TMP36_PIN A0
#define ADC_MIN 0
#define ADC_MAX 1023
#define TMP_MIN -40
#define TMP_MAX 125

void setupTMP36();
float getTemperature(void);

#endif
