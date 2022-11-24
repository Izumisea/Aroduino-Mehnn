

void f()
{
  motor(12,25);
  motor(34,25);
}

void b()
{
  motor(12,-50);
  motor(34,-50);
}

void l()
{
  motor(12,100);
  motor(34,-75);
}

void r()
{
  motor(12,-75);
  motor(34,100);
}


void setup()
{
  OK();// Wait for OK button
  delay(3000);
}

void loop()
{
  int TR = digitalRead(A4);
  int TB = digitalRead(A6);
  int TL = digitalRead(A7);
  int F = analogRead(A5);
  int L = analogRead(A2);
  int R = analogRead(A0);
  
 if(TR == 1 && TL ==1)
  {
    f();
  }
  
    else if(TR == 0 & TL ==0)
  {
    b();
    delay(300);
    r();
    delay(200);
  }
  
  if(TB == 1)
  {
    motor(12,25);
    motor(34,25);
  }
  else
  {
    motor(12,35);
    motor(34,35);
  }
  
  if (F>= 200)
  {
    motor(12,75);
    motor(34,75);
    delay(100);
  }
  
  else if(L>= 350)
  {
    l();
    delay(100);
  }
    
  else if(R>= 350)
  {
    r();
    delay(100);
  }
  
  else if(TR == 1 && TL ==0)
  {
    b();
    delay(300);
    r();
    delay(200);
  }
  
  else if(TR == 0 && TL ==1)
  {
    b();
    delay(300);
    l();
    delay(200);
  }
}
  
  
