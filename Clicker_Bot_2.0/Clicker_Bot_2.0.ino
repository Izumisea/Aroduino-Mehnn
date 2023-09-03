//code made by Izumisea

#include <Servo.h>          
#define UP 180              
#define DOWN 0             

Servo myservo;

char bluetooth;
int myservo_pin = 4;

void myservo_pos(int pos) {
  myservo.write(pos);
}

void setup() {
 myservo.attach(myservo_pin);
 Serial.begin(9600);       
 
}

void loop() {
if(Serial.available()){    
  bluetooth = Serial.read();
  Serial.println(bluetooth);
  }
  if(bluetooth == 'F'){            
  myservo_pos(UP);
  delay(1000);
  myservo_pos(DOWN);
  delay(1000);
 }
  if(bluetooth == 'B'){            
  myservo_pos(DOWN);
 }
}
