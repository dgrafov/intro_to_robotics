#include "Ultrasonic.h"
#include "MotorShield.h"

const int TRIGGER_PIN = A5;
const int ECHO_PIN = A4;
const unsigned MAX_DISTANCE = 200;
const unsigned AVOIDANCE_DISTANCE_CM = 10;

const int PING_INTERVAL_MS = 50;

//#define BATTERY

#ifdef BATTERY
const int SPEED = 127;
#else
const int SPEED = 255;
#endif

const int TURN_TIMEOUT_MS = 5000;  
const int TURN_LOOPS_COUNT = (TURN_TIMEOUT_MS / PING_INTERVAL_MS); // each loop takes at least PING_INTERVAL_MS ms. 

Ultrasonic sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
MotorShield shield;

void setup() {
  Serial.begin(115200); 
  sonar.init();
  shield.init();
}

int loopsCount = 0;

void loop() {
  delay(PING_INTERVAL_MS);  
             
  unsigned distCm = sonar.ping();        

  if (distCm > 0 && distCm < AVOIDANCE_DISTANCE_CM) 
  {
    // turn 
    if( loopsCount <= TURN_LOOPS_COUNT )
    {
      if( shield.getState() != MotorShield::TURN_POSITIVE && shield.getState() != MotorShield::TURN_NEGATIVE )
      {
        shield.turn(SPEED);
      }
      ++loopsCount;
    }
    else
    {
      shield.stop();
    }
  }
  else if (shield.getState() != MotorShield::FORWARD)
  {
    loopsCount = 0;
    shield.move(SPEED);   
  }
}
