#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x47);

void setup() {
  pwm.begin();
  pwm.setPWMFreq(60);
}
void loop() {
  // para a frente
 pwm.setPWM(0,0,4000);
 pwm.setPWM(1,0,2000);
 pwm.setPWM(6,0,4000);
 pwm.setPWM(7,0,2000);
delay(5000);
// para trás
 pwm.setPWM(0,0,000);
  pwm.setPWM(1,0,2000);
  pwm.setPWM(6,0,000);
  pwm.setPWM(7,0,2000);
delay(5000);
}
