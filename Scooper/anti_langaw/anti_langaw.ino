
#include <Servo.h> 
// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

Servo myservoY;
Servo myservoZ;
Servo Eye;

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

   myservoZ.attach(7);
  myservoY.attach(6);
   Eye.attach(5);

}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  if(sensorValue >= 600){
    myservoZ.writeMicroseconds(1000); 
    myservoY.writeMicroseconds(1000);
    delay(1000);
    myservoZ.writeMicroseconds(2000); 
    myservoY.writeMicroseconds(2000);
    delay(1000);
    myservoZ.writeMicroseconds(1000); 
    myservoY.writeMicroseconds(1000);
    delay(1000);
    myservoZ.writeMicroseconds(2000); 
    myservoY.writeMicroseconds(2000);
    delay(1000);
        myservoZ.writeMicroseconds(1000); 
    myservoY.writeMicroseconds(1000);
    delay(1000);
    myservoZ.writeMicroseconds(2000); 
    myservoY.writeMicroseconds(2000);
  }else {
     Eye.writeMicroseconds(2000);
     delay(1000);
     Eye.writeMicroseconds(1000);
      delay(1000);
    }
  

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
   
}
