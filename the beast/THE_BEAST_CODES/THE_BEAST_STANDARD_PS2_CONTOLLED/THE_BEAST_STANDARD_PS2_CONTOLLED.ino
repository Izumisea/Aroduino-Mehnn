//  PARZ (THE BEAST)
//*************************************************************************************************************************************************************************************************************************************************************************.
// INITIALIZATION:
#include <Servo.h>
#define PH_MOTOR_2_DIRECTION              8
#define PWH_ON_SPEED_CONTROL_2            9
#define PWH_ON_SPEED_CONTROL_1            10
#define PH_MOTOR_1_DIRECTION              11
#define  MODEPIN  2
#define SER_SYNC1 0
#define SER_SYNC2 1
#define SER_FETCHDATA 2

int PWH_ON_SPEED_CONTROL_VALUE = 250;
int STEERING_SPEED = 200;
int PAUSE = 200;
char SERIAL_DATA;

char  rxmsg[30];
byte  inputData[15];
byte stage;
byte rxctr;
byte  msg;
byte serial_rxcounter=0;
byte serial_state=0;

boolean serial_available = false;
boolean CLR = false;

float left_x;
float left_y;
float right_x;
float right_y;

typedef  struct cont cont;
struct cont
{
  boolean  up;
  boolean  down;
  boolean  left;
  boolean  right;
  boolean  triangle;
  boolean  circle;
  boolean  cross;
  boolean  square;
  boolean  left1;
  boolean  left2;
  boolean  right1;
  boolean  right2;
  boolean  start;
  byte  leftx;
  byte  lefty;
  byte  rightx;
  byte  righty;
};
cont  controller;
//*************************************************************************************************************************************************************************************************************************************************************************
void setup(){
  int i;
  Serial.begin(9600);
  Serial1.begin(9600);

  pinMode(PH_MOTOR_1_DIRECTION,OUTPUT);
  pinMode(PH_MOTOR_2_DIRECTION ,OUTPUT);
  pinMode(PWH_ON_SPEED_CONTROL_1,OUTPUT);
  pinMode(PWH_ON_SPEED_CONTROL_2,OUTPUT);
  pinMode(i,OUTPUT);

  for(i=0;i<20;i++) IO("o",i);
  digitalWrite(MODEPIN,HIGH);
  if(digitalRead(MODEPIN)==HIGH) Send_Command("F"); 
  Send_Command("F");
  Send_Command("c"); 

  Send_To("2","e-Gizmo","6");
  Send_To("3","THE BEAST","5");
  delay(2000);
  Send_To("1","* IMPORTANT *","4");
  Send_To("2","MAKE SURE THAT THE","1");
  Send_To("3","PS2 CONTROLLER","3");
  Send_To("4","IS OFF","6");
  delay(5000); 
  Send_Command("c");
  Send_To("1","THE BEAST STANDARD","1");
  Send_To("2","JOYSTICK LEFT ","3");
  Send_To("3","X:","6");
  Send_To("4","Y:","6");
}

//*************************************************************************************************************************************************************************************************************************************************************************
void  loop(void)
{
  if (serial_available==true) {
    serial_available = false;
    serial_state=SER_SYNC1;

    left_x = controller.leftx;
    left_y = controller.lefty;

    //LEFTX JOYSTICK
    Serial1.write(0x02);      //STX
    Serial1.print(">");       // Send position info
    Serial1.print(8);         // LINES 1 TO 20
    Serial1.write(0x03);      //ETX

    Serial1.write(0x02);
    Serial1.print(3);         // ROW 1 TO 4 
    Serial1.print(left_x);    // WHAT TO DISPLAY
    Serial1.write(0x03);

    //LEFTY JOYSTICK
    Serial1.write(0x02);  
    Serial1.print(">");    
    Serial1.print(8);
    Serial1.write(0x03);   

    Serial1.write(0x02);
    Serial1.print(4);    
    Serial1.print(left_y);
    Serial1.write(0x03);


    //LEFT JOYSTICK
    if(controller.lefty == 0){ 
      GO_FORWARD ();
    }
    else if(controller.leftx == 0){
      SPIN_LEFT();
    }
    else if(controller.lefty == 255){
      GO_BACKWARD ();
    }
    else if(controller.leftx == 255){
      SPIN_RIGHT();
    }
    else if(CLR == true){
      Serial1.write(0x02);     
      Serial1.print(">");     
      Serial1.print(9);
      Serial1.write(0x03);  

      Serial1.write(0x02);
      Serial1.print(1);    
      Serial1.print("        ");
      Serial1.write(0x03);
    }
    else{
      GO_STOP ();

    }
  }
}

