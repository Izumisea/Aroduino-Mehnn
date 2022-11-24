#include <Servo.h>

Servo myservo;
char t;
int pos = 0;

void pindot()
  {
  if(pos = 0; pos <= 180; pos += 1)
   myservo.write(pos);              
   delay(15);                       
  if(pos = 180; pos >= 0; pos -= 1)  
   myservo.write(pos);              
   delay(15);                       
  }
  void top()
  {
  if(pos = 0; pos <= 180; pos += 1)
   myservo.write(pos);                     
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9)
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
  }
  if(t == 'N'){            //move forward(all motors rotate in forward direction)
  pindot();
 }
  if(t == 'F'){            //move forward(all motors rotate in forward direction)
  top();
 }
}
