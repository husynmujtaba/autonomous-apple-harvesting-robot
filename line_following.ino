// Define motor speeds and time interval
int Speed1 = 110;
int Speed2 = 220;
int dt = 10;

// Define motor pins
int motorA1 = 8;
int motorA2 = 10;
int motorAspeed = 9;
int motorB1 = 12;
int motorB2 = 13;
int motorBspeed = 11;

// Define infrared sensor pins
int IR_left = A0;
int IR_right = A1;

// Variables to store sensor states
int left_sensor_state;
int right_sensor_state;

void setup() {
  // Set motor pins as outputs
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
}

void loop() {
  // Read sensor values
  left_sensor_state = analogRead(IR_left);
  right_sensor_state = analogRead(IR_right);

  // Move forward if only the right sensor detects an obstacle
  if (right_sensor_state > 500 && left_sensor_state < 500) {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);
    analogWrite(motorAspeed, Speed1);
    analogWrite(motorBspeed, Speed2);
  }

  // Move backward if only the left sensor detects an obstacle
  if (right_sensor_state < 500 && left_sensor_state > 500) {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
    analogWrite(motorAspeed, Speed2);
    analogWrite(motorBspeed, Speed1);
    delay(dt);
  }

  // Move forward if both sensors detect an obstacle
  if (right_sensor_state > 500 && left_sensor_state > 500) {
    Serial.println("going forward");
    digitalWrite(motorA2, LOW);
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorB2, HIGH);
    digitalWrite(motorB1, LOW);
    analogWrite(motorAspeed, Speed1);
    analogWrite(motorBspeed, Speed2);
    delay(dt);
  }

  // Stop if both sensors do not detect an obstacle
  if (right_sensor_state < 500 && left_sensor_state < 500) {
    analogWrite(motorAspeed, 0);
    analogWrite(motorBspeed, 0);
  }
}
