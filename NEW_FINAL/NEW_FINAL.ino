
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

int green = 11;
int orange = 12;
char command; 

int fronts = A0;
int lefts = A1;
int rights = A2;
int pb = A3;
int brush = 24; 

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
pinMode(fronts,INPUT);
pinMode(lefts,INPUT);
pinMode(rights,INPUT);
pinMode(pb,INPUT);
pinMode(brush,OUTPUT); 

pinMode(green,OUTPUT);
pinMode(orange,OUTPUT);
Serial.begin(9500);  //Set the baud rate to your Bluetooth module.

}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 60);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 60);  

  digitalWrite(brush, HIGH);

}

void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 60);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 60); 
  
  digitalWrite(brush, HIGH);

}

void left() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 40);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 40);  

  digitalWrite(brush, HIGH);

}

void right() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 40);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 40);  

  digitalWrite(brush, HIGH);

}

void tigil() {
  digitalWrite(brush,LOW);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  digitalWrite(orange,HIGH);
  digitalWrite(green,LOW);

}

void hinto()
{
  digitalWrite(brush,LOW);
   
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  digitalWrite(orange,HIGH);
  digitalWrite(green,LOW);


}
void hinto2()
{
  digitalWrite(brush,LOW);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  digitalWrite(orange,HIGH);
  digitalWrite(green,LOW);

}
void autocar()
{
  int irleft = analogRead(lefts);
  int irright = analogRead(rights);
  int irfront = analogRead(fronts);

  
   if (irleft > 400)
  {
    digitalWrite(brush,LOW);

    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);  
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(500);
    digitalWrite(orange,HIGH);
    digitalWrite(green,LOW);
    delay(500);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 60);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 60);
    delay(1000);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 40);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 40);
    delay(500);

    digitalWrite(green,HIGH);
    digitalWrite(orange,LOW);


   }

 else if (irright > 400)
 {
    digitalWrite(brush,LOW);
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);  
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(500);    
    digitalWrite(orange,HIGH);
    digitalWrite(green,LOW);
    delay(500);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 60);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 60);
    delay(1000);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 40);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 40); 
    delay(500);

     digitalWrite(green,HIGH);
     digitalWrite(orange,LOW);

   }

 else if (irfront > 400)
 {
    digitalWrite(brush,LOW);

    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);  
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(500);
    digitalWrite(orange,HIGH);
    digitalWrite(green,HIGH);    
    delay(500);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 60);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 60);
    delay(1000);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 40);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 40);
    delay(500);


    digitalWrite(green,HIGH);
    digitalWrite(orange,LOW);
     
   }
   
 else
  {
  digitalWrite(brush,HIGH);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 60);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 60);
  digitalWrite(green,HIGH);

  }

  
  }


void loop() {
  
  int pbstate = digitalRead(pb);
  
   if(Serial.available() > 0){ 
    command = Serial.read(); 
    switch(command){
    case 'F':  
      digitalWrite(green,HIGH);
      digitalWrite(orange,LOW);
     
      digitalWrite(brush,HIGH);
      forward();
      break;
    case 'B':  
       digitalWrite(green,HIGH);
       digitalWrite(orange,LOW);
       digitalWrite(brush,HIGH);
       backward();
      break;
    case 'L':  
      digitalWrite(green,HIGH);
      digitalWrite(orange,LOW);
      digitalWrite(brush,HIGH);
      left();
      break;
    case 'R':
      digitalWrite(green,HIGH);
      digitalWrite(orange,LOW);
      digitalWrite(brush,HIGH);
      right();
      break;
    case 'V':
      hinto();
      digitalWrite(brush,LOW);
      break;
    case 'v':
      hinto2();
      digitalWrite(brush,LOW);
      break;
    case 'w':
      hinto();
      digitalWrite(brush,LOW);
      break;
    
    }
  } 
  
    if (pbstate == LOW)
    {
      autocar();
     }


}


