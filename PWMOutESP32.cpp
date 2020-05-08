/*------------------------------------------------------------------------------
  Program  : PWMOutESP32
  Descr    : Library for controlling ESP32 PWM outputs similar to use on Arduino
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/PWMOutESP32
  Date     : 2020-05-08
  ------------------------------------------------------------------------------*/
#include "PWMOutESP32.h"
#include <Arduino.h>
int _channel[16];
int _resolution;
double _frequency;

PWMOutESP32::PWMOutESP32(int resolution, double frequency) {
  _resolution = resolution;
  _frequency = frequency;
  for (int c = 0; c < 16; c++) {
    _channel[c] = 99;
  }
}

void PWMOutESP32::analogWrite(int pin, int value) {
  int channelPin = 99;
  for (int c = 0; c < 16; c++) {
    if (_channel[c] == pin) {
      channelPin = c;
      break;
    }
  }
  if (channelPin == 99) {
    for (int c = 0; c < 16; c++) {
      if (_channel[c] == 99) {
        _channel[c] = pin;
        channelPin = c;
        break;
      }
    }
  }
  ledcAttachPin(pin, channelPin);
  ledcSetup(channelPin, _frequency, _resolution);
  ledcWrite(channelPin, value);
}

int PWMOutESP32::getMaxPWMValue() {
  return pow(2, _resolution) - 1;
}
