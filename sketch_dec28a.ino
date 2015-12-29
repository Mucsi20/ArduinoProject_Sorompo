#include <Servo.h>
#include "Led.h"
#include "Button.h"
#include "Alarm.h"
Servo myServo;
float a = 0;
int ledStatus = 0;
int servoStatus = 0;

Led r2 (13);
Led w (12);
Led r1 (11);
Button b1 (10);
Button b2 (9);
Alarm s (7);

void setup() {
  w.blink(400, 0);
  myServo.write(0);
  myServo.attach(8);
}

void loop() {
  if (b1.isPressed() && ledStatus == 0) {
      r1.blink(250,250);
      r2.blink(250,0);
      w.blink(-1, 0);
      s.alarm(125,25);
      ledStatus = 1;
      servoStatus = 1;
  }
  if (b2.isPressed() && ledStatus == 1 && servoStatus == 0) {
      ledStatus = 0;
      servoStatus = 1;
  }

  if (servoStatus == 1) {
    if (ledStatus == 0) {
      a -= 0.004;
      if (a < 0) {
        a = 0;
        servoStatus = 0;
        r1.blink(-1,0);
        r2.blink(-1,0);
        w.blink(400, 0);
        s.alarm(-1, 0);
      }
    } else {
      a += 0.004;
      if (a > 80) {
        a = 80;
        servoStatus = 0;
      }
    }
    myServo.write(a);
  }
  
  w.update();
  r1.update();
  r2.update();
  s.update();
}


