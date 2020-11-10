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

int distance = 0;

void startDance(); // declaration
void setup() {
 // put your setup code here, to run once:
 Otto.init(leftLeg, rightLeg, leftFoot, rightFoot,false, 0, buzzer, trigPin, echoPin);
 Otto.home(); // reset position
}

void loop() {
 // put your main code here, to run repeatedly:
   distance = Otto.getDistance();

   if (distance < 200) {
       startDance();
   } else {
       Otto.walk(3, 1000, 1);
   }
   delay(500);
}

void startDance() {
   Otto.walk(3, 1000, 1);
   delay(100);
   Otto.moonwalker(3,800,25,1);
   Otto.home();
   Otto.turn(2, 800, -1);
   delay(50);
   Otto.jump(1, 2000);
   Otto.home();

}
