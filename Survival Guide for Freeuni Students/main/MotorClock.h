#ifndef MotorClock_h
#define MotorClock_h
#include "Arduino.h"
#include <Servo.h>
#include <Stepper.h>
class MotorClock
{
public:
MotorClock (int hour, int minutes, uint8_t servoP, uint8_t stepperN1P, uint8_t
stepperN2P, uint8_t stepperN3P, uint8_t stepperN4P, uint8_t buzzerP, uint8_t
button1P, uint8_t button2P, uint8_t rgbRP, uint8_t rgbGP, uint8_t rgbBP);
String showTime();
    void setTimer(double minutes);
    
    void setTimerByHand();
    
    void setAlarm(int hour, int minutes);
    
    void setAlarmByHand();
    
    void checkAlarm();
    
    double setStopWatch();
    
    double setStopWatchByhand();
 private:
 Servo srv;
 void stepperMove(int a);
 int hours=0;
 int minute=0;
 int n=0;
    uint8_t st1;
    uint8_t st2;
    uint8_t st3;
    uint8_t st4;
    uint8_t buzz;
    uint8_t bt1;
    uint8_t bt2;
    uint8_t red;
    uint8_t green;
    uint8_t blue;
   int  alah=-1;
   int  alam=-1;


};
#endif
