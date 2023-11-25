#include <Servo.h>

int ServoPin = 5;
int ServoPos = 45;

Servo myServo;

void setup() {
  // Setup code runs once
  myServo.attach(ServoPin);
}

void loop() {
  // Main code runs repeatedly
  myServo.write(ServoPos);
}
