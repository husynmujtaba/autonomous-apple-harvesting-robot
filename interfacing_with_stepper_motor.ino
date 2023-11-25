#include <Stepper.h>

// Define motor parameters
int stepsPerRevolution = 2048;
int motorSpeed = 5;
int delayTime = 500;

// Create a Stepper object
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // Initialization code runs once
  myStepper.setSpeed(motorSpeed);
}

void loop() {
  // Main code runs repeatedly
  myStepper.setSpeed(stepsPerRevolution);
  delay(delayTime);
}
