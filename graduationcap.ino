#include <Servo.h>
#include "LedControl.h"

// pin mappings
#define SWITCH_PIN 2
#define SERVO_PIN 9
LedControl lc = LedControl(11,13,10,1);  // (DIN, CLK, CS, # of MAX7219 chips)

// wannabe enum
#define PALY 0
#define COLUMBIA 1

Servo myservo;
int state = PALY;

void setup() {
    Serial.begin(9600);
    //wake up the MAX72XX from power-saving mode
    lc.shutdown(0,false);
    //set a medium brightness for the Leds
    lc.setIntensity(0,8);

    pinMode(SWITCH_PIN, INPUT_PULLUP);
    myservo.attach(SERVO_PIN);
}

void loop() {
  if (digitalRead(SWITCH_PIN) == 0) {
    delay(500);
    state = 1 - state; // toggle state
  }

  switch(state) {
    case PALY:
      display_paly();
      myservo.write(180);
      break;
    case COLUMBIA:
      display_columbia_upsidedown();
      myservo.write(0);
      break;
    default:
      break;
  }
}

void display_paly() {
  lc.setChar(0, 7, 'P', false);
  lc.setChar(0, 6, 'A', false);
  lc.setChar(0, 5, 'L', false);
  lc.setChar(0, 4, 'Y', false);
  lc.setChar(0, 3, '2', false);
  lc.setChar(0, 2, '0', false);
  lc.setChar(0, 1, '1', false);
  lc.setChar(0, 0, '6', false);
}

void display_columbia() {
  lc.setChar(0, 7, '5', false);
  lc.setChar(0, 6, 'E', false);
  lc.setChar(0, 5, 'A', false);
  lc.setChar(0, 4, '5', false);
  lc.setChar(0, 3, '2', false);
  lc.setChar(0, 2, '0', false);
  lc.setChar(0, 1, '2', false);
  lc.setChar(0, 0, '0', false);
}

void display_columbia_upsidedown() {
  lc.setChar(0, 7, '0', false);
  lc.setChar(0, 6, '2', false);
  lc.setChar(0, 5, '0', false);
  lc.setChar(0, 4, '2', false);
  lc.setChar(0, 3, 'S', false);
  lc.setByte(0, 2, B0111111, false); // upside-down A
  lc.setChar(0, 1, '3', false);
  lc.setChar(0, 0, 'S', false);
}

