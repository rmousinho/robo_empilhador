#define SensorLeft    6   //input pin of left sensor
#define SensorMiddle  7   //input pin of middle sensor
#define SensorRight   8   //input pin of right sensor
unsigned char SL;        //state of left sensor
unsigned char SM;        //state of middle sensor
unsigned char SR;        //state of right sensor

void setup() {
Serial.begin(9600);
  pinMode(SensorLeft, INPUT);
  pinMode(SensorMiddle, INPUT);
  pinMode(SensorRight, INPUT);
}

void loop() {
  SL = digitalRead(SensorLeft); 
  Serial.print(" SL: ");
  Serial.print(SL); 
  SM = digitalRead(SensorMiddle);
  Serial.print(" SM: ");
  Serial.print(SM);
  SR = digitalRead(SensorRight);
  Serial.print(" SR: ");
  Serial.print(SR);

  Serial.println();
  delay(500);

}
