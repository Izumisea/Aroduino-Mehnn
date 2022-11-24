//*********************************************//
//                 THE BEAST WITH              //
//              WIRELESS PS2 CONTROLLED        //
//                                             //
//                                             //
//      ALL PS2 FUNCTIONS JUST FOR DEBUGGING   //
//          THIS PROGRAM IS FOR PARZ ONLY      //
//        NOTE: TURN THE PS2 CONTROLLER OFF    //
//           BEFORE TURNING ON THE BEAST       //
//     THEN TURN THE PS2 CONTROLLER ON AFTER   //
//            THE DISPLAY STABILIZE            //
//                                             //
//                JUNE 17,2016                 //
//*********************************************//
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
//***************************************************************************************************
//                                       INITIALIZATION
//***************************************************************************************************
#include <Servo.h>
Servo myservo1;
Servo myservo2;

#define PH_MOTOR_2_DIRECTION              8
#define PWH_ON_SPEED_CONTROL_2            9
#define PWH_ON_SPEED_CONTROL_1            10
#define PH_MOTOR_1_DIRECTION              11
#define  MODEPIN  2
#define SER_SYNC1 0
#define SER_SYNC2 1
#define SER_FETCHDATA 2

int PWH_ON_SPEED_CONTROL_VALUE = 250;
int STEERING_SPEED = 250;
int PAUSE = 200;
int pos1 = 90;
int pos2 = 90;

int val0;
int val1;
int valx0;
int valy0;
int button_latch_L1 = 0;
int button_latch_L2 = 0;

char SERIAL_DATA;
char  rxmsg[30];

float left_x;
float left_y;
float right_x;
float right_y;

byte  inputData[15];
byte stage;
byte rxctr;
byte  msg;
byte serial_rxcounter=0;
byte serial_state=0;

