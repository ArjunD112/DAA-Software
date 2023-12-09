void setup() {
  Serial.begin(9600);
}

void loop() {
  tone(2, 600, 2000);
  delay(2500);
  tone(3, 600, 2000);
  delay(2500);
  tone(4, 600, 2000);
  delay(2500);
  tone(5, 600, 2000);
  delay(2500);
  tone(6, 600, 2000);
  delay(2500);
  tone(7, 600, 2000);
  delay(2500);
  tone(8, 600, 2000);
  delay(2500);
  tone(9, 600, 2000);
  delay(2500);
}


//
//#include <stdint.h>
//#include "TouchScreen.h"
//
//#define YP1 A0  // must be an analog pin, use "An" notation!
//#define XM1 A1  // must be an analog pin, use "An" notation!
//#define YM1 11   // can be a digital pin
//#define XP1 10   // can be a digital pin
//
//#define YP2 A2  // must be an analog pin, use "An" notation!
//#define XM2 A3  // must be an analog pin, use "An" notation!
//#define YM2 13   // can be a digital pin
//#define XP2 12   // can be a digital pin
//
//#define YP3 A4  // must be an analog pin, use "An" notation!
//#define XM3 A5  // must be an analog pin, use "An" notation!
//#define YM3 15   // can be a digital pin
//#define XP3 14   // can be a digital pin
//
//#define YP4 A6  // must be an analog pin, use "An" notation!
//#define XM4 A7  // must be an analog pin, use "An" notation!
//#define YM4 17   // can be a digital pin
//#define XP4 16   // can be a digital pin
//
//
//
//TouchScreen ts1 = TouchScreen(XP1, YP1, XM1, YM1, 350);
//TouchScreen ts2 = TouchScreen(XP2, YP2, XM2, YM2, 350);
//TouchScreen ts3 = TouchScreen(XP3, YP3, XM3, YM3, 350);
//TouchScreen ts4 = TouchScreen(XP4, YP4, XM4, YM4, 350);
//
//
//void setup() {
//  pinMode(A0, INPUT);
//  pinMode(A1, INPUT);
//  pinMode(A2, INPUT);
//  pinMode(A3, INPUT);
//  pinMode(A4, INPUT);
//  pinMode(A5, INPUT);
//  pinMode(A6, INPUT);
//  pinMode(A7, INPUT);
//  
//  pinMode(10, OUTPUT);
//  pinMode(11, OUTPUT);
//  pinMode(12, OUTPUT);
//  pinMode(13, OUTPUT);
//  pinMode(14, OUTPUT);
//  pinMode(15, OUTPUT);
//  pinMode(16, OUTPUT);
//  pinMode(17, OUTPUT);
//
//  Serial.begin(9600);
//}
//
//void loop() {
//  TSPoint p[] = {ts1.getPoint(), ts2.getPoint(), ts3.getPoint(), ts4.getPoint()};
//
//  if (p[0].z > ts1.pressureThreshhold || p[1].z > ts2.pressureThreshhold || p[2].z > ts3.pressureThreshhold || p[3].z > ts4.pressureThreshhold) {
//    if (p[0].z > ts1.pressureThreshhold) {
//        Serial.print("X1 = "); Serial.print(p[0].x);
//        Serial.print("\tY1 = "); Serial.print(p[0].y);
//        Serial.print("\tPressure1 = "); Serial.println(p[0].z);
//
//        delay(50);
//  }
//  if (p[1].z > ts2.pressureThreshhold) {
//        Serial.print("X2 = "); Serial.print(p[1].x);
//        Serial.print("\tY2 = "); Serial.print(p[1].y);
//        Serial.print("\tPressure2 = "); Serial.println(p[1].z);
//
//        delay(50);
//  }
//  if (p[2].z > ts3.pressureThreshhold) {
//        Serial.print("X3 = "); Serial.print(p[2].x);
//        Serial.print("\tY3 = "); Serial.print(p[2].y);
//        Serial.print("\tPressure3 = "); Serial.println(p[2].z);
//
//        delay(50);
//  }
//  if (p[3].z > ts4.pressureThreshhold) {
//        Serial.print("X4 = "); Serial.print(p[3].x);
//        Serial.print("\tY4 = "); Serial.print(p[3].y);
//        Serial.print("\tPressure4 = "); Serial.println(p[3].z);
//
//        delay(50);
//  }
//}
//}
