#include "ArduinoMotorShield.h"

ArduinoMotorShield shield;

//#define BATTERY

#ifdef BATTERY
const int SPEED = 127;
#else
const int SPEED = 255;
#endif

const int RUN_MS = 2000;
const int STOP_MS = 1000;
const int TURN_MS = 1000;

void setup()
{
  Serial.begin(115200);
  shield.init();
}

void loop()
{
  shield.move(SPEED);
  delay(RUN_MS);

  shield.stop();
  delay(STOP_MS);

  shield.move(-SPEED);
  delay(RUN_MS);

  shield.stop();
  delay(STOP_MS);
  
  shield.turn(SPEED);
  delay(TURN_MS);

  shield.stop();
  delay(STOP_MS);

  shield.turn(-SPEED);
  delay(TURN_MS);

  shield.stop();
  delay(STOP_MS);
}
