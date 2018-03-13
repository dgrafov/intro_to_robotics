#include "Ultrasonic.h"
#include "MotorShield.h"

const int TRIGGER_PIN = A5;
const int ECHO_PIN = A4;
const unsigned MAX_DISTANCE = 200;
const unsigned AVOIDANCE_DISTANCE_CM = 10;

const int PING_INTERVAL_MS = 50;
const int TURN_TIME_MS = 500;

#define BATTERY

#ifdef BATTERY
const int SPEED = 127;
#else
const int SPEED = 255;
#endif

const int TURN_TIMEOUT_MS = 5000;  
const int TURN_LOOPS_COUNT = (TURN_TIMEOUT_MS / TURN_TIME_MS); // each loop takes at least PING_INTERVAL_MS ms. 

Ultrasonic sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
MotorShield shield;

void setup() {
  Serial.begin(115200); 
  sonar.init();
  shield.init();
  // for the direction selection in case of an obstacle
  randomSeed(analogRead(0));
}

int loopsCount = 0;
int turnDir = 0;

void loop() {
  delay(PING_INTERVAL_MS);  
             
  unsigned distCm = sonar.ping();        

  if (distCm > 0 && distCm < AVOIDANCE_DISTANCE_CM) 
  {
    // turn
    if (shield.getState() == MotorShield::FORWARD)
    {
      turnDir = random(2); // 0..1  
    }
    // select direction of a turn
    if( loopsCount <= TURN_LOOPS_COUNT )
    {
      if( shield.getState() != MotorShield::TURN_POSITIVE && shield.getState() != MotorShield::TURN_NEGATIVE )
      {
        
        if(turnDir) 
        {
          shield.turn(SPEED);
        }
        else
        {
          shield.turn(-SPEED);
        }
        delay(TURN_TIME_MS);
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
