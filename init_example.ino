#include <Servo.h>
#include <Oscillator.h>
#include <Otto9.h>

Otto9 Otto;

byte leftLeg = 2;
byte rightLeg = 3;
byte leftFoot = 4;
byte rightFoor = 5;
byte buzzer = 12;
byte trigPin = 8;
byte echoPin = 9;

void setup() {
  // put your setup code here, to run once:
  Otto.init(leftLeg, rightLeg, leftFoot, false, 0, buzzer, trigPin, echoPin);
}

void loop() {
  // put your main code here, to run repeatedly:

}