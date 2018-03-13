#include <nRF24L01.h>
#include <RF24.h>

const int CE_PIN = 7;
const int CSN_PIN = 8;

const byte address[] = "00001";

const int JOYSTICK_X = A0;
const int JOYSTICK_Y = A1;

const int READINGS_THRESHOLD = 5;

RF24 radio(CE_PIN, CSN_PIN);

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
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
  Serial.begin(115200);
}

Action lastSentAction = STOP;
Action lastReadAction = STOP;
int numSameReadings = 0;

void loop()
{
  int x = analogRead(JOYSTICK_X);
  int y = analogRead(JOYSTICK_Y);

  // calculate an action for the robot
  Action action = STOP;
  if(x < 411)
  {
    action = TURN_LEFT;
  }
  else if (x > 611)
  {
    action = TURN_RIGHT;
  }
  else if (y > 611)
  {
    action = FORWARD;
  }
  else if (y < 411)
  {
    action = BACKWARD;
  }

  // filter a bit
  if (lastReadAction != action)
  {
    numSameReadings = 0;
    lastReadAction = action;
  }
  else if (++numSameReadings >= READINGS_THRESHOLD && lastReadAction != lastSentAction)
  {
    Serial.println(lastReadAction);
    lastSentAction = lastReadAction;
    radio.write(&lastReadAction, sizeof(lastReadAction));
  }
  delay(50);
}
