#include <IRremote.h>
#include <IRremoteInt.h>

int RECV_PIN = 13;
IRrecv receiver(RECV_PIN);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  receiver.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(receiver.decode(&results))
  {
  Serial.println(results.value,HEX);
  receiver.resume();
  }
}
