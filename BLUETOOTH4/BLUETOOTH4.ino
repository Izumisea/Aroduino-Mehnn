#include <ATX2.h>
#define SERVO  (3)
#define SERVO_SIG_PIN2  (2)
#define SERVO_SIG_PIN  (1)
#define WEST_POS       (10)
#define NORTH_POS      (90)
#define EAST_POS       (120)
#define EAST_POS2       (170)
#define NORTH_POS2      (70)
#define NORTH_POS3      (30)
byte x;

void f()
{
motor(1, 80);
motor(3, 80);
motor(4, 80);

}
void b()
{
motor(1, -80);
motor(3, -80);
motor(4, -80);

}
void l()
{
motor(1, 80);
motor(3, -50);
motor(4, -50);

}
void r()
{
motor(1, -50);
motor(3, 80);
motor(4, 80);

}
void water()
{
motor(2, 75);

}
void _stop()
{
motor(1, 0);
motor(2, 0);
motor(3, 0);
motor(4, 0);
motor(5, 0);
servo(SERVO_SIG_PIN, EAST_POS);
servo(SERVO_SIG_PIN2, EAST_POS2);
servo(SERVO,  EAST_POS2 );
}
void setup()
{
  XIO(); // Initialize
   pinMode(2,INPUT_PULLUP);
}

void loop()
{  
  if(uart1_available())                // Get the serial command from UART1
  {                                    
    x=uart1_getkey();
      
    if(x==0x38)
    {
  glcdClear();
  f();
  glcd(2,1, "FORWARD");
    }
   else if(x==0x32)
   {
  glcdClear();
  b();
  glcd(2,1, "BACKWARD");
   }
  else if(x==0x34)
  {
  glcdClear();
  r();
  glcd(2,1,"LEFT");
  }
  else if(x==0x36)
  {
  glcdClear();
  l();
  glcd(2,1,"LEFT");
  }
  else if(x==0x44)
  {
  glcdClear();
  water();
  glcd(2,1,"WATER");
  }
  else if(x==0x42)
  {
  glcdClear();
  _stop();
  glcd(2,1,"stop");
  }
  else if(x==0x45)
  {
 glcdClear();
  servo(SERVO_SIG_PIN,NORTH_POS);
  servo(SERVO,NORTH_POS3 );
  glcd(2,1, "EAST Position");
  }
 else if(x==0x46)
  {
 glcdClear();
  servo(SERVO_SIG_PIN2, NORTH_POS2 );
  glcd(2,1, "EAST Position");
  }
 
  }
}
