#include "Arduino.h"
#include "MotorClock.h"
#include <Stepper.h>

MotorClock::MotorClock(int hour, int minutes, uint8_t servoP, uint8_t stepperN1P, uint8_t
                       stepperN2P, uint8_t stepperN3P, uint8_t stepperN4P, uint8_t buzzerP, uint8_t
                       button1P, uint8_t button2P, uint8_t rgbRP, uint8_t rgbGP, uint8_t rgbBP)
{
  srv.attach(servoP);
  hours = hour;
  minute = minutes;
  st1 = stepperN1P;
  st2 = stepperN2P;
  st3 = stepperN3P;
  st4 = stepperN4P;
  buzz = buzzerP;
  bt1 = button1P;
  bt2 = button2P;
  red = rgbRP;
  green = rgbGP;
  blue = rgbBP;
}
String MotorClock::showTime() {
  int ang = hours * 180 / 12 + minute / 4;
  double min2 = 2000 * (double)minute / 60; //2000 steps are needed to go around
  srv.write(ang);
  stepperMove(min2);
  return  String(ang) + ":" + min2;

}
void MotorClock::setTimer(double minutes) {
  delay(minutes * 60000);
  while (true) {
    tone(buzz, 1000);
    if (analogRead(bt2) == 1) break;
  }
  noTone(buzz);
}
void MotorClock::setTimerByHand() {
  double w = 0;
  while (true) {
    analogWrite(red, 100);
    if (analogRead(bt1) == 1) {
      w++;
      delay(1000);
    }
    if (analogRead(bt2) == 1) break;
  }
  analogWrite(red, 0);
  setTimer(w);
}
void MotorClock:: setAlarm(int hour, int minutes) {
  alah = hour;
  alam = minutes;
  if (hours == alah && minute == alam) {
    alah = -1;
    alam = -1;
    while (true) {
      tone(buzz, 1000);
      if (analogRead(bt2) == 1) break;
    }
    noTone(buzz);
  }
}
void MotorClock::setAlarmByHand() {
  alah = 0;
  alam = 0;
  analogWrite(green, 100);
  int ha = 0;
  int mi = 0;
  while (true) {
    if (analogRead(bt1 == 1)) {
      delay(500);
      ha++;
    }
    if (ha > 12)ha = 0;
    if (analogRead(bt2 == 1)) {
      delay(500);
      break;
    }
  }
  while (true) {
    if (analogRead(bt1 == 1)) {
      delay(500);
      mi += 10;
    }
    if (mi > 60)mi = 0;
    if (analogRead(bt2 == 1)) {
      delay(500);
      break;
    }
  }
  analogWrite(green, 0);
  setAlarm(ha, mi);
}
void MotorClock::checkAlarm() {
  if (alah < hours || alah == hours && alam < minute) {
    while (true) {
      tone(buzz, 1000);
      if (analogRead(bt2) == 1) break;
    }
    noTone(buzz);
    alah = -1;
    alam = -1;
  }
}
double MotorClock :: setStopWatch() {
  int m = 0;
  double rand = 0;
  while (true) {
    delay(60000);
    m++;
    if (analogRead(bt2) == 1) break;
  }
  rand = (double)m;
  if (m < 60) {
    stepperMove((2000 * m) / 60);
  } else {
    int h = m / 60;
    m = m - h * 60;
    for (int i = 0; i < h; i++) {
      stepperMove(2000);
    }
    stepperMove((2000 * m) / 60);
  }
  delay(1000);
  int left = 60 - m;
  stepperMove((2000 * left) / 60);
  return rand;
}
double MotorClock :: setStopWatchByhand() {
  analogWrite(blue, 100);
  int m = 0;
  while (analogRead(bt1) == 0) {
    //smth
  }
  return setStopWatch();
}
void MotorClock ::  stepperMove(int a) {
  while (a > 0) {
    delay(12);
    switch (n) {
      case 0:
        digitalWrite(st1, LOW);
        digitalWrite(st2, LOW);
        digitalWrite(st3, LOW);
        digitalWrite(st3, HIGH);
        break;
      case 1:
        digitalWrite(st1, LOW);
        digitalWrite(st2, LOW);
        digitalWrite(st3, HIGH);
        digitalWrite(st4, LOW);
        break;
      case 2:
        digitalWrite(st1, LOW);
        digitalWrite(st2, HIGH);
        digitalWrite(st3, LOW);
        digitalWrite(st4, LOW);
        break;
      case 3:
        digitalWrite(st1, HIGH);
        digitalWrite(st2, LOW);
        digitalWrite(st3, LOW);
        digitalWrite(st4, LOW);
    }
    n++;
    a--;
    if (n > 3) {
      n = 0;
    }
  }
}
