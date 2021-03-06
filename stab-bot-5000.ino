#include <Servo.h>

Servo myServo;

const int servoPin = 9;
const int sensorPin = A0;
const int baseAngle = 160;

int baseLight;
int lightLevel;

void setup() {
  myServo.attach(servoPin);
  reset();
}

void loop() {
  lightLevel = analogRead(sensorPin);
  
  if (abs(baseLight - lightLevel) > 100) {
    stab();
    reset();
  }
}

// Reset base light level, ensure arm in resting position.
void reset() {
  baseLight = analogRead(sensorPin);
  myServo.write(baseAngle);
  delay(1000);
}

// Stabs arm between 1 & 5 times.
void stab() {
  int stabs = random(0, 5);
  while (stabs > 0) {
    swing(136 + random(-16, 16));
    stabs--;
  }
  swing(baseAngle);
}

// Moves servo completely down, then to 'high'.
void swing(int high) {
  myServo.write(0); // swing arm down
  delay(750);
  myServo.write(high); // swing arm up
  delay(750);
}