//*************************************************************************************************************************************************************************************************************************************************************************
// PRESET FUNCTIONS:
// MOTOR ROUTINE::
void GO_FORWARD (){
  digitalWrite(PH_MOTOR_1_DIRECTION,HIGH);
  digitalWrite(PH_MOTOR_2_DIRECTION,HIGH);  
  analogWrite(PWH_ON_SPEED_CONTROL_1,PWH_ON_SPEED_CONTROL_VALUE);
  analogWrite(PWH_ON_SPEED_CONTROL_2,PWH_ON_SPEED_CONTROL_VALUE);
}
void GO_BACKWARD (){
  digitalWrite(PH_MOTOR_1_DIRECTION,LOW);
  digitalWrite(PH_MOTOR_2_DIRECTION,LOW);  
  analogWrite(PWH_ON_SPEED_CONTROL_1,PWH_ON_SPEED_CONTROL_VALUE);
  analogWrite(PWH_ON_SPEED_CONTROL_2,PWH_ON_SPEED_CONTROL_VALUE);
}
void GO_STOP (){
  analogWrite(PWH_ON_SPEED_CONTROL_1,0);
  analogWrite(PWH_ON_SPEED_CONTROL_2,0);
}
void SPIN_LEFT (){
  digitalWrite(PH_MOTOR_1_DIRECTION,HIGH);
  digitalWrite(PH_MOTOR_2_DIRECTION,LOW);  
  analogWrite(PWH_ON_SPEED_CONTROL_1,STEERING_SPEED);
  analogWrite(PWH_ON_SPEED_CONTROL_2,STEERING_SPEED);
}
void SPIN_RIGHT (){
  digitalWrite(PH_MOTOR_1_DIRECTION,LOW);
  digitalWrite(PH_MOTOR_2_DIRECTION,HIGH);  
  analogWrite(PWH_ON_SPEED_CONTROL_1,STEERING_SPEED);
  analogWrite(PWH_ON_SPEED_CONTROL_2,STEERING_SPEED);
}

//*************************************************************************************************************************************************************************************************************************************************************************
void serialEvent() {
  while (Serial.available()) {
    byte inChar = (byte)Serial.read(); 
    switch(serial_state){
    case SER_SYNC1:

      serial_rxcounter=0;
      if(inChar==0x5A)serial_state=SER_SYNC2;
      break;
    case SER_SYNC2:
      if(inChar==0xA5) 
        serial_state=SER_FETCHDATA;
      else
        serial_state=SER_SYNC1;
      break;
    case  SER_FETCHDATA:
      inputData[serial_rxcounter]= inChar;
      serial_rxcounter++;
      if(serial_rxcounter>=10){
        if(checksum()==inputData[9]){
          refresh_controller();
          serial_available=true;   
        }
        else{    
          serial_state=SER_SYNC1;
          serial_available=false;
        }
      }
    }
  }
}

//*************************************************************************************************************************************************************************************************************************************************************************
void  refresh_controller(void){
  controller.up=false;
  if((inputData[3]&0x08)==0) controller.up=true;
  controller.down=false;
  if((inputData[3]&0x02)==0) controller.down=true;
  controller.left=false;
  if((inputData[3]&0x01)==0) controller.left=true;
  controller.right=false;
  if((inputData[3]&0x04)==0) controller.right=true;
  controller.triangle=false;
  if((inputData[4]&0x08)==0) controller.triangle=true;
  controller.circle=false;
  if((inputData[4]&0x04)==0) controller.circle=true;
  controller.cross=false;
  if((inputData[4]&0x02)==0) controller.cross=true;
  controller.square=false;
  if((inputData[4]&0x01)==0) controller.square=true;
  controller.left1=false;
  if((inputData[4]&0x20)==0) controller.left1=true;
  controller.left2=false;
  if((inputData[4]&0x80)==0) controller.left2=true;
  controller.right1=false;
  if((inputData[4]&0x10)==0) controller.right1=true;
  controller.right2=false;
  if((inputData[4]&0x40)==0) controller.right2=true;
  controller.start=false;
  if((inputData[3]&0x10)==0) controller.start=true;
  controller.leftx=inputData[7];
  controller.lefty=inputData[8];
  controller.rightx=inputData[5];
  controller.righty=inputData[6];
}
byte  checksum(void){
  int  i;
  byte chk= 0x5A+0xA5;
  for(i=0;i<9;i++) chk += inputData[i];
  return(chk);
}
//*************************************************************************************************************************************************************************************************************************************************************************
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
//*************************************************************************************************************************************************************************************************************************************************************************









