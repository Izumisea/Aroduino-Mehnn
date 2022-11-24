//code made by Izumisea

#include <Servo.h>          
#define UP 180              
#define DOWN 0             

Servo mop1;

char bluetooth;
int mop1_pin = 4;

void SET_MOP(int pos) {
  mop1.write(pos);
}

void setup() {
 mop1.attach(mop1_pin);
 Serial.begin(9600);       
 
}

void loop() {
if(Serial.available()){    
  bluetooth = Serial.read();
  Serial.println(bluetooth);
  }
  if(bluetooth == 'F'){            
  SET_MOP(UP);
  delay(1000);
  SET_MOP(DOWN);
  delay(1000);
 }
  if(bluetooth == 'B'){            
  SET_MOP(DOWN);
 }
}
