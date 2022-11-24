#include <ATX2.h>
#include <IRremote.h>

int RECV_PIN = 3;
bool _run = false;

IRrecv irrecv(RECV_PIN);

decode_results results;

void forward() {
  motor(1, 100);
  motor(2, 100);
  motor(3, 100);
  motor(4, 100);
}

void backward() {
  motor(1, -100);
  motor(2, -100);
  motor(3, -100);
  motor(4, -100);
}

void left() {
  motor(1, 100);
  motor(2, 100);
  motor(3, -50);
  motor(4, -50);
}

void right() {
  motor(1, -50);
  motor(2, -50);
  motor(3, 100);
  motor(4, 100);
}

void f() {
  motor(12, 40);
  motor(34, 40);
}

void b() {
  motor(12, -50);
  motor(34, -50);
}

void l() {
  motor(12, 100);
  motor(34, -50);
}

void r() {
  motor(12, -50);
  motor(34, 100);
}

void _stop() {
  motor(12, 0);
  motor(34, 0);
}

void sumo(int TR, int TB, int TL, int F, int L, int R) {
  if (TR == 0 & TL == 0) {
    b();
    delay(500);
    r();
    delay(250);
  } else if (TR == 1 && TL == 0) {
    b();
    delay(500);
    l();
    delay(250);
  } else if (TR == 0 && TL == 1) {
    b();
    delay(500);
    r();
    delay(250);
  } else if (TR == 1 && TL == 1) {
    f();
  }

  if (TB == 1) {
    motor(12, 40);
    motor(34, 40);
  } else {
    motor(12, 75);
    motor(34, 75);
  }

  if (F >= 300) {
    motor(12, 75);
    motor(34, 75);
  } else {
    motor(12, 40);
    motor(34, 40);
  }

  if (L <= 300) {
    f();
  } else if (L >= 350) {
    l();
    delay(75);
  }

  if (R <= 300) {
    f();
  } else if (R >= 350) {
    r();
    delay(75);
  }
}

void setup() {
  OK();// Wait for OK button
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  int TR = digitalRead(A4);
  int TB = digitalRead(A6);
  int TL = digitalRead(A7);
 
  int L = analogRead(A2);
  int R = analogRead(A0);

  if (irrecv.decode(&results)) {
    switch (results.value) {
    
     
   //   case F:
       forward();
        delay(100);
        _stop();
        break;
    //  case B:
        backward();
        delay(100);
        _stop();
        break;
   //  case L:
        left();
        delay(125);
       _stop();
        break;
    //  case R:
       right();
        delay(125);
        _stop();
       break;
     // case W:
        _stop();
        delay(100);
      default: Serial.println(results.value, HEX); break;
    }
    irrecv.resume(); // Receive the next value
  }

    if (_run) {
 //     sumo(TR, TB, TL, L, R);
    }
}
