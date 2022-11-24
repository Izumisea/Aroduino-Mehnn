#include <ATX2.h>
#define SERVO_SIG_PIN  (3)
#define WEST_POS       (10)
#define NORTH_POS      (90)
#define EAST_POS       (180)
#define SERVO_DEL      delay(1000)

void setup()
{
  OK();// Wait for OK button

}

void loop()
{  
  glcdClear();
  servo(SERVO_SIG_PIN, NORTH_POS);
  glcd(2,1, "NORTH Position");
  SERVO_DEL;
  //
  glcdClear();
  servo(SERVO_SIG_PIN, WEST_POS);
  glcd(2,1, "WEST Position");
  SERVO_DEL;
  //
  glcdClear();
  servo(SERVO_SIG_PIN, NORTH_POS);
  glcd(2,1, "NORTH Position");
  SERVO_DEL;
  //
  glcdClear();
  servo(SERVO_SIG_PIN, EAST_POS);
  glcd(2,1, "EAST Position");
  SERVO_DEL;
}
