#include <ATX2.h>

void lf()
{
  motor(1,100);
  motor(2,100);
  motor(3,-50);
  motor(4,-50);
}

void st()
{
  motor(1,0);
  motor(2,0);
  motor(3,0);
  motor(4,0);
}
  

void setup()
{
  OK();// Wait for OK button
  pinMode(30, INPUT);
  Serial.begin(9600);
}

void loop()
{
   int L = digitalRead(30);
   Serial.println(L);
   if (L <=300)
   {
     st();
   }
   
   else if (L>= 350)
   {
     lf();
     delay(100);
   }
}
