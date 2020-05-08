/*------------------------------------------------------------------------------
  Program  : PWMOutESP32
  Descr    : Library for controlling ESP32 PWM outputs similar to use on Arduino
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/PWMOutESP32
  Date     : 2020-05-08
  ------------------------------------------------------------------------------*/
#ifndef PWMOutESP32_h
#define PWMOutESP32_h
#include "Arduino.h"

class PWMOutESP32 {
  public:
    //Initializes the library. Resolution and frequency parameters. If not declared, they assume the default values
    //Resolution between 1 and 16 (bits). Frequency between 1 and 40000 (Hz)
    PWMOutESP32(int resolution = 8, double frequency = 5000);

    //Sets the PWM value on the output pin
    void analogWrite(int pin, int value);

    //Returns the maximum PWM value for the configured resolution
    int getMaxPWMValue();
};
#endif
