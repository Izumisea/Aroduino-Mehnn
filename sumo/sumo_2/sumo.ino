

void f()
{
  motor(52, 30);
  motor(36, 30);
}

void b()
{
   motor(52, -60);
  motor(36, -60);
}

void l()
{
  motor(52,65);
  motor(36,55);
}

void r()
{
  motor(52,60);
  motor(36,85);
}


void setup()
{
  OK();// Wait for OK 
  delay(4800);
}

void loop()
{
  int TR = digitalRead(A1);
  int TL = digitalRead(A0);
  int F = analogRead(A2);
  int L = analogRead(A3);
  int R = analogRead(A4);
  
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
  
  
  if (F>= 500)
  {
    motor(12,100);
    motor(34,100);
  }
  
  else if(L>= 500)
  {
    l();
    delay(100);
  }
    
  else if(R>= 500)
  {
    r();
    delay(100);
  }
}
