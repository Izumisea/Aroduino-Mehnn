#include <ATX2.h>

#define TX_PULSE_PIN    (24)
#define RX_PULSE_PIN   (26)

#define LOW_PING_DEL  delayMicroseconds(2)
#define HIGH_PING_DEL  delayMicroseconds(10)

#define BAUD_RATE  (9600)
#define DISPLAY_DEL  delay(300)
#define DEC_PT     (2)

#define MICROSEC_TO_IN  ((float)microseconds /11.08)/ 2.00
#define MICROSEC_TO_CM   ((float)microseconds / 28.15) / 2.00


void generatedDigitalPulse()
{
  out(TX_PULSE_PIN, LOW);
  LOW_PING_DEL;
  out(TX_PULSE_PIN, HIGH);
  HIGH_PING_DEL;
  out(TX_PULSE_PIN, LOW);
}

float microsecondsToInches(long microseconds)
{
  return MICROSEC_TO_IN;
}

float microsecondsToCentimeters(long microseconds)
{
  return MICROSEC_TO_CM;
}
#define SERVO_SIG_PIN  (3)
#define WEST_POS       (10)
#define NORTH_POS      (90)
#define EAST_POS       (180)
#define SERVO_DEL      delay(1000)


void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(TX_PULSE_PIN, OUTPUT);
  pinMode(RX_PULSE_PIN, INPUT);
  OK();// Wait for OK button
}

void loop()
{
  
  long calc_time;
  float dist_inches, dist_cm;
  
  generatedDigitalPulse();
  
  calc_time = pulseIn(RX_PULSE_PIN, HIGH);
  
  dist_inches = microsecondsToInches(calc_time);
  
  dist_cm = microsecondsToCentimeters(calc_time);
  
  Serial.print("Calculate time: ");
  Serial.print("Calc_time:");
  Serial.println("microseconds");
  
  Serial.print("Distance in inches: ");
  Serial.print(dist_inches, DEC_PT);
  Serial.println("inches");
  
  Serial.print("Distance in centimeters: ");
  Serial.print(dist_cm);
  Serial.println(" cm");
  Serial.println();
  
  DISPLAY_DEL;
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

