#include "MotorShield.h"

void startMotor(int speed, const Motor& motor)
{
  if (speed < 0)
  {
    digitalWrite(motor.dirPin, LOW);
    speed = -speed;
  }
  else 
  {
    digitalWrite(motor.dirPin, HIGH);
  }
  
  if (speed > 255) 
  {
    speed = 255;
  }

  analogWrite(motor.speedPin, speed);
  digitalWrite(motor.brakePin, LOW);
}


MotorShield::MotorShield(const Motor & m1, const Motor & m2)
  : mMotor1(m1)
  , mMotor2(m2)
{ }

void MotorShield::init()
{
  
  pinMode(mMotor1.dirPin, OUTPUT); 
  pinMode(mMotor1.brakePin, OUTPUT); 
  pinMode(mMotor1.speedPin, OUTPUT);
  
  digitalWrite(mMotor1.brakePin, HIGH);    

  pinMode(mMotor2.dirPin, OUTPUT); 
  pinMode(mMotor2.brakePin, OUTPUT);
  pinMode(mMotor2.speedPin, OUTPUT);

  digitalWrite(mMotor2.brakePin, HIGH); 

  m_state = STOPPED;
}

void MotorShield::move(int speed)
{
  startMotor(speed, mMotor1);    
  startMotor(speed, mMotor2);

  if (speed > 0)
  {
    m_state = FORWARD;
  }
  else if (speed < 0)
  {
    m_state = BACKWARD;
  }
  else
  {
    m_state = STOPPED;
  }
}

void MotorShield::stop()
{
  digitalWrite(mMotor1.brakePin, HIGH); 
  digitalWrite(mMotor2.brakePin, HIGH);

  m_state = STOPPED;
}

void MotorShield::turn(int speed)
{
  startMotor(speed, mMotor1);    
  startMotor(-speed, mMotor2);

  if (speed > 0)
  {
    m_state = TURN_POSITIVE;
  }
  else if (speed < 0)
  {
    m_state = TURN_NEGATIVE;
  }
  else
  {
    m_state = STOPPED;
  }
}

MotorShield::State MotorShield::getState() const
{
    return m_state;
}





