#include "ArduinoMotorShield.h"

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


ArduinoMotorShield::ArduinoMotorShield(const Motor & m1, const Motor & m2)
  : mMotor1(m1)
  , mMotor2(m2)
{ }

void ArduinoMotorShield::init() const
{
  
  pinMode(mMotor1.dirPin, OUTPUT); 
  pinMode(mMotor1.brakePin, OUTPUT); 
  pinMode(mMotor1.speedPin, OUTPUT);
  
  digitalWrite(mMotor1.brakePin, HIGH);    

  pinMode(mMotor2.dirPin, OUTPUT); 
  pinMode(mMotor2.brakePin, OUTPUT);
  pinMode(mMotor2.speedPin, OUTPUT);

  digitalWrite(mMotor2.brakePin, HIGH); 
}

void ArduinoMotorShield::move(int speed) const
{
  startMotor(speed, mMotor1);    
  startMotor(speed, mMotor2);
}

void ArduinoMotorShield::stop() const
{
  digitalWrite(mMotor1.brakePin, HIGH); 
  digitalWrite(mMotor2.brakePin, HIGH);
}

void ArduinoMotorShield::turn(int speed) const
{
  startMotor(speed, mMotor1);    
  startMotor(-speed, mMotor2);
}



