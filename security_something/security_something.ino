//Define RFID
#include <SPI.h>
#include <RFID.h>
#define SS_PIN 10
#define RST_PIN 9
RFID rfid(SS_PIN, RST_PIN);
String rfidCard;

char student1 = "35 99 154 23"


//Define sensor and things
const int IRA = 1; //infrared sensor A
const int IRB = 2; //infrared sensor B
const int IRC = 3; //infrared sensor C
const int RedPin =  7; //LED Color Red 
const int GreenPin =  6; //LED Color Greed
const int Buzzer = 5; //Buzzer

int valueA;
int valueB;
int valueC;

//alarm buzzer 4 times
void Alarm(){
  digitalWrite(Buzzer, HIGH);
  delay(300);
  digitalWrite(Buzzer, LOW);
  delay(300);
  digitalWrite(Buzzer, HIGH);
  delay(300);
  digitalWrite(Buzzer, LOW);
  delay(300);
  digitalWrite(Buzzer, HIGH);
  delay(300);
  digitalWrite(Buzzer, LOW);
  delay(300);
  digitalWrite(Buzzer, HIGH);
  delay(300);
  digitalWrite(Buzzer, LOW);
  delay(300);
}
//Free To Go
void Entering(){
  digitalWrite(RedPin, LOW);
  digitalWrite(GreenPin, HIGH); 
}
//Emergency Mode
void Emergency(){
  digitalWrite(RedPin, HIGH);
  digitalWrite(GreenPin, LOW); 
  Alarm();
}



void setup() {
  // put your setup code here, to run once:
  SPI.begin();
  rfid.init();
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
  
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      rfidCard = String(rfid.serNum[0]) + " " + String(rfid.serNum[1]) + " " + String(rfid.serNum[2]) + " " + String(rfid.serNum[3]);

      if (Serial.available()  > 0) {
        char rfidshit = Serial.read();

        switch (rfidshit){
          
        }
      }

      
        
      
     
    }
    rfid.halt();
  }
  
        Serial.print("IRA Value: ");
        Serial.print(valueA);
        Serial.print(" | IRB Value: ");
        Serial.print(valueB);
        Serial.print(" | IRC Value: ");
        Serial.print(valueC);
        Serial.print(" | RFID Value: ");
        Serial.println(rfidCard);
        delay(100);
  
  
}
if(rfidCard == "35 99 154 23"){
        Entering();
      }else{
        
