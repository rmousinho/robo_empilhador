#include <Servo.h>
Servo myservo1;
int pos1 = 90, pos2 = 0, pos3 = 180;

void setup() {
   myservo1.attach(9);
   
   myservo1.write(pos1);
}

void loop() {
  delay(2000);
  myservo1.write(pos2);
  delay(2000);
  myservo1.write(pos3);
}
