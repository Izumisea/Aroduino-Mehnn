#include <Servo.h> 
 
Servo myservoX;
Servo myservoY;
Servo myservoZ;

int VRx = A1;
int VRy = A2;
int SW = A3;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 

  myservoX.attach(7);
  myservoY.attach(6);
  myservoZ.attach(5);
      
}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  
  if(mapX == 512){
      myservoX.writeMicroseconds(1000);  
    }else if(mapX == -512) {
      myservoX.writeMicroseconds(2000);  
      }else{
        myservoX.writeMicroseconds(1500);  
        }

         if(mapY == 512){
              myservoY.writeMicroseconds(1250);  
                }else if(mapY == -512) {
                  myservoY.writeMicroseconds(1750);  
                     }else{
                        myservoY.writeMicroseconds(1500);  
                         }

                           if(SW_state == 1){
                            myservoZ.writeMicroseconds(1000);  
                            }else {
                              myservoZ.writeMicroseconds(2000);  
                              }
      
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);
  delay(100);
}
