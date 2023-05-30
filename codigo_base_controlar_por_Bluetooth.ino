/*
 keyestudio 4DOF Mechanical Robot Arm Car
lesson 14.1
 Bluetooth control robotic arm
 http://www.keyestudio.com
*/
#include <Servo.h>  //add the library of servo
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x47);
int speeds = 2000; //set initial rotation speed of motor

Servo myservo1; //define the name of servo variable
Servo myservo2; //define the name of servo variable
Servo myservo3; //define the name of servo variable
Servo myservo4; //define the name of servo variable
int pos1=90,pos2=100,pos3=80,pos4=90; // define angle variable of four servos(angle value of posture when starting up)
void T_left(){  //turn left
  pos1+=1;
  myservo1.write(pos1);
  delay(10);
  if(pos1>=180){  //set the limited angle value of servo
    pos1=180;
  }}
void T_right(){  //turn right
  pos1-=1;
  myservo1.write(pos1);
  delay(10);
  if(pos1<=0){
    pos1=0;
  }}
void ZB(){  //claw closes
  pos4-=1;
  myservo4.write(pos4);
  delay(5);
  if(pos4<=95){
    pos4=95;
  }}
void ZK(){  //claw opens
  pos4+=1;
  myservo4.write(pos4);
  delay(5);
  if(pos4>=180){
    pos4=180;
  }}
void LF(){  //smaller arm lifts up
  pos2+=1;
  myservo2.write(pos2);
  delay(10);
  if(pos2>=100){
    pos2=100;
  }}
void LB(){  //smaller arm lifts down
  pos2-=1;
  myservo2.write(pos2);
  delay(10);
  if(pos2<=0){
    pos2=0;
  }}
void RF(){  // bigger arm swings forward
  pos3+=1;
  myservo3.write(pos3);
  delay(10);
  if(pos3>=180){
    pos3=180;
  }}
void RB(){  // bigger arm swings back
  pos3-=1;
  myservo3.write(pos3);
  delay(10);
  if(pos3<=80){
    pos3=80;
  }}
void setup(){

  pwm.begin();
  pwm.setPWMFreq(60);
  stopp();  //Car stops 
  
  Serial.begin(9600);
  myservo1.attach(9);  //set control pin of servo 1 to A1
  myservo2.attach(5);  //set control pin of servo 2 to A0
  myservo3.attach(10);   //set control pin of servo 3 to D8
  myservo4.attach(11);   //set control pin of servo 4 to D9
  myservo3.write(pos3);  //servo 3 rotates to 80° 
  delay(500);
  myservo2.write(pos2);  //servo 2 rotates to 100° 
  delay(500);
  myservo1.write(pos1);  //posture to start up, servo 1 rotates to 90°
  delay(500);
  myservo4.write(pos4);  //servo 4 rotates to 90° 
}
void loop(){
  if(Serial.available()>0){  //determine if Bluetooth receives signals
    switch(Serial.read()){
      
      case 'F': advance(); Serial.println("advance"); break; //receive‘F’, go forward
      case 'B': back(); Serial.println("back"); break; //receive‘B’, go back

      case 'L': turnL(); Serial.println("turn left"); break;//receive L’，turn left

      case 'R': turnR(); Serial.println("turn right"); break;//receive‘R’，turn right
      case 'S': stopp(); Serial.println("stop"); break;//receive‘S’，stop
      default : break;
      
      case 'Q':while('Q'){
        LF(); //smaller arm lifts up
        if(Serial.read()=='s')break;
      }break;
      case 'E':while('E'){
        LB(); //smaller arm lifts down
        if(Serial.read()=='s')break;
      }break;
      case 'l':while('l'){
        T_left(); //mechanical arm turns left
        if(Serial.read()=='s')break;
      }break;
      case 'r':while('r'){
        T_right();  //mechanical arm turn right
        if(Serial.read()=='s')break;
      }break;
      case 'f':while('f'){
        RF(); //bigger arm swings forward
        if(Serial.read()=='s')break;
      }break;
      case 'b':while('b'){
        RB(); //bigger arm swings back
        if(Serial.read()=='s')break;
      }break;
      case 'V':while('V'){
        ZK(); //claw opens
        if(Serial.read()=='s')break;
      }break;
      case 'P':while('P'){
        ZB(); //claw closes
        if(Serial.read()=='s')break;
      }break; 
    } }
  delay(5);
}
void advance()     // going forwards
{
  pwm.setPWM(0, 0, 4095); //turn clockwise
  pwm.setPWM(1, 0, speeds);
  pwm.setPWM(6, 0, 4095);
  pwm.setPWM(7, 0, speeds);
}
void turnR()       //turn right
{
  pwm.setPWM(0, 0, 4095); //turn clockwise
  pwm.setPWM(1, 0, speeds);
  pwm.setPWM(6, 0, 0);
  pwm.setPWM(7, 0, speeds);
}
void turnL()      //turn left
{
  pwm.setPWM(0, 0, 0); //turn anticlockwise
  pwm.setPWM(1, 0, speeds);
  pwm.setPWM(6, 0, 4095);
  pwm.setPWM(7, 0, speeds);
}
void stopp()         //stop
{
  pwm.setPWM(1, 0, 0); // adjust speed to 0
  pwm.setPWM(3, 0, 0);
  pwm.setPWM(5, 0, 0);
  pwm.setPWM(7, 0, 0);
}
void back()          //back
{
  pwm.setPWM(0, 0, 0); //turn anticlockwise
  pwm.setPWM(1, 0, speeds);
  pwm.setPWM(6, 0, 0);
  pwm.setPWM(7, 0, speeds);
}
