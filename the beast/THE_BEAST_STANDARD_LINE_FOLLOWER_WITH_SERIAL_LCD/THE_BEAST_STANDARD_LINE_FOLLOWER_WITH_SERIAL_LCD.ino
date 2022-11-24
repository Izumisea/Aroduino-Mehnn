//*********************************************//
//                 THE BEAST                   //
//               LINE FOLLOWER                 //
//  enables BEAST to FOLLOW BLACK/WHITE line   //
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
#define MOTOR_RIGHT_DIRECTION       11       // Motor control HIGH = FWD, LOW = BWD
#define MOTOR_RIGHT_SPEED           10       // Speed input
#define MOTOR_LEFT_SPEED            9        // Speed input
#define MOTOR_LEFT_DIRECTION        8        // Motor control HIGH = FWD, LOW = BWD

#define LEFT_LINE_SENSOR          7       // Line sensor left 
#define CENTER_LINE_SENSOR        6       // Line sensor center
#define RIGHT_LINE_SENSOR         5       // Line sensor right

// VARIABLES
long int RTC;
int  LINE_SENSE=0;
int GIVE_UP=0;
int LAST_SENSE;
int RUN_SPEED=210;                // Keep 210 maximum value for the runspeed

// TIMERS
byte  RETRY_DELAY=0;
byte  LED_FLASH=25;

char  rxmsg[30];
byte stage;
byte rxctr;
byte  msg;
//------------------------------------------------------------------------------------------------------------------------
// INPUTS AND OUTPUTS
void setup() {                
  Serial.begin(9600);
  Serial1.begin(9600);
  delay(2000);
  
  Send_Command("F");
  Send_Command("c"); 
  Send_To("1","e-Gizmo","6");
  Send_To("2","THE BEAST","5");
  Send_To("3","LINE FOLLOWER","3");
  delay(2000);
  
  // DEFAULT PINS OF THE MOTOR DRIVER (8,9,10,11)
  pinMode(MOTOR_RIGHT_DIRECTION, OUTPUT);       
  pinMode(MOTOR_RIGHT_SPEED, OUTPUT);
  pinMode(MOTOR_LEFT_SPEED, OUTPUT);
  pinMode(MOTOR_LEFT_DIRECTION, OUTPUT);

  pinMode(LEFT_LINE_SENSOR, INPUT);   
  pinMode(CENTER_LINE_SENSOR, INPUT);
  pinMode(RIGHT_LINE_SENSOR, INPUT);
  RTC=millis()+10;


}
//------------------------------------------------------------------------------------------------------------------------
// MAIN PROGRAM
void loop()                     
{
  // HARDWARE TIMER SERVICE
  if(millis()>=RTC)
  {
    RTC=RTC+10;
    if(RETRY_DELAY>0) RETRY_DELAY--;
    if(LED_FLASH>0)
    {
      LED_FLASH--;
      if(LED_FLASH==0)
      {
        LED_FLASH=25;
        PORTB ^= 0x20;
      }
    }        
  }      
  // READ THE STATUS OF THE LINE SENSOR
  LINE_SENSE=0;
  if(digitalRead(LEFT_LINE_SENSOR)==LOW) LINE_SENSE=1;
  if(digitalRead(CENTER_LINE_SENSOR)==LOW) LINE_SENSE=LINE_SENSE+2;
  if(digitalRead(RIGHT_LINE_SENSOR)==LOW) LINE_SENSE=LINE_SENSE+4;

  // IF NO LINES ARE DETECTED
  if((LINE_SENSE==0) & (RETRY_DELAY==0))
  {
    if(GIVE_UP<10)
    {
      // REVERSE FOR 20MS
      if(LAST_SENSE==1) RUN_BOT(RUN_SPEED*15/10,RUN_SPEED,LOW);
      if(LAST_SENSE==3) RUN_BOT(RUN_SPEED*12/10,RUN_SPEED,LOW);
      if(LAST_SENSE==4) RUN_BOT(RUN_SPEED,RUN_SPEED*15/10,LOW);
      if(LAST_SENSE==6) RUN_BOT(RUN_SPEED,RUN_SPEED*12/10,LOW);
      delay(40);
      GIVE_UP++;
    }
    else
      STOP();
  }
  // IF LINE IS DETECTED
  if(LINE_SENSE!=7)
  {
    LAST_SENSE=LINE_SENSE;
    GIVE_UP=0;
    RETRY_DELAY=50;
  }
  // EXTREME LEFT
  if(LINE_SENSE==6)
  {
    FORWARD();
    analogWrite(MOTOR_RIGHT_SPEED, RUN_SPEED);
    analogWrite(MOTOR_LEFT_SPEED, 0);
    delay(50);
  }
  // CENTER LINE
  if((LINE_SENSE==5)|(LINE_SENSE==0))
  {
    RUN_BOT(RUN_SPEED,RUN_SPEED,HIGH);
    delay(50);
  }      
  // TURN LEFT
  if(LINE_SENSE==4)
  {
    STOP();
    FORWARD();
    analogWrite(MOTOR_RIGHT_SPEED, RUN_SPEED*12/10);
    delay(50);
  }
  // EXTREME RIGHT
  if(LINE_SENSE==3)
  {
    FORWARD();
    analogWrite(MOTOR_LEFT_SPEED, RUN_SPEED);
    analogWrite(MOTOR_RIGHT_SPEED, 0);
    delay(50);
  }
  // TURN RIGHT
  if(LINE_SENSE==1)
  {
    STOP();
    FORWARD();
    analogWrite(MOTOR_LEFT_SPEED, RUN_SPEED*12/10);
    delay(50);
  }
}

