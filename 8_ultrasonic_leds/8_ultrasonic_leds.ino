#include "Ultrasonic.h"
#include "LedLine.h"

const int TRIGGER_PIN = 9;
const int ECHO_PIN = 8;
const unsigned MAX_DISTANCE = 200;
const int LED_PINS[] = {2, 3, 4, 5, 6, 7};
const int LEDS_NUM = 6;
const int CM_PER_LED = 5;

const unsigned LED_MASKS[] = {63, 31, 15, 7, 3, 1};


Ultrasonic sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
LedLine leds(LEDS_NUM, LED_PINS);

void setup() {
  Serial.begin(115200); 
  sonar.init();
  leds.init();
}

void loop() {
  delay(50);             
  unsigned distCm = sonar.ping();        
  Serial.print("Ping: ");
  Serial.print(distCm); 
  Serial.println("cm");

  if (distCm > 0)
  {
    int num = distCm / CM_PER_LED;
    
    if (num < LEDS_NUM) 
    {
      leds.setLeds(LED_MASKS[num]);
      Serial.println(LED_MASKS[num]);
    }
    else
    {
      leds.setLeds(0);
    }
  }
  else
  {
    leds.setLeds(0);
  }
}
