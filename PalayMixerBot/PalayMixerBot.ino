
char t;
 
void setup() {
pinMode(9,OUTPUT);   //left motors forward
pinMode(10,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(12,OUTPUT);   //right motors reverse
 
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'a'){            //move forward(all motors rotate in forward direction)
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
}
 
else if(t == 'e'){      //STOP (all motors stop)
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
}
 
else if(t == 'd'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
}
 
else if(t == 'b'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
}
 
delay(100);
}
