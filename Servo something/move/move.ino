#include <ATX2.h>

void push()
{
  motor(1,-50);
  motor(2,-50);
  motor(3,100);
  motor(4,100);
}

void push3()
{
  motor(1,100);
  motor(2,100);
  motor(3,-50);
  motor(4,-50);
}

void push2()
{
  motor(1,100);
  motor(2,100);
  motor(3,100);
  motor(4,100);
}

void tp ()
{
  motor(1,0);
  motor(2,0);
  motor(3,0);
  motor(4,0);
}


void setup()
{
  OK();// Wait for OK button
  pinMode(24, INPUT);
}

void loop()
{
  int F = analogRead(24);
  
  if(F <= 300)
  {
    tp();
  } 
  
  if (F>= 350)
  {
    push();
    delay(100);
    push2();
    delay(200);
    push3();
    delay(200);
  }
}
