
const int LED_PINS[] = {7, 8, 9, 10, 11, 12};
const int DELAY = 200;

void setup()
{
  for (const auto pin : LED_PINS)
  {
    pinMode(pin, OUTPUT);
  }   
}

void loop()
{
  for (const auto pin : LED_PINS) 
  {
    digitalWrite(pin, HIGH);
    delay(DELAY);                 
    digitalWrite(pin, LOW); 
    delay(DELAY);    
  }
  
}
