
#include <stdint.h>
#include "TouchScreen.h"

#define YP1 A0  // must be an analog pin, use "An" notation!
#define XM1 A1  // must be an analog pin, use "An" notation!
#define YM1 11   // can be a digital pin
#define XP1 10   // can be a digital pin

#define YP2 A2  // must be an analog pin, use "An" notation!
#define XM2 A3  // must be an analog pin, use "An" notation!
#define YM2 13   // can be a digital pin
#define XP2 12   // can be a digital pin

#define YP3 A4  // must be an analog pin, use "An" notation!
#define XM3 A5  // must be an analog pin, use "An" notation!
#define YM3 15   // can be a digital pin
#define XP3 14   // can be a digital pin

#define YP4 A6  // must be an analog pin, use "An" notation!
#define XM4 A7  // must be an analog pin, use "An" notation!
#define YM4 17   // can be a digital pin
#define XP4 16   // can be a digital pin



TouchScreen ts1 = TouchScreen(XP1, YP1, XM1, YM1, 350);
TouchScreen ts2 = TouchScreen(XP2, YP2, XM2, YM2, 350);
TouchScreen ts3 = TouchScreen(XP3, YP3, XM3, YM3, 350);
TouchScreen ts4 = TouchScreen(XP4, YP4, XM4, YM4, 350);



int goalY[] = {250, 750}; //update after testing
int distance = -1;
int buzzers[] = {2, 3, 4, 5, 6, 7, 8, 9};
boolean toned = false;

void setup(void) {
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);

}

void loop(void) {

  int targetBuzzer = random(0, 8);
  int targetScreen = (targetBuzzer / 2) + 1;
  Serial.println("Target Buzzer: " + targetBuzzer);
  Serial.println("Target Screen: " + targetScreen);
  delay(100);
  tone(buzzers[targetBuzzer], 700, 2000);
  delay(2500);
  toned = true;
  int touched = -1;

  while (toned == true) {

    TSPoint p[] = {ts1.getPoint(), ts2.getPoint(), ts3.getPoint(), ts4.getPoint()};


    if (p[0].z > ts1.pressureThreshhold) {
      Serial.print("X1 = "); Serial.print(p[0].x);
      Serial.print("\tY1 = "); Serial.print(p[0].y);
      Serial.print("\tPressure1 = "); Serial.println(p[0].z);

      if (targetScreen == 1) {

        TSPoint a = ts1.getPoint();
        int distance = abs(goalY[targetBuzzer % 2] - a.y);

        if (distance <= 10) {
          tone(buzzers[targetBuzzer], 550, 200);
          delay(250);
          tone(buzzers[targetBuzzer], 650, 200);
          delay(250);
          tone(buzzers[targetBuzzer], 750, 200);
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

      delay(50);
    }

    
    if (p[1].z > ts2.pressureThreshhold) {
      Serial.print("X2 = "); Serial.print(p[1].x);
      Serial.print("\tY2 = "); Serial.print(p[1].y);
      Serial.print("\tPressure2 = "); Serial.println(p[1].z);

      if (targetScreen == 2) {

        TSPoint a = ts2.getPoint();
        int distance = abs(goalY[targetBuzzer % 2] - a.y);

        if (distance <= 10) {
          tone(buzzers[targetBuzzer], 550, 200);
          delay(250);
          tone(buzzers[targetBuzzer], 650, 200);
          delay(250);
          tone(buzzers[targetBuzzer], 750, 200);
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

      delay(50);
    }

    
    if (p[2].z > ts3.pressureThreshhold) {
      Serial.print("X3 = "); Serial.print(p[2].x);
      Serial.print("\tY3 = "); Serial.print(p[2].y);
      Serial.print("\tPressure3 = "); Serial.println(p[2].z);

      if (targetScreen == 3) {

        TSPoint a = ts3.getPoint();
        int distance = abs(goalY[targetBuzzer % 2] - a.y);

        if (distance <= 10) {
          tone(buzzers[targetBuzzer], 550, 200);
          delay(250);
          tone(buzzers[targetBuzzer], 650, 200);
          delay(250);
          tone(buzzers[targetBuzzer], 750, 200);
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

      delay(50);
    }

    
    if (p[3].z > ts4.pressureThreshhold) {
      Serial.print("X4 = "); Serial.print(p[3].x);
      Serial.print("\tY4 = "); Serial.print(p[3].y);
      Serial.print("\tPressure4 = "); Serial.println(p[3].z);

      if (targetScreen == 1) {

        TSPoint a = ts4.getPoint();
        int distance = abs(goalY[targetBuzzer % 2] - a.y);

        if (distance <= 10) {
          tone(buzzers[targetBuzzer], 550, 200);
          delay(250);
          tone(buzzers[targetBuzzer], 650, 200);
          delay(250);
          tone(buzzers[targetBuzzer], 750, 200);
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

      delay(50);
    }
  }
}
