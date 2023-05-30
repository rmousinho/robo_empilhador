#define S2 4
#define S3 3
#define sensorOut 2

int redfrequency = 0;
int bluefrequency = 0;
int greenfrequency = 0;
int whitefrequency = 0;

void setup() {
  
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  Serial.begin(9600);
}

void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  redfrequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(redfrequency);//printing RED color frequency
  Serial.print("  ");
  delay(1000);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  greenfrequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(greenfrequency);//printing RED color frequency
  Serial.print("  ");
  delay(1000);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  bluefrequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(bluefrequency);//printing RED color frequency
  Serial.println("  ");
  delay(1000);

  digitalWrite(S2,HIGH);
  digitalWrite(S3,LOW);
  whitefrequency = pulseIn(sensorOut, LOW);
  Serial.print("W= ");
  Serial.print(whitefrequency);
  Serial.println(" ");
  delay(1000);
}
