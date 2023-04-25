#include "MotorClock.h"
#include "Arduino.h"
int hour=6;
int minute=30;
#define servPin 5
#define st1 6
#define st2 7
#define st3 8
#define st4 9
#define buzz 10
#define but1 A0
#define but2 A1
#define red A2
#define green A3
#define blue A4
MotorClock mt = MotorClock (hour, minute,servPin, st1, st2, st3, st4, buzz,but1, but2, red, green, blue);
void setup() {
  // put your setup code here, to run once:
 pinMode(servPin,OUTPUT) ;
 pinMode(st1,OUTPUT);
 pinMode(st2,OUTPUT);
 pinMode(st3,OUTPUT);
 pinMode(st4,OUTPUT);
 pinMode(buzz,OUTPUT);
 pinMode(but1, INPUT);
 pinMode(but2,INPUT);
 pinMode(red,INPUT);
 pinMode(green,INPUT);
 pinMode(blue,INPUT);
 

}

void loop() {
  // put your main code here, to run repeatedly:

}
