//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Otto_distance   sample sketch
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-- Otto DIY PLUS APP Firmware version 9 (V9)
//-- Otto DIY invests time and resources providing open source code and hardware,  please support by purchasing kits from (https://www.ottodiy.com)
//-----------------------------------------------------------------
//-- If you wish to use this software under Open Source Licensing, you must contribute all your source code to the community and all text above must be included in any redistribution
//-- in accordance with the GPL Version 2 when your application is distributed. See http://www.gnu.org/copyleft/gpl.html
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <Otto9.h> //-- Otto Library version 9
Otto9 Otto;  //This is Otto!

//---------------------------------------------------------
//-- First step: Configure the pins where the servos are attached
/*
         ---------------
        |     O   O     |
        |---------------|
YR 3==> |               | <== YL 2
         ---------------
            ||     ||
            ||     ||
RR 5==>   -----   ------  <== RL 4
         |-----   ------|
*/
// SERVO PINs //////////////////////////////////////////////////////////////////////////////
#define PIN_YL 2 //servo[0]  left leg
#define PIN_YR 3 //servo[1]  right leg
#define PIN_RL 4 //servo[2]  left foot
#define PIN_RR 5 //servo[3]  right foot
// ULTRASONIC PINs /////////////////////////////////////////////////////////////////////////
#define PIN_Trigger  8  //TRIGGER pin (8)
#define PIN_Echo     9  //ECHO pin (9)
// BUZZER PIN //////////////////////////////////////////////////////////////////////////////
#define PIN_Buzzer  13 //BUZZER pin (13)
// SERVO ASSEMBLY PIN   /////////////////////////////////////////////////////////////////////
// to help assemble Otto's feet and legs - wire link between pin 7 and GND
#define PIN_ASSEMBLY    7   //ASSEMBLY pin (7) LOW = assembly    HIGH  = normal operation
///////////////////////////////////////////////////////////////////
//-- Global Variables -------------------------------------------//
///////////////////////////////////////////////////////////////////
int distance; // variable to store distance read from ultrasonic range finder module
bool obstacleDetected = false; // logic state for when object detected is at the distance we set
///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup() {
  Otto.init(PIN_YL, PIN_YR, PIN_RL, PIN_RR, true, A6, PIN_Buzzer, PIN_Trigger, PIN_Echo); //Set the servo pins and ultrasonic pins and Buzzer pin

  Otto.sing(S_connection);// Otto makes a sound
  Otto.home(); // Otto moves to its ready position

Otto.home(); // here we stop Otto walking and place it in its ready position
}
///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void dance() {
  Otto.crusaito(2, 1000, 20,1); //FORWARD
  Otto.crusaito(2, 1000, 20,-1);//BACKWARD
  delay(100); 
}

void danceOfALifeTime() {
  Otto.jitter(2,750,20);
  Otto.crusaito(1,800,30,1);
  Otto.crusaito(1,800,30,-1);
  Otto.crusaito(1,800,30,1);
  delay(300);
  Otto.walk(1,1500,-1);
  Otto.walk(2,1000,1);
  Otto.moonwalker(1,600,30,1);
  Otto.moonwalker(1,600,30,-1);
  Otto.moonwalker(1,600,30,1);
  Otto.moonwalker(1,600,30,-1);
  Otto.walk(1,1500,-1);
  Otto.walk(2,1000,1);
  Otto.moonwalker(1,600,30,1);
  Otto.moonwalker(1,600,30,-1);
  Otto.moonwalker(1,600,30,1);
  Otto.moonwalker(1,600,30,-1);
  Otto.walk(1,1500,-1);
  Otto.walk(2,1000,1);
  Otto.shakeLeg(1,700,1);
  Otto.shakeLeg(1,700,-1);
  delay(1000);
  Otto.home();
  Otto.moonwalker(1,3000,50,1);
  Otto.moonwalker(1,3000,50,-1);
  delay(100);
  Otto.moonwalker(1,3000,50,-1);
  Otto.moonwalker(1,3000,50,1);
  Otto.jump(1,370);
  Otto.jump(1,370);
  Otto.jump(1,370);
  Otto.jump(1,370);
  Otto.bend(1,100,1);
  Otto.bend(1,100,-1);
  Otto.jump(1,370);
  Otto.jump(1,370);
  Otto.jump(1,370);
  Otto.jump(1,370);
  Otto.bend(1,100,1);
  Otto.bend(1,100,-1);
  delay(500);
  Otto.crusaito(1,800,30,1);
  Otto.crusaito(1,800,30,-1);
  Otto.crusaito(1,800,30,1);
  delay(300);
  Otto.walk(1,1500,-1);
  Otto.walk(2,1000,1);
  Otto.moonwalker(1,600,30,1);
  Otto.moonwalker(1,600,30,-1);
  Otto.moonwalker(1,600,30,1);
  Otto.moonwalker(1,600,30,-1);
  Otto.walk(1,1500,-1);
  Otto.walk(2,1000,1);
  Otto.moonwalker(1,600,30,1);
  Otto.moonwalker(1,600,30,-1);
  Otto.moonwalker(1,600,30,1);
  Otto.moonwalker(1,600,30,-1);
  Otto.updown(3,900,30);
  Otto.jitter(3,1000,20);
  Otto.jump(1,400);
  Otto.jump(1,400);
  Otto.jump(1,400);
  Otto.jump(1,400);
  Otto.jitter(4,800,20);
  Otto.jump(1,400);
  Otto.jump(1,400);
  Otto.jump(1,400);
  Otto.jump(1,400);
  Otto.jitter(2,800,20);
  delay(1500);
  Otto.home();
  Otto.moonwalker(1,3000,50,1);
  Otto.moonwalker(1,3000,50,-1);
  delay(100);
  Otto.moonwalker(1,3000,50,-1);
  Otto.moonwalker(1,3000,50,1);
}


void loop() {
                              
  delay(1000); // wait for 2 seconds to allow Otto to settle and so you can see the serial port data on the serial monitor
         
   distance = Otto.getDistance(); // get the distance from the object - value will be between 99cm and 4cm
   
   if (distance < 6) {
    danceOfALifeTime();
   }

   
   if (distance < 10) {
    dance();
   }

   if (distance < 15) {
    Otto.tiptoeSwing(2, 1000, 20);
   }
   Otto.home();
   Serial.println("hello");
   Serial.println(distance); // send the distance measured to the serial port so you can see the distance as a number

    
}  
