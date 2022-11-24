#include <ATX2.h>
#define SERVO_SIG_PIN (1)
#define MIN_ANGLE     (0)
#define MAX_ANGLE     (180)
#define DISP_DEL      delay(2000)
#define SERVO_DEL     delay(5)

void setup()
{
  OK();// Wait for OK button
  servo (SERVO_SIG_PIN, MIN_ANGLE);
  dispIntro();
  DISP_DEL;
}

void loop()
{
  setupDisplay();
  turnClockwise();
  turnCounterClockwise();
}
void dispIntro(){
   glcdClear();
   setTextSize(2);
   setTextColor(GLCD_GREEN);
   glcd(0,1, "Automatic");
   glcd(1,1, "swivel");
   glcd(2,1, "servo motor");
   glcd(3,1, "in ATX-2");
   DISP_DEL;
}
//Definition of function for turning clockwise
void turnClockwise(){
   for (int servo_angle = MIN_ANGLE; servo_angle <= MAX_ANGLE; servo_angle = servo_angle + 10){
     servo(SERVO_SIG_PIN, servo_angle);
     glcd(0,1, "Servo is");
     glcd(1,1, "Turning in");
     glcd(2,1, "CW Rotation");
     glcd(3,1, "Current Pos=");
     glcd(4,1, "%d", servo_angle);
   }
}
//Definition of function for turning counter-clockwise
void turnCounterClockwise(){
   for (int servo_angle = MAX_ANGLE; servo_angle >= MIN_ANGLE; servo_angle = servo_angle - 10){
     servo(SERVO_SIG_PIN, servo_angle);
     glcd(0,1, "Servo is");
     glcd(1,1, "Turning in");
     glcd(2,1, "CCW Rotation");
     glcd(3,1, "Current Pos");
     glcd(4,1, "%d", servo_angle);
   }
}
//Definition of function in order to set-up the display
void setupDisplay(){
  glcdClear();
  setTextSize(2);
  glcdFillScreen(GLCD_MAGENTA);
  setTextBackgroundColor(GLCD_MAGENTA);
  setTextColor(GLCD_WHITE); 
}
