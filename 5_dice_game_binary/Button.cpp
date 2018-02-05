#include "Button.h"
#include "Arduino.h"

Button::Button(int p)
  : mPin(p)
{ }

void Button::init() const 
{
  pinMode(mPin, INPUT);
}

int Button::state(bool& toggled)
{
  int curState = digitalRead(mPin);
  if (mLastState == curState)
  {
    toggled = false;  
  }
  else
  {
    toggled = true;
    mLastState = curState;
  }
  return mLastState;
}

