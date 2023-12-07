
#include <stdint.h>
#include "TouchScreen.h"

#define YP1 A2  // must be an analog pin, use "An" notation!
#define XM1 A3  // must be an analog pin, use "An" notation!
#define YM1 7   // can be a digital pin
#define XP1 8   // can be a digital pin

#define YP2 A2  // must be an analog pin, use "An" notation!
#define XM2 A3  // must be an analog pin, use "An" notation!
#define YM2 7   // can be a digital pin
#define XP2 8   // can be a digital pin

#define YP3 A2  // must be an analog pin, use "An" notation!
#define XM3 A3  // must be an analog pin, use "An" notation!
#define YM3 7   // can be a digital pin
#define XP3 8   // can be a digital pin

#define YP4 A2  // must be an analog pin, use "An" notation!
#define XM4 A3  // must be an analog pin, use "An" notation!
#define YM4 7   // can be a digital pin
#define XP4 8   // can be a digital pin



TouchScreen ts1 = TouchScreen(XP1, YP1, XM1, YM1, 350);
TouchScreen ts2 = TouchScreen(XP2, YP2, XM2, YM2, 350);
TouchScreen ts3 = TouchScreen(XP3, YP3, XM3, YM3, 350);
TouchScreen ts4 = TouchScreen(XP4, YP4, XM4, YM4, 350);



int goalY[] = {250, 750}; //update after testing
int distance = -1;
int buzzers[] = {*(0 - 7)*};
boolean toned = false;

void setup(void) {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(12, OUTPUT); //expand to all buzzer pins
  //add pin mode decs. for screens too
}

void loop(void) {

  int targetBuzzer = random(0, 8);
  int targetScreen = targetBuzzer / 2 + 1;
  Serial.print(targetBuzzer);
  Serial.print(targetScreen);
  delay(100);
  tone(buzzers[targetBuzzer], 700, 2000);
  delay(2500);
  toned = true;

  while (toned == true) {

    TSPoint p[] = {ts1.getPoint(), ts2.getPoint(), ts3.getPoint(), ts4.getPoint()};

    if (p[0].z > ts.pressureThreshhold || p[1].z > ts.pressureThreshhold || p[2].z > ts.pressureThreshhold || p[3].z > ts.pressureThreshhold) {

      if (p[targetScreen].z > ts.pressureThreshhold) {
        Serial.print("X = "); Serial.print(p.x);
        Serial.print("\tY = "); Serial.print(p.y);
        Serial.print("\tPressure = "); Serial.println(p.z);

        delay(50);

        int distance = abs(goalY[targetBuzzer] - p.y);

        if (distance <= 10) {
          tone(buzzers[0], 550, 200);
          delay(250);
          tone(buzzers[0], 650, 200);
          delay(250);
          tone(buzzers[0], 750, 200);
          delay(250);
          toned = false;
          delay(2000);
        } else {
          int freq = map(distance, 500, 0, 200, 1200); //test this
          tone(buzzers[targetBuzzer], freq, 500);
          delay(50);
        }
      }

      else {
        tone(buzzers[targetBuzzer], 450, 400);
        delay(500);
        tone(buzzers[targetBuzzer], 350, 400);
        delay(500);
        delay(1000);
      }
    }
  }
}
