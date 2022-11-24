//*********************************************//
//                 THE BEAST                   //
//                  SUMOBOT                    //
//     enables BEAST ATTACK opponents using    //
//         ultrasonic sensor as its eye        //
//       and bumps target across the ring      //
//     avoiding the BLACK line as perimeter    //
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
Servo MYSERVO;

int SERVOPIN=4;
int TRIGPIN=30;
int ECHOPIN=31;
float DISTANCE;
float DURATION;

// INITIALIZATION:
#define MOTOR_1_DIRECTION         8       // Motor control HIGH = FWD, LOW = BWD
#define MOTOR_1_SPEED             9       // Speed input from 0 to 255 (left motor)
#define MOTOR_2_SPEED            10       // Speed input from 0 to 255 (right motor)
#define MOTOR_2_DIRECTION        11       // Motor control HIGH = FWD, LOW = BWD

#define LEFT_LINE_SENSOR          5       // Line sensor left 
#define CENTER_LINE_SENSOR        6       // Line sensor center
#define RIGHT_LINE_SENSOR         7       // Line sensor right

int FULL_SPEED = 255;                    // 0 means fullstop on analog read,255 means fullspeed,feel free to play analog values from 0-255
int FULL_STOP = 0;
int LINER = 0;
int LINERS = 0;
boolean LINE = false;
boolean GO = false;

char  rxmsg[30];
byte  inputData[15];
byte stage;
byte rxctr;
byte  msg;
/**********************************************************************************/
void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
    delay(2000);
    Send_Command("F");
  Send_Command("c"); 

  Send_To("1","e-Gizmo","6");
  Send_To("2","THE BEAST","5");
  Send_To("3","SUMOBOT FIGHTER","2");
    Send_To("4","WHITE ARENA","4");
  delay(2000);

  pinMode(SERVOPIN,OUTPUT);
  pinMode(TRIGPIN,OUTPUT);
  pinMode(ECHOPIN,INPUT);

  pinMode(MOTOR_1_DIRECTION, OUTPUT);
  pinMode(MOTOR_1_SPEED, OUTPUT);
  pinMode(MOTOR_2_SPEED, OUTPUT);
  pinMode(MOTOR_2_DIRECTION, OUTPUT);
  MYSERVO.attach(SERVOPIN);

  pinMode(LEFT_LINE_SENSOR, INPUT_PULLUP);
  pinMode(CENTER_LINE_SENSOR, INPUT_PULLUP);
  pinMode(RIGHT_LINE_SENSOR, INPUT_PULLUP);

}
int ping()
{
  digitalWrite(TRIGPIN,LOW);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW);

  DURATION= pulseIn(ECHOPIN,HIGH);
  DISTANCE= DURATION*0.034/2;
  return(DISTANCE);
}
/**********************************************************************************/
void loop()
{ 
  int LINE_SENSE_LEFT =      digitalRead(LEFT_LINE_SENSOR);
  int LINE_SENSE_CENTER =    digitalRead(CENTER_LINE_SENSOR);
  int LINE_SENSE_RIGHT =     digitalRead(RIGHT_LINE_SENSOR);

  float VALUE;
  VALUE=ping();                // value ng ultrasonic
  delay(10);

  // If line is detected:
  if((LINE_SENSE_LEFT == 1|| LINE_SENSE_CENTER == 1) || LINE_SENSE_RIGHT == 1)
  {
    LINER-=1;
  }


  // If there is no line detected and there is no enemy
  while(LINER == 1 && VALUE > 20)
  {
    STOP();                     // pag less than 20cm,search mode
    delay(200);
    LOOKING_FOR_OPPONENT();
    delay(200);
    break;
  }
  // If there is an enemy and there is no line detected
  while((VALUE < 20 && VALUE > 0) && LINER == 1) 
  {
    ATTACK();                   // pag greater than 20cm,attack mode
    delay(500);
    break;
  }
  while((VALUE < 20 && VALUE > 0) && LINER == 0)
  {
    STOP();
    delay(500);
    GO_BACKWARD ();
    delay(500);
    SPIN_LEFT();
    break;
  }

  // Turn around if line is detected:
  if(LINER == 0)
  {
    SPIN_LEFT();
    delay(1500);
    GO_FORWARD_SLOW();
  }
  LINER = 1;

  MYSERVO.write(90);
}

