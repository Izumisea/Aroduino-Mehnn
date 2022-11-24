//*********************************************//
//                 THE BEAST                   //
//             OBSTACLE AVOIDER                //
//       enables BEAST to avoid obstacles      //
//             along in its path               //
//                 Codes by:                   //
//        e-Gizmo Mechatronix Central          //
//         Taft, Manila, Philippines           //
//           http://www.egizmo.com             //
//              dec 8,2016-(2019)              //
//*********************************************//

// WIRING FROM GIZDUINO PLUS 644 TO BEEFY MOTOR DRIVER:
//------------------------------------------------------------------------------------------------------------------------
/*
       GIZDUINO PLUS 644                 BEFFY MOTOR DRIVER 1 LEFT                 FUNCTION
 -----------------                         --------------------                    --------
 5V                                            PWL AND SR                       + LOGIC SUUPLY
 RST                                              RST                           RESET THE MOTOR
 GND                                              GND                           - LOGIC SUUPLY
 10                                               PWH                                 ON/PWM
 11                                               PH                            DIRECTION (FF,REV)
 
 BEFFY MOTOR DRIVER 2 RIGHT 
 --------------------
 5V                                            PWL AND SR                       + LOGIC SUUPLY
 RST                                              RST                            RESET THE MOTOR
 GND                                              GND                            - LOGIC SUUPLY
 9                                                PWH                                 ON/PWM
 8                                                PH                            DIRECTION (FF,REV)
 */
//------------------------------------------------------------------------------------------------------------------------
// INITIALIZATION:
#include<Servo.h>
Servo myservo;

int servopin=4;
int trigpin=30;
int echopin=31;
float distance;
float duration;

char  rxmsg[30];
byte  inputData[15];
byte stage;
byte rxctr;
byte  msg;

#define PH_MOTOR_2_DIRECTION              8
#define PWH_ON_SPEED_CONTROL_2            9
#define PWH_ON_SPEED_CONTROL_1            10
#define PH_MOTOR_1_DIRECTION              11

