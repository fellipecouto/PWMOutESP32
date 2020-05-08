/*------------------------------------------------------------------------------
  Program  : PWMOutESP32
  Descr    : Library for controlling ESP32 PWM outputs similar to use on Arduino
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/PWMOutESP32
  Date     : 2020-05-08
  ------------------------------------------------------------------------------*/
//PWM as in Arduino on ESP32 using the PWMOutESP32 library
//With resolution and frequency control

#define LED_BUILTIN 2

#include <PWMOutESP32.h> //https://github.com/fellipecouto/PWMOutESP32 [ http://www.efeitonerd.com.br ]

//Resolution between 1 and 16 (bits). Frequency between 1 and 40000 (Hz)
PWMOutESP32 pwm(10, 5000); //Resolution=10bits, Frequency=5000Hz

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println("\nPWMOutESP32");
  Serial.println("Library for controlling ESP32 PWM outputs similar to use on Arduino");
  Serial.print("Maximum PWM value for the configured resolution: ");
  Serial.println(pwm.getMaxPWMValue());
}

void loop() {

  for (int fadeValue = 0; fadeValue <= pwm.getMaxPWMValue(); fadeValue++)  {
    pwm.analogWrite(LED_BUILTIN, fadeValue);
    delay(2);
  }
  delay(500);

  for (int fadeValue = pwm.getMaxPWMValue(); fadeValue >= 0; fadeValue--)  {
    pwm.analogWrite(LED_BUILTIN, fadeValue);
    delay(2);
  }
  delay(500);

}
