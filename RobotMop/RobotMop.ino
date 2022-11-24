// Robot Mop
// 09/12/18

#include <Servo.h>
#define UP 180
#define DOWN 90
#define OBSTACLE_DISTANCE 6

//Button class
class Button {
  private:
    bool _state;
    uint8_t _pin;

  public:
    Button(uint8_t pin) : _pin(pin) {}

    void begin() {
      pinMode(_pin, INPUT_PULLUP);
      _state = digitalRead(_pin);
    }

    bool isReleased() {
      bool v = digitalRead(_pin);
      if (v != _state) {
        _state = v;
        if (_state) {
          return true;
        }
      }
      return false;
    }
};

//variables

int E1 = 10;
int M1 = 12;
int E2 = 11;
int M2 = 13;

int IR_F = A0;
int IR_L = A1;
int IR_R = A2;

Button button(A3);
bool _start = true;

int mop1_pin = A4;
int mop2_pin = A5;

Servo mop1;
Servo mop2;

//movement functions
void backward(int a, int b) {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, a);
  analogWrite(E2, b);
}

void forward(int a, int b) {
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  analogWrite(E1, a);
  analogWrite(E2, b);
}

void left(int a, int b) {
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  analogWrite(E1, a);
  analogWrite(E2, b);
}

void right(int a, int b) {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  analogWrite(E1, a);
  analogWrite(E2, b);
}

//set mop's position
void SET_MOP(int pos) {
  mop1.write(pos);
  mop2.write(pos);
}

void setup() {
  mop1.attach(mop1_pin);
  mop2.attach(mop2_pin);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(IR_F, INPUT);
  pinMode(IR_L, INPUT);
  pinMode(IR_R, INPUT);
  Serial.begin(9600);
}

void loop() {
  //wait for button press to begin mopping
  if (button.isReleased()) {
    _start = !_start;
  }

  if (_start) {
    SET_MOP(DOWN);

    int D_F = map(analogRead(IR_F), 0, 650, 0, 10); //distance read from front IR sensor
    int D_L = map(analogRead(IR_L), 0, 650, 0, 10); //distance read from left IR sensor
    int D_R = map(analogRead(IR_R), 0, 650, 0, 10); //distance read from right IR sensor

    // print distance
    Serial.println("FRONT \t LEFT \t RIGHT");
    Serial.print(D_F);
    Serial.print("\t");
    Serial.print(D_L);
    Serial.print("\t");
    Serial.println(D_R);

    if (D_F >= OBSTACLE_DISTANCE) {
      //if an object is infront,
      //check if there are any objects detected by the left/right sensor.
      //turn to the direction without obstructions.

      if (D_R < OBSTACLE_DISTANCE) {
        //if right is free
        left(60, 60);
        delay(450);
        forward(60, 60);
        delay(300);
      } else { //D_L < OBSTACLE_DISTANCE
        //if left is free
        right(60, 60);
        delay(450);
        forward(60, 60);
        delay(300);
      }
    } else if (D_R >= OBSTACLE_DISTANCE) {
      //if an object is detected by the right sensor, turn left
      left(60, 60);
      delay(450);
      forward(60, 60);
      delay(300);
    } else if (D_L >= OBSTACLE_DISTANCE) {
      //if an object is detected by the left sensor, turn right
      right(60, 60);
      delay(450);
      forward(60, 60);
      delay(300);
    } else {
      //keep mopping when there are no obstructions ahead or beside the robot
      forward(60, 60);
      delay(10);
    }
  } else {
    SET_MOP(UP);
    //stop
    forward(0, 0);
    delay(10);
  }
}
