#include <ATX2.h>
#define M5          (5)
#define M6          (6)
#define INFRA_RIGHT (24)
#define INFRA_LEFT  (26)


void setup()
{
  OK();// Wait for OK button
  glcdClear();

}

void loop()
{
  unsigned int INFRA_READING_BOTH = 0;
  //Start of the conditional Statements determining the state of the motors
  int infra_read_r = digitalRead(INFRA_RIGHT);
  int infra_read_l = digitalRead(INFRA_LEFT);
  
  
  if(infra_read_r ==HIGH & infra_read_l ==HIGH ){
    MoveForwards();
    
  }else if(infra_read_r ==HIGH & infra_read_l ==LOW ){
    TurnLeft();
    
  }else if(infra_read_r ==LOW & infra_read_l ==HIGH ){
    TurnRight();
    
  }else if(infra_read_r ==LOW & infra_read_l ==LOW ){
    if (INFRA_READING_BOTH == 0){
      SpecialRight();
    }else{
      SpecialLeft(); 
    }
    
  }
  //End of the conditional statements determining the state of the motors
}

//Declaration of the Functions essential to the robot
void MoveForwards(){  //Move the robot FORWARD
  ao();
  motor(M5, 6);
  motor(M6, 6); 
}
void MoveBackwards(){ //Move the robot BACKWARD
  ao();
  motor(M5, -20);
  motor(M6, -20);
  delay(200); 
}
void TurnRight(){    //Turn the robot RIGHT
  ao();
  motor(M5, 15);
  motor(M6, -5);
}
void TurnLeft(){     //Turn the robot LEFT
  ao();
  motor(M5, -5);
  motor(M6, 15);
}
void Stop(){         //STOP
  ao();
}
void SpecialRight(){
  motor(M5, 20);
  motor(M6, 0);
  delay(100);
}
void SpecialLeft(){
  motor(M5, 0);
  motor(M6, 20);
  delay(100);
}
