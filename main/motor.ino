// constants won't change
const int ENA_PIN = 7; // the Arduino pin connected to the EN1 pin L298N
const int IN1_PIN = 6; // the Arduino pin connected to the IN1 pin L298N
const int IN2_PIN = 5; // the Arduino pin connected to the IN2 pin L298N

// the setup function runs once when you press reset or power the board
void setupMotor() {
  // initialize digital pins as outputs.
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
}

void deurOpen() {
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);

  for (int speed = 0; speed <= 255; speed++) {
    analogWrite(ENA_PIN, speed);
    delay(10);
  }

  delay(23000);
  for (int speed = 255; speed >= 0; speed--) {
    analogWrite(ENA_PIN, speed);
    delay(10);
  }
}
void deurDicht() {
  // change direction
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);

  for (int speed = 0; speed <= 255; speed++) {
    analogWrite(ENA_PIN, speed);
    delay(10);
  }

  delay(19000);

  for (int speed = 255; speed >= 0; speed--) {
    analogWrite(ENA_PIN, speed);
    delay(10);
  }

  delay(1000);
}