void RUN_BOT(int spd1,int spd2, boolean direction )
{
  digitalWrite(MOTOR_RIGHT_DIRECTION,direction);
  digitalWrite(MOTOR_LEFT_DIRECTION,direction);
  analogWrite(MOTOR_LEFT_SPEED, spd1);
  analogWrite(MOTOR_RIGHT_SPEED, spd2); 
}

void FORWARD(void)
{
  digitalWrite(MOTOR_RIGHT_DIRECTION,HIGH);
  digitalWrite(MOTOR_LEFT_DIRECTION,HIGH);
}    

void ROTATE_BOT(int speed, boolean direction)
{
  digitalWrite(MOTOR_RIGHT_DIRECTION,direction);
  digitalWrite(MOTOR_LEFT_DIRECTION,~direction);
  analogWrite(MOTOR_RIGHT_SPEED, speed);
  analogWrite(MOTOR_LEFT_SPEED, speed); 
}

void STOP(void)
{
  analogWrite(MOTOR_RIGHT_SPEED, 0);
  analogWrite(MOTOR_LEFT_SPEED, 0); 
}
//------------------------------------------------------------------------------------------------------------------------
//Wait for EZ HMI response

void  wait_response(void){
  while(stage !=3) read_buffer();
}
/* This routine checks the serial input *
 * scans for the occurrence of STX and ETX *
 * and extract the message stripped of STX *
 * and ETX marker
 * Rx message in rxmsg[]
 * stage = 3 indicates RX complete
 */

void  read_buffer(void){
  if(Serial1.available()>0){
    char  rxchar=Serial1.read();  // Read one Rxed character
    if(stage==0){                // Look for STX
      if(rxchar==0x02){          // STX?
        stage=1;                // STX is found, stage 1
        return;
      }
    }
    if(stage==1){              // Store next Rx char until ETX is detected
      if(rxchar==0x03)        // ETX?
      {
        stage=3;              // ETX found, data ready=stage 3
        rxmsg[rxctr]=0;      // NULL String terminator
      }
      else
      {
        if(rxctr<30){      // collect data until ETX is found or buffer full
          rxmsg[rxctr]=rxchar;
          rxctr++;
        }
      }
    }

  }
}

/* This function sends the EZ HMI command
 *  wrapped in STX and ETX marker
 */

void Send_Command(char *message){
  Serial1.write(0x02);      //STX
  Serial1.print(message);
  Serial1.write(0x03);      //ETX
  stage=0;                 //Reset Rx buffer
  rxctr=0;
  wait_response();        // Wait until EZ HMI responds
}


/* Display Function with print start position
 *  line= which line to print to, 0 or 1
 *  message = message to print
 *  pos = print start position
 */

void Send_To(char *line,char *message,char *pos){

  String k=message;        // Save input string
  Serial1.write(0x02);      //STX
  Serial1.print(">");      // Send position info
  Serial1.print(pos);
  Serial1.write(0x03);    //ETX
  stage=0;
  rxctr=0;
  wait_response();

  Serial1.write(0x02); 
  Serial1.print(line);    // Send message to line
  Serial1.print(k);
  Serial1.write(0x03);
  stage=0;
  rxctr=0;
  wait_response();

}
void LCD_CLEAR()
{
  Send_Command("c");
}
// I/O service
void IO(char *message,int port){
  Serial1.write(0x02);      //STX
  Serial1.print(message);
  Serial1.print(port);
  Serial1.write(0x03);      //ETX
  stage=0;                 //Reset Rx buffer
  rxctr=0;
  wait_response();        // Wait until EZ HMI responds
}
// PROGRAM ENDS AND LOOP BACK FOREVER                                                                                                                                                   // PARZ

