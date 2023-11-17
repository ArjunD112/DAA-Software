//int goalX = 110;
//int goalY = 780;
//int buzzer = 9;
//boolean toned = false;
//double distance = -1;
//
//void setup(){
//  Serial.begin(9600);
//  pinMode(buzzer, OUTPUT);
//}
//
//void loop() {

//  tone(9, 800, 500);
//  delay(1000);
//  toned = true;
//  
//  
//  while(toned = true){
//    
//  pinMode(A2, OUTPUT); //x-left
//  pinMode(A3, OUTPUT); //x-right
//  pinMode(A0, INPUT); //read
//
//  analogWrite(A3, 0);
//  analogWrite(A2, 255);
//  int x = analogRead(A0);
//  String printState = "  (" + String(x) + ", ";
//  Serial.print(printState);
//  
//  pinMode(A0, OUTPUT); //y-up
//  pinMode(A1, OUTPUT); //y-down
//  pinMode(A2, INPUT); // read
//
//  analogWrite(A0, 255);
//  analogWrite(A1, 0);
//  int y = analogRead(A2);
//  String print2 = String(y) + ") ";
//  Serial.print(print2);
//
//  float xdist = sq(x-110);
//  if (xdist < 0) { xdist = xdist*(-1); }
//  Serial.print(xdist);
//
//  float ydist = sq(y-780);
//  if (ydist < 0) { ydist = ydist*(-1); }
//  Serial.print(ydist);
//
//  distance = sqrt(xdist+ydist);
//
//  if(x >= 2 && y <= 1020){
//
//  tone(9, 7*(distance), 1000);
//  delay(2000);
//  }
//  
//  }

#include <stdint.h>
#include "TouchScreen.h"

#define YP A2  // must be an analog pin, use "An" notation!
#define XM A3  // must be an analog pin, use "An" notation!
#define YM 7   // can be a digital pin
#define XP 8   // can be a digital pin

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 350);

int goalY = 530;
int distance = -1;
int buzzer = 2;
boolean toned = false;
boolean targetHit = false;

void setup(void) {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop(void) {

  tone(buzzer, 800, 2000);
  delay(1000);
  toned = true;
  
  while(toned == true) {
  TSPoint p = ts.getPoint();
  
  // we have some minimum pressure we consider 'valid'
  // pressure of 0 means no pressing!
  if (p.z > ts.pressureThreshhold) {
     Serial.print("X = "); Serial.print(p.x);
     Serial.print("\tY = "); Serial.print(p.y);
     Serial.print("\tPressure = "); Serial.println(p.z);
  }

  delay(50);

  distance = abs(goalY-p.y);

  if (p.z > ts.pressureThreshhold && distance <= 10) {
    tone(buzzer, 550, 400);
    delay(600);
    tone(buzzer, 650, 400);
    delay(600);
    tone(buzzer, 750, 400);
    delay(600);
  } else if(p.z > ts.pressureThreshhold) {
    int freq = map(distance, 0, 500, 200, 800);
    tone(buzzer, freq, 500);
    delay(50);
  } 

  }

  
}
