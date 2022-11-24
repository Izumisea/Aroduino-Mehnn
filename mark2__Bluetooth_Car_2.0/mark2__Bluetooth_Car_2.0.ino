// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;
// motor tree
int enC = 14;
int in5 = 15;
int in6 = 16;
// motor four
int enD = 19;
int in7 = 18;
int in8 = 17;

char t;

void forward ()
{
  // side R
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);
  //side L
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enC, 200);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  analogWrite(enD, 200);
}

void backward ()
{
  // side R
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 100);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 100);
  //side L
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enC, 100);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  analogWrite(enD, 100);
}

void right ()
{
  // side R
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 125);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 125);
  //side L
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enC, 200);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  analogWrite(enD, 200);
}

void left ()
{
 // side R
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);
  //side L
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enC, 125);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  analogWrite(enD, 125);
}

void Stop ()
{
  //side R
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
  //side L
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  analogWrite(enC, 0);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
  analogWrite(enD, 0);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  


  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()){    
  t = Serial.read();
  Serial.println(t);
  }
   if(t == 'F')
   {            
  forward();
 }
  if(t == 'B')
  {            
  backward();  
 }
  if(t == 'L')
  {            
  left();
 }
  if(t == 'R')
  {            
  right();
 }
  if(t == 'S')
  {            
  Stop();
 }
}
