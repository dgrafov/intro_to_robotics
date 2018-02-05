


const int BUTTON_PIN = 2;  
const int LED_PINS[] = {7, 8, 9, 10, 11, 12};
const int LEDS_NUM = sizeof(LED_PINS) / sizeof(LED_PINS[0]);
const int ANIMATION_DELAY = 100;
 
void setup() 
{  
  Serial.begin(115200);
  
  pinMode(BUTTON_PIN, INPUT);
  
  for (const auto pin : LED_PINS)
  {
    pinMode(pin, OUTPUT);
  }   
  
  resetAllLeds();
  
  randomSeed(analogRead(0));
}

void resetAllLeds()
{
  for (const auto pin : LED_PINS)
  {
    digitalWrite(pin, LOW);
  }   
}

int nextLed(int led) 
{
  return led >= (LEDS_NUM - 1) ? 0 : led + 1;
  /* the same but with if-else 
  if (led >= LEDS_NUM - 1)
  {
    return 0;
  }
  return led + 1;*/
}

int curLed = LEDS_NUM - 1;
int lastButtonState = 0;
long randomNum = 0;

void loop() 
{
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) 
  { 
    if (lastButtonState == LOW)
    {
      resetAllLeds();  
      curLed = LEDS_NUM;
    }
    Serial.println(curLed);
    digitalWrite(LED_PINS[curLed], LOW);    
    digitalWrite(LED_PINS[curLed = nextLed(curLed)], HIGH);
    delay(ANIMATION_DELAY);
  }
  else // buttonState == LOW
  {
    if (lastButtonState == HIGH)
    {
      resetAllLeds();  
      randomNum = random(1, 6);
      
      Serial.println(randomNum);
    }
    
    for (int i = 0; i < LEDS_NUM; ++i)
    {
      if (i < randomNum)
      {
        digitalWrite(LED_PINS[i], HIGH);
      }
      else
      {
        digitalWrite(LED_PINS[i], LOW);  
      }
    }
  }
  lastButtonState = buttonState;
}

