#include "LedLine.h"
#include "Button.h"

const int BUTTON_PIN = 2;  
const int LED_PINS[] = {7, 8, 9, 10};
const int LEDS_NUM = 4;
const int ANIMATION_DELAY_MS = 100;

Button button(BUTTON_PIN);
LedLine leds(LEDS_NUM, LED_PINS);
 
void setup() 
{  
  Serial.begin(115200);
 
  button.init();
  leds.init();
  
  randomSeed(analogRead(0));
}

unsigned randomNum = 0;

void loop() 
{
  bool toggled = false;
 
  if (button.state(toggled) == HIGH) 
  { 
    if (toggled)
    {
      leds.initAnimation();
    }
    leds.nextAnimationStep(ANIMATION_DELAY_MS);
  }
  else 
  {
    if (toggled)
    {  
      randomNum = static_cast<unsigned>(random(1, 12));
      
      Serial.println(randomNum);
    }
    leds.setLeds(randomNum);
  }
}

