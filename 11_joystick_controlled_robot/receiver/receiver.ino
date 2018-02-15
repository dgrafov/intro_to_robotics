#include "nRF24L01.h"
#include "RF24.h"
#include "MotorShield.h"

//#define BATTERY

#ifdef BATTERY
const int SPEED = 127;
#else
const int SPEED = 255;
#endif

const int CE_PIN = A4;
const int CSN_PIN = A5;

const byte address[] = "00001";

RF24 radio(CE_PIN, CSN_PIN);
MotorShield shield;

enum Action
{
  FORWARD = 1,
  BACKWARD,
  TURN_LEFT,
  TURN_RIGHT,
  STOP
};

void setup()
{
  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
  shield.init();
  shield.stop();
}

Action curAction = STOP;

void loop()
{
  if (radio.available())
  {
    Action action = STOP;
    radio.read(&action, sizeof(action));

    Serial.println(action);

    if (action != curAction)
    {
      curAction = action;
      Serial.println(curAction);
      switch(action)
      {
        case FORWARD:
          shield.move(SPEED);
          break;
        case BACKWARD:
          shield.move(-SPEED);
          break;
        case TURN_LEFT:
          shield.turn(SPEED);
          break;
        case TURN_RIGHT:
          shield.turn(-SPEED);
          break;
        case STOP:
          shield.stop();
          break;
      }
    }
  }
}