boolean CLR = false;
boolean serial_available = false; 
typedef  struct cont cont;
struct cont{
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
//***************************************************************************************************
//                                 SET UP (INPUT,OUTPUT)
//***************************************************************************************************
void setup(){
  int i;
  Serial.begin(9600);
  Serial1.begin(9600);

  myservo1.attach(12);
  myservo2.attach(4);
  delay(1500);

  pinMode(PH_MOTOR_1_DIRECTION,OUTPUT);
  pinMode(PH_MOTOR_2_DIRECTION ,OUTPUT);
  pinMode(PWH_ON_SPEED_CONTROL_1,OUTPUT);
  pinMode(PWH_ON_SPEED_CONTROL_2,OUTPUT);
  pinMode(i,OUTPUT);

  for(i=0;i<32;i++) IO("o",i);
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
  Send_To("1","BEAST:","0");
  Send_To("2","JS LEFT     RIGHT","0");
  Send_To("3","X:","0");
  Send_To("4","Y:","0");
}
//***************************************************************************************************
//                                  PROGRAM LOOP STARTS HERE
//***************************************************************************************************
void  loop(void)
{
  if (serial_available==true) {
    serial_available = false;
    serial_state=SER_SYNC1;
    //***************************************
    //          JOYSTICK FUNCTION
    //***************************************
    left_x = controller.leftx;
    left_y = controller.lefty;

    right_x = controller.rightx;
    right_y = controller.righty;   
    //LEFTX JOYSTICK
    Serial1.write(0x02);      // START BIT
    Serial1.print(">");       
    Serial1.print(3);         // SEND MESSAGE FROM LINES 1 TO 20
    Serial1.write(0x03);      // STOP BIT

    Serial1.write(0x02);      // START BIT
    Serial1.print(3);         //SEND MESSAGE FROM ROW 1 TO 4 
    Serial1.print(left_x);    // WHAT TO DISPLAY
    Serial1.write(0x03);      // STOP BIT
    //LEFTY JOYSTICK
    Serial1.write(0x02);      
    Serial1.print(">");     
    Serial1.print(3);
    Serial1.write(0x03);   

    Serial1.write(0x02);
    Serial1.print(4);   
    Serial1.print(left_y);
    Serial1.write(0x03);

    //RIGHTX JOYSTICK
    Serial1.write(0x02);     
    Serial1.print(">");      

    Serial1.print(12);
    Serial1.write(0x03);  

    Serial1.write(0x02);
    Serial1.print(3);    
    Serial1.print(right_x);
    Serial1.write(0x03);

    //RIGHTY JOYSTICK
    Serial1.write(0x02);     
    Serial1.print(">");    
    Serial1.print(12);
    Serial1.write(0x03); 

    Serial1.write(0x02);
    Serial1.print(4);    
    Serial1.print(right_y);
    Serial1.write(0x03);

    valx0 = controller.rightx;
    val0 = map(valx0, 128, 255, 90, 170);
    myservo1.write(val0);
    valy0 = controller.righty;
    val1 = map(valy0, 128, 255, 90, 160);
    myservo2.write(val1);

    //LEFT JOYSTICK
    if(controller.lefty == 0){
      Serial1.write(0x02);      // START BIT
      Serial1.print(">");       
      Serial1.print(9);         // SEND MESSAGE FROM LINES 1 TO 20
      Serial1.write(0x03);      // STOP BIT

      Serial1.write(0x02);      // START BIT
      Serial1.print(1);         //SEND MESSAGE FROM ROW 1 TO 4 
      Serial1.print("FORWARD");    // WHAT TO DISPLAY
      Serial1.write(0x03);      // STOP BIT 
      GO_FORWARD ();
    }
    else if(controller.leftx == 0){
      Serial1.write(0x02);      // START BIT
      Serial1.print(">");       
      Serial1.print(9);         // SEND MESSAGE FROM LINES 1 TO 20
      Serial1.write(0x03);      // STOP BIT

      Serial1.write(0x02);      // START BIT
      Serial1.print(1);         //SEND MESSAGE FROM ROW 1 TO 4 
      Serial1.print("LEFT");    // WHAT TO DISPLAY
      Serial1.write(0x03);      // STOP BIT
      SPIN_LEFT();
    }
    else if(controller.lefty == 255){
      Serial1.write(0x02);      // START BIT
      Serial1.print(">");       
      Serial1.print(9);         // SEND MESSAGE FROM LINES 1 TO 20
      Serial1.write(0x03);      // STOP BIT

      Serial1.write(0x02);      // START BIT
      Serial1.print(1);         //SEND MESSAGE FROM ROW 1 TO 4 
      Serial1.print("BACKWARD");    // WHAT TO DISPLAY
      Serial1.write(0x03);      // STOP BIT
      GO_BACKWARD ();      
    }
    else if(controller.leftx == 255){
      Serial1.write(0x02);      // START BIT
      Serial1.print(">");       
      Serial1.print(9);         // SEND MESSAGE FROM LINES 1 TO 20
      Serial1.write(0x03);      // STOP BIT

      Serial1.write(0x02);      // START BIT
      Serial1.print(1);         //SEND MESSAGE FROM ROW 1 TO 4 
      Serial1.print("RIGHT");    // WHAT TO DISPLAY
      Serial1.write(0x03);      // STOP BIT
      SPIN_RIGHT();
    }
    //***************************************
    //     UP,DOWN,LEFT,RIGHT FUNCTION
    //***************************************
    // UP
    else if(controller.up==true){ 
      Serial1.write(0x02);   
      Serial1.print(">");    
      Serial1.print(9);
      Serial1.write(0x03);

      Serial1.write(0x02);
      Serial1.print(1);    
      Serial1.print("FORWARD      ");
      Serial1.write(0x03);
      CLR = true;
      GO_FORWARD ();      
    }
    // DOWN
    else if(controller.down==true){ 
      Serial1.write(0x02);    
      Serial1.print(">");  
      Serial1.print(9);
      Serial1.write(0x03); 

      Serial1.write(0x02);
      Serial1.print(1); 
      Serial1.print("BACKWARD    ");
      Serial1.write(0x03);
      CLR = true;
      GO_BACKWARD ();
    }
    // LEFT    
    else if(controller.left==true){
      Serial1.write(0x02);    
      Serial1.print(">");    
      Serial1.print(9);
      Serial1.write(0x03);   

      Serial1.write(0x02);
      Serial1.print(1);   
      Serial1.print("LEFT    ");
      Serial1.write(0x03);
      CLR = true;
      SPIN_LEFT();
    }
    // RIGHT    
    else if(controller.right==true){
      Serial1.write(0x02);     
      Serial1.print(">");     
      Serial1.print(9);
      Serial1.write(0x03); 

      Serial1.write(0x02);
      Serial1.print(1);   
      Serial1.print("RIGHT   ");
      Serial1.write(0x03);
      CLR = true;
      SPIN_RIGHT();
    }
    //***************************************
    //          SHAPES FUNCTION
    //***************************************    
    // TRIANGLE    
    else if(controller.triangle==true){ 
      Serial1.write(0x02);     
      Serial1.print(">");    
      Serial1.print(9);
      Serial1.write(0x03);  

      Serial1.write(0x02);
      Serial1.print(1);  
      Serial1.print("TRIANGLE");
      Serial1.write(0x03);
      CLR = true;
      digitalWrite(27,HIGH);
    }
    // CIRCLE    
    else if(controller.circle==true){
      Serial1.write(0x02);  
      Serial1.print(">");  
      Serial1.print(9);
      Serial1.write(0x03);  

      Serial1.write(0x02);
      Serial1.print(1);   
      Serial1.print("CIRCLE  ");
      Serial1.write(0x03);
      CLR = true;
      digitalWrite(26,HIGH);
    }
    // SQUARE    
    else if(controller.square==true){  
      Serial1.write(0x02);      
      Serial1.print(">");    
      Serial1.print(9);
      Serial1.write(0x03); 

      Serial1.write(0x02);
      Serial1.print(1);   
      Serial1.print("SQUARE  ");
      Serial1.write(0x03);
      CLR = true;
      digitalWrite(23,HIGH);
    }
    // CROSS   
    else if(controller.cross==true){ 
      Serial1.write(0x02);      
      Serial1.print(">");     
      Serial1.print(9);
      Serial1.write(0x03); 

      Serial1.write(0x02);
      Serial1.print(1);  
      Serial1.print("CROSS   ");
      Serial1.write(0x03);
      CLR = true;
      digitalWrite(22,HIGH);
    }
    //***************************************
    //         L1,L2,R1,R2 FUNCTION
    //***************************************    
    // LEFT1    
    else if(controller.left1==true && button_latch_L1 == 0){  
      Serial1.write(0x02);     
      Serial1.print(">");   
      Serial1.print(10);
      Serial1.write(0x03);   

      Serial1.write(0x02);
      Serial1.print(1);    
      Serial1.print("ON1");
      Serial1.write(0x03);
      CLR = true;
      button_latch_L1 = 1;
      delay (500);      
      LIGHT_ON1 ();
    }
    else if(controller.left1==true && button_latch_L1 == 1){  
      Serial1.write(0x02);     
      Serial1.print(">");   
      Serial1.print(10);
      Serial1.write(0x03);   

      Serial1.write(0x02);
      Serial1.print(1);    
      Serial1.print("OFF1");
      Serial1.write(0x03);
      CLR = true;
      button_latch_L1 = 0;
      delay (500);
      LIGHT_OFF1 ();
    }
    // LEFT2    
    else if(controller.right1==true && button_latch_L2 == 0){ 
      Serial1.write(0x02);   
      Serial1.print(">");    
      Serial1.print(9);
      Serial1.write(0x03); 

      Serial1.write(0x02);
      Serial1.print(1);    
      Serial1.print("ON2");
      Serial1.write(0x03);
      CLR = true;
      button_latch_L2 = 1;
      delay (500);      
      LIGHT_ON2 ();
    }
    else if(controller.right1==true && button_latch_L2 == 1){ 
      Serial1.write(0x02);   
      Serial1.print(">");    
      Serial1.print(9);
      Serial1.write(0x03); 

      Serial1.write(0x02);
      Serial1.print(1);    
      Serial1.print("OFF2");
      Serial1.write(0x03);
      CLR = true;
      button_latch_L2 = 0;
      delay (500);      
      LIGHT_OFF2 ();
    }
    // RIGHT1    
    else if(controller.left2==true){  
      Serial1.write(0x02);      
      Serial1.print(">");     
      Serial1.print(9);
      Serial1.write(0x03);   

      Serial1.write(0x02);
      Serial1.print(1);  
      Serial1.print("RIGHT1  ");
      Serial1.write(0x03);
      CLR = true;
      digitalWrite(29,HIGH);
    }
    // RIGHT2    
    else if(controller.right2==true){ 
      Serial1.write(0x02);    
      Serial1.print(">");      
      Serial1.print(9);
      Serial1.write(0x03);   

      Serial1.write(0x02);
      Serial1.print(1);    
      Serial1.print("RIGHT2  ");
      Serial1.write(0x03);
      CLR = true;
      digitalWrite(28,HIGH);
    }
    //***************************************
    //      START,MODE,SELECT FUNCTION
    //***************************************    
    // START    
    else if(controller.start==true){  
      Serial1.write(0x02);     
      Serial1.print(">");     
      Serial1.print(9);
      Serial1.write(0x03);   

      Serial1.write(0x02);
      Serial1.print(1);  
      Serial1.print("START   ");
      Serial1.write(0x03);
      CLR = true;
    }
    // CLEAR
    else if(CLR == true){
      Serial1.write(0x02);     
      Serial1.print(">");      
      Serial1.print(9);
      Serial1.write(0x03);  

      Serial1.write(0x02);
      Serial1.print(1);  
      Serial1.print("        ");
      Serial1.write(0x03);
      STOP ();
      // SHAPES BUTTON ALL OFF
      digitalWrite(29,LOW); 
      digitalWrite(28,LOW); 
      digitalWrite(27,LOW); 
      digitalWrite(26,LOW); 
      // R1,R2 ALL OFF
      digitalWrite(23,LOW);
      digitalWrite(22,LOW);  
    }
  }
}
//***************************************************************************************************
//                              PRESET FUNCTIONS,MOTOR ROUTINE
//***************************************************************************************************
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
void STOP (){
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
void LIGHT_ON1 (){
  digitalWrite(31,HIGH);
}
void LIGHT_OFF1 (){
  digitalWrite(31,LOW); 
}
void LIGHT_ON2 (){
  digitalWrite(30,HIGH);
}
void LIGHT_OFF2 (){
  digitalWrite(30,LOW);
}
//***************************************************************************************************
//                      DO NOT MODIFY ANY OF THIS LINE BELOW (SERIAL EVENT)
//***************************************************************************************************
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
//***************************************************************************************************
//                      DO NOT MODIFY ANY OF THIS LINE BELOW (PS2 CONTROLLER)
//***************************************************************************************************
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
//***************************************************************************************************
//                    DO NOT MODIFY ANY OF THIS LINE BELOW (SERIAL LCD II)
//***************************************************************************************************
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
//***************************************************************************************************
//                             PROGRAM ENDS HERE AND LOOP FOREVER
//***************************************************************************************************





