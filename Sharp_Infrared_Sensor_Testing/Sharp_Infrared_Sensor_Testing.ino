//Sharp Infrared Sensor Testing
//To view the reading, select Serial Monitor. (magnifying glass icon)

//Define sensor and things
const int IRA = 1; //infrared sensor A
const int IRB = 2; //infrared sensor B
const int IRC = 3; //infrared sensor C
const int RedPin =  7; //LED Color Red (optional)
const int GreenPin =  6; //LED Color Greed (optional)
const int Buzzer = 5; //Buzzer(optional)

int valueA;
int valueB;
int valueC;

void ProtocolA(){
  digitalWrite(RedPin, HIGH);
  digitalWrite(GreenPin, LOW); 
}
void ProtocolB(){
  digitalWrite(RedPin, HIGH);
  digitalWrite(GreenPin, LOW); 
}
void ProtocolC(){
  digitalWrite(RedPin, HIGH);
  digitalWrite(GreenPin, LOW); 
}



void setup() {
  // put your setup code here, to run once:
  pinMode(IRA, INPUT);
  pinMode(IRB, INPUT);
  pinMode(IRC, INPUT);
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  valueA=digitalRead(IRA); 
  valueB=digitalRead(IRB);
  valueC=digitalRead(IRC);  

  //Open Serial Monitor To See Value
  Serial.print("IRA Value: ");
  Serial.print(valueA);
  Serial.print(" | IRB Value: ");
  Serial.print(valueB);
  Serial.print(" | IRC Value: ");
  Serial.println(valueC);
  delay(100);
  
}
