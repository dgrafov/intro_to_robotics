#pragma once

#include "Arduino.h"

class Button
{
public:
  explicit Button(int p);
  void init() const;
  int state(bool& toggled);
private:  
  int mLastState = LOW;
  int mPin = 0;
};
