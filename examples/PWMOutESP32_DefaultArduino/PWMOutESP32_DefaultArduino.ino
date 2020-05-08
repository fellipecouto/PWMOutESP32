/*------------------------------------------------------------------------------
  Program  : PWMOutESP32
  Descr    : Library for controlling ESP32 PWM outputs similar to use on Arduino
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/PWMOutESP32
  Date     : 2020-05-08
  ------------------------------------------------------------------------------*/
//PWM as in Arduino on ESP32 using the PWMOutESP32 library

#define LED_BUILTIN 2

#include <PWMOutESP32.h> //https://github.com/fellipecouto/PWMOutESP32 [ http://www.efeitonerd.com.br ]

PWMOutESP32 pwm;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  for (int fadeValue = 0; fadeValue <= 255; fadeValue++)  {
    pwm.analogWrite(LED_BUILTIN, fadeValue);
    delay(5);
  }
  delay(500);

  for (int fadeValue = 255; fadeValue >= 0; fadeValue--)  {
    pwm.analogWrite(LED_BUILTIN, fadeValue);
    delay(5);
  }
  delay(500);
  
}
