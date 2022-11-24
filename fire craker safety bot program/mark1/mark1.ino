

#define PH_MOTOR_2_DIRECTION              8
#define PWH_ON_SPEED_CONTROL_2            9
#define PWH_ON_SPEED_CONTROL_1            10
#define PH_MOTOR_1_DIRECTION              11

int command;
int PWH_ON_SPEED_CONTROL_VALUE = 255;
int STEERING_SPEED = 255;
int PAUSE = 200;

void GO_FORWARD (){
  digitalWrite(PH_MOTOR_1_DIRECTION,HIGH);
  digitalWrite(PH_MOTOR_2_DIRECTION,HIGH);  
  analogWrite(PWH_ON_SPEED_CONTROL_1,PWH_ON_SPEED_CONTROL_VALUE);
  analogWrite(PWH_ON_SPEED_CONTROL_2,PWH_ON_SPEED_CONTROL_VALUE);
  delay(PAUSE);
}
void GO_BACKWARD (){
  digitalWrite(PH_MOTOR_1_DIRECTION,LOW);
  digitalWrite(PH_MOTOR_2_DIRECTION,LOW);  
  analogWrite(PWH_ON_SPEED_CONTROL_1,PWH_ON_SPEED_CONTROL_VALUE);
  analogWrite(PWH_ON_SPEED_CONTROL_2,PWH_ON_SPEED_CONTROL_VALUE);
  delay(PAUSE);
}
void GO_STOP (){
  analogWrite(PWH_ON_SPEED_CONTROL_1,0);
  analogWrite(PWH_ON_SPEED_CONTROL_2,0);
  delay(PAUSE);
}
void SPIN_LEFT (){
  digitalWrite(PH_MOTOR_1_DIRECTION,HIGH);
  digitalWrite(PH_MOTOR_2_DIRECTION,LOW);  
  analogWrite(PWH_ON_SPEED_CONTROL_1,STEERING_SPEED);
  analogWrite(PWH_ON_SPEED_CONTROL_2,STEERING_SPEED);
  delay(PAUSE);
}
void SPIN_RIGHT (){
  digitalWrite(PH_MOTOR_1_DIRECTION,LOW);
  digitalWrite(PH_MOTOR_2_DIRECTION,HIGH);  
  analogWrite(PWH_ON_SPEED_CONTROL_1,STEERING_SPEED);
  analogWrite(PWH_ON_SPEED_CONTROL_2,STEERING_SPEED);
  delay(PAUSE);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(PH_MOTOR_1_DIRECTION,OUTPUT);
  pinMode(PH_MOTOR_2_DIRECTION ,OUTPUT);
  pinMode(PWH_ON_SPEED_CONTROL_1,OUTPUT);
  pinMode(PWH_ON_SPEED_CONTROL_2,OUTPUT);

  digitalWrite(PH_MOTOR_1_DIRECTION,HIGH);
  digitalWrite(PH_MOTOR_2_DIRECTION,HIGH);

  digitalWrite(17,HIGH);
  digitalWrite(18,HIGH);
  digitalWrite(19,HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:
    if (Serial.available() > 0) {
    command = Serial.read();
    GO_STOP();
    switch (command) {
      case 'F':
        GO_FORWARD();
        break;
      case 'B':
        GO_BACKWARD();
        break;
      case 'L':
        SPIN_LEFT();
        break;
      case 'R':
        SPIN_RIGHT();
        break;
     }
   }
}
