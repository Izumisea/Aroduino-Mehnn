#include <ATX2.h>

void f()
{
  motor(12,40);
  motor(34,40);
}

void b()
{
  motor(12,-50);
  motor(34,-50);
}

void l()
{
  motor(12,100);
  motor(34,-50);
}

void r()
{
  motor(12,-50);
  motor(34,100);
}


void setup()
{
  OK();// Wait for OK button
}

void loop()
{
  int TR = digitalRead(A4);
  int TB = digitalRead(A6);
  int TL = digitalRead(A7);
  int F = analogRead(A3);
  int L = analogRead(A2);
  int R = analogRead(A0);
  
  if(TR == 0 & TL ==0)
  {
    b();
    delay(500);
    r();
    delay(250);
  }
  
  else if(TR == 1 && TL ==0)
  {
    b();
    delay(500);
    l();
    delay(250);
  }
  
  else if(TR == 0 && TL ==1)
  {
    b();
    delay(500);
    r();
    delay(250);
  }
  
  else if(TR == 1 && TL ==1)
  {
    f();
  }
  
  if(TB == 1)
  {
    motor(12,40);
    motor(34,40);
  }
  else
  {
    motor(12,75);
    motor(34,75);
  }
  
  if (F >=300)
  {
    motor(12,75);
    motor(34,75);
  }
  
  else 
  {
    motor(12,40);
    motor(34,40);
  }
  
  if(L <=300)
  {
    f();
  }
  
  else if(L>= 350)
  {
    l();
    delay(75);
  }
  
  if(R <=300)
  {
    f();
  }
  
  else if(R>= 350)
  {
    r();
    delay(75);
  }
  
}
