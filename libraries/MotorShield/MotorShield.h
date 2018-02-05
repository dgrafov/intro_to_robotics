#pragma once

#include <Arduino.h>

struct Motor 
{
  Motor(int dir, int brake, int speed)
  : dirPin(dir)
  , brakePin(brake)
  , speedPin(speed)
  {}
  int dirPin;
  int brakePin;
  int speedPin;
};


class MotorShield
{
public:
  enum State
  {
    STOPPED,
    FORWARD,
    BACKWARD,
    TURN_POSITIVE,
    TURN_NEGATIVE
  };

  // default constructor: two motors with default pin selection
  MotorShield() = default;  
  // constructor with two motors, user's pin selection
  MotorShield(const Motor & m1, const Motor & m2); 

  void init();
  void move(int speed);
  void stop();
  void turn(int speed);
  State getState() const;
private:
  Motor mMotor1 = {12, 9, 3};
  Motor mMotor2 = {13, 8, 11};
  State m_state = STOPPED;
};

