#include <Servo.h> 
 
Servo myservo;
 
void setup() 
{ 
  myservo.attach(9);
 
} 
 
void loop() {

  myservo.writeMicroseconds(1000);  // set servo to mid-point
  delay(2000);
   myservo.writeMicroseconds(1500);  // set servo to mid-point
  delay(2000);
   myservo.writeMicroseconds(2000);  // set servo to mid-point
  delay(2000);
  myservo.writeMicroseconds(1500);  // set servo to mid-point
  delay(2000);
  
  } 