int PWH_ON_SPEED_CONTROL_VALUE = 255;
int STEERING_SPEED = 255;
int PAUSE = 200;
int FULL_STOP = 0;
//------------------------------------------------------------------------------------------------------------------------
// INPUTS AND OUTPUTS:
void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
    delay(2000);
  Send_Command("F");
  Send_Command("c"); 

  Send_To("1","e-Gizmo","6");
  Send_To("2","THE BEAST","5");
  Send_To("3","OBSTACLE AVOIDER","2");
  delay(2000);

  pinMode(servopin,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  myservo.attach(servopin); 

  pinMode(PH_MOTOR_1_DIRECTION,OUTPUT);
  pinMode(PH_MOTOR_2_DIRECTION ,OUTPUT);
  pinMode(PWH_ON_SPEED_CONTROL_1,OUTPUT);
  pinMode(PWH_ON_SPEED_CONTROL_2,OUTPUT);

  digitalWrite(PH_MOTOR_1_DIRECTION,HIGH);
  digitalWrite(PH_MOTOR_2_DIRECTION,HIGH);
}
int ping()
{
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);

  duration= pulseIn(echopin,HIGH);
  distance= duration*0.034/2;
  return(distance);
}
//------------------------------------------------------------------------------------------------------------------------
// MAIN PROGRAM:
void loop()
{ 
  myservo.write(90);
  float value;
  value=ping();
  Serial.println(value);
  delay(10);

  if(value>=20)
  {
    GO_FORWARD();
    delay(100);
  }
  if(value<20 )
  {
    GO_STOP();
    delay(100);
    GO_BACKWARD();
    delay(400);
    GO_STOP();
    delay(100);
    DO_OBSTACLE_AVOIDING();
    delay(200);
  }
  myservo.write(90);
}
void DO_OBSTACLE_AVOIDING ()
{
  int OBSTACLE_ON_LEFT;
  int OBSTACLE_ON_RIGHT;
  myservo.write(10);
  delay(500);
  OBSTACLE_ON_LEFT = ping();
  myservo.write(170);
  delay(500);
  OBSTACLE_ON_RIGHT = ping();
  if(OBSTACLE_ON_LEFT > OBSTACLE_ON_RIGHT)
  {
    SPIN_LEFT();
    delay(800);     
  }
  else if(OBSTACLE_ON_LEFT < OBSTACLE_ON_RIGHT)
  {
    SPIN_RIGHT();
    delay(800);    
  }
  else if(OBSTACLE_ON_LEFT = OBSTACLE_ON_RIGHT)
  {
    GO_BACKWARD();
    delay(1000);
    SPIN_RIGHT();
    delay(800);
  }
}
//------------------------------------------------------------------------------------------------------------------------
// PRESET FUNCTIONS:
// MOTOR ROUTINE::
void GO_FORWARD (){
  digitalWrite(PH_MOTOR_1_DIRECTION,HIGH);
  digitalWrite(PH_MOTOR_2_DIRECTION,HIGH);  
  analogWrite(PWH_ON_SPEED_CONTROL_1,PWH_ON_SPEED_CONTROL_VALUE);
  analogWrite(PWH_ON_SPEED_CONTROL_2,PWH_ON_SPEED_CONTROL_VALUE);
  delay(PAUSE);
}
void GO_BACKWARD (){
  digitalWrite(PH_MOTOR_1_DIRECTION,LOW);
  digitalWrite(PH_MOTOR_2_DIRECTION,LOW);  
  analogWrite(PWH_ON_SPEED_CONTROL_1,PWH_ON_SPEED_CONTROL_VALUE);
  analogWrite(PWH_ON_SPEED_CONTROL_2,PWH_ON_SPEED_CONTROL_VALUE);
  delay(PAUSE);
}
void GO_STOP (){
  analogWrite(PWH_ON_SPEED_CONTROL_1,0);
  analogWrite(PWH_ON_SPEED_CONTROL_2,0);
  delay(PAUSE);
}
void SPIN_LEFT (){
  digitalWrite(PH_MOTOR_1_DIRECTION,HIGH);
  digitalWrite(PH_MOTOR_2_DIRECTION,LOW);  
  analogWrite(PWH_ON_SPEED_CONTROL_1,STEERING_SPEED);
  analogWrite(PWH_ON_SPEED_CONTROL_2,STEERING_SPEED);
  delay(PAUSE);
}
void SPIN_RIGHT (){
  digitalWrite(PH_MOTOR_1_DIRECTION,LOW);
  digitalWrite(PH_MOTOR_2_DIRECTION,HIGH);  
  analogWrite(PWH_ON_SPEED_CONTROL_1,STEERING_SPEED);
  analogWrite(PWH_ON_SPEED_CONTROL_2,STEERING_SPEED);
  delay(PAUSE);
}
//*********************************************************************************************************************************
void  wait_response(void){
  while(stage !=3) read_buffer();
}
void  read_buffer(void){
  if(Serial1.available()>0){
    char  rxchar=Serial1.read(); 
    if(stage==0){            
      if(rxchar==0x02){       
        stage=1;            
        return;
      }
    }
    if(stage==1){             
      if(rxchar==0x03)      
      {
        stage=3;           
        rxmsg[rxctr]=0;    
      }
      else
      {
        if(rxctr<30){     
          rxmsg[rxctr]=rxchar;
          rxctr++;
        }
      }
    }
  }
}
void Send_Command(char *message){
  Serial1.write(0x02);    
  Serial1.print(message);
  Serial1.write(0x03);      
  stage=0;              
  rxctr=0;
  wait_response();       
}
void Send_To(char *line,char *message,char *pos){
  String k=message;      
  Serial1.write(0x02);     
  Serial1.print(">");     
  Serial1.print(pos);
  Serial1.write(0x03);  
  stage=0;
  rxctr=0;
  wait_response();
  Serial1.write(0x02); 
  Serial1.print(line); 
  Serial1.print(k);
  Serial1.write(0x03);
  stage=0;
  rxctr=0;
  wait_response();
}
void IO(char *message,int port){
  Serial1.write(0x02);   
  Serial1.print(message);
  Serial1.print(port);
  Serial1.write(0x03);    
  stage=0;                
  rxctr=0;
  wait_response();       
}
// PROGRAM ENDS AND LOOP BACK FOREVER  
//**********************************************************************************//PARZ


