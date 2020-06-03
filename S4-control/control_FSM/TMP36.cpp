#include "TMP36.h"
#include "Arduino.h"

void setupTMP36(){
  pinMode(TMP36_PIN, INPUT);
}

float getTemperature(void){
  int rawTemp = analogRead(TMP36_PIN);
  float temp = map(((rawTemp - 20) * 3.04), ADC_MIN, ADC_MAX, TMP_MIN, TMP_MAX);
  return temp;
}
