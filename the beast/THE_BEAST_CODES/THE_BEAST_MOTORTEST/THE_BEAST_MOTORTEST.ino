#include <eGizmo_PBOT2018.h>

//*********************************************//
//            THE BEAST BLUETOOTH              //
//                                             //
//     This enables you to controls the tank   //
//            basic routine,ff,rev             //
//                 Codes by:                   //
//        e-Gizmo Mechatronix Central          //
//         Taft, Manila, Philippines           //
//           http://www.egizmo.com             //
//                dec 8,2016                   //
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
#define PH_MOTOR_2_DIRECTION              8
#define PWH_ON_SPEED_CONTROL_2            9
#define PWH_ON_SPEED_CONTROL_1            10
#define PH_MOTOR_1_DIRECTION              11

int PWH_ON_SPEED_CONTROL_VALUE = 255;
int STEERING_SPEED = 255;
int PAUSE = 200;

//------------------------------------------------------------------------------------------------------------------------
// INPUTS AND OUTPUTS:
void setup(){
  Serial.begin(9600);

  pinMode(PH_MOTOR_1_DIRECTION,OUTPUT);
  pinMode(PH_MOTOR_2_DIRECTION ,OUTPUT);
  pinMode(PWH_ON_SPEED_CONTROL_1,OUTPUT);
  pinMode(PWH_ON_SPEED_CONTROL_2,OUTPUT);

  digitalWrite(PH_MOTOR_1_DIRECTION,HIGH);
  digitalWrite(PH_MOTOR_2_DIRECTION,HIGH);

 
}
//------------------------------------------------------------------------------------------------------------------------
// MAIN PROGRAM:
void loop(){
    GO_FORWARD ();
    delay (500);
        GO_STOP ();
    GO_BACKWARD ();
    delay (500);
        GO_STOP ();
    SPIN_LEFT();
    delay (500);
        GO_STOP ();
    SPIN_RIGHT();
    delay (500);    
    GO_STOP ();
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
