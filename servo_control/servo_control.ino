
// Basic servo && Bluetooth Control
// subcribe to my youtube chanel


  
#include <Servo.h>          
#define UP 180              
#define DOWN 0             

Servo arm;

bool a = false;


char t;
int arm_pin = 4;

void set_arm(int pos) {
  arm.write(pos);
}

void setup() {
  // put your setup code here, to run once:
  arm.attach(arm_pin);
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()){    
  t = Serial.read();
  Serial.println(t);
  }
  if(t == 'f'){            
  set_arm(UP);
  delay(1000);
  set_arm(DOWN);
  delay(1000);
 }
  if(t == 'b'){            
  set_arm(DOWN);
 }
}
