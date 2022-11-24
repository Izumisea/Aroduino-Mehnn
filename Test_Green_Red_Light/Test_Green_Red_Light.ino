const int trigPin = 9;
const int echoPin = 10;
const int RedPin =  7;  
const int GreenPin =  6;  
// defines variables
long duration;
int distance;
void setup() {
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  Serial.begin(9600); 
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance <= 30){
    digitalWrite(RedPin, HIGH);
    digitalWrite(GreenPin, LOW);
  }else{
    digitalWrite(RedPin, LOW);
    digitalWrite(GreenPin, HIGH);
  }
}