/*---------------------------*/
void LOOKING_FOR_OPPONENT ()
{
  int OPPONENT_ON_LEFT;
  int OPPONENT_ON_CENTER;
  int OPPONENT_ON_RIGHT;
  MYSERVO.write(10);
  delay(500);
  OPPONENT_ON_RIGHT = ping();
  WHILE_SEARCHING_LINE_DETECTED();
  MYSERVO.write(170);
  delay(500);
  OPPONENT_ON_LEFT = ping();
  WHILE_SEARCHING_LINE_DETECTED();
  MYSERVO.write(90);
  delay(500);
  OPPONENT_ON_CENTER= ping();
  WHILE_SEARCHING_LINE_DETECTED();
  /*---------------------------*/
  if(OPPONENT_ON_RIGHT <= 20 && LINER == 1 )
  {
    STOP();  
    GO = true;
    if(OPPONENT_ON_RIGHT <=20 && GO == true){
      SPIN_LEFT();
      delay(1000); 
      ATTACK();  
      delay(500);
      GO = false;
    }
  }
  /*---------------------------*/
  else if(OPPONENT_ON_LEFT <= 20 && LINER == 1)
  { 
    SPIN_RIGHT();
    delay(1000);
    ATTACK();                                       
    delay(500);
  }
  /*---------------------------*/
  else if(OPPONENT_ON_LEFT = OPPONENT_ON_RIGHT)
  {
    GO_FORWARD_SLOW();
  }
}
/*---------------------------*/
// MOTOR CONTROL FUNCTION
void ATTACK()
{
  digitalWrite(MOTOR_1_DIRECTION,HIGH);
  digitalWrite(MOTOR_2_DIRECTION,HIGH);
  analogWrite(MOTOR_1_SPEED,FULL_SPEED);
  analogWrite(MOTOR_2_SPEED,FULL_SPEED);

}
/*---------------------------*/
void GO_FORWARD_SLOW()
{
  digitalWrite(MOTOR_1_DIRECTION, HIGH); 
  digitalWrite(MOTOR_2_DIRECTION, HIGH);
  analogWrite(MOTOR_1_SPEED,200);
  analogWrite(MOTOR_2_SPEED,200);
}
/*---------------------------*/
void GO_BACKWARD()
{
  digitalWrite(MOTOR_1_DIRECTION,LOW);
  digitalWrite(MOTOR_2_DIRECTION,LOW);
  analogWrite(MOTOR_1_SPEED,FULL_SPEED);
  analogWrite(MOTOR_2_SPEED,FULL_SPEED);
}
/*---------------------------*/
void STOP()
{
  digitalWrite(MOTOR_1_DIRECTION,LOW);
  digitalWrite(MOTOR_2_DIRECTION,LOW);
  analogWrite(MOTOR_1_SPEED,0);
  analogWrite(MOTOR_2_SPEED,0); 
}
/*---------------------------*/
void SPIN_LEFT()
{
  digitalWrite(MOTOR_1_DIRECTION,LOW);
  digitalWrite(MOTOR_2_DIRECTION,HIGH);
  analogWrite(MOTOR_1_SPEED,FULL_SPEED);
  analogWrite(MOTOR_2_SPEED,FULL_SPEED);
}
/*---------------------------*/
void SPIN_RIGHT()
{
  digitalWrite(MOTOR_1_DIRECTION,HIGH);
  digitalWrite(MOTOR_2_DIRECTION,LOW);
  analogWrite(MOTOR_1_SPEED,FULL_SPEED);
  analogWrite(MOTOR_2_SPEED,FULL_SPEED);
}
//**********************************************************************************
void WHILE_SEARCHING_LINE_DETECTED(){
  int LINE_SENSE_LEFT =      digitalRead(LEFT_LINE_SENSOR);
  int LINE_SENSE_CENTER =    digitalRead(CENTER_LINE_SENSOR);
  int LINE_SENSE_RIGHT =     digitalRead(RIGHT_LINE_SENSOR);
  if(LINE_SENSE_LEFT == 1  || LINE_SENSE_RIGHT == 1)
  {
    LINER-=1;
  }
  if(LINER == 0){
    GO_BACKWARD();
    delay(500);
    SPIN_LEFT();
    delay(800);
    GO_FORWARD_SLOW();
    STOP();
  }
  LINER = 1;

}
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











