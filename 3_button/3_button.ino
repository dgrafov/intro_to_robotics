const int BUTTON_PIN = 2;    
const int LED_PIN =  13; //built in LED  

void setup() 
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() 
{
  // 1) classic if-else code
  int buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == HIGH) 
  {
    digitalWrite(LED_PIN, HIGH);
  } 
  else 
  {
  
    digitalWrite(LED_PIN, LOW);
  }

  // 2) if-else is actually not needed here  
  //digitalWrite(LED_PIN, digitalRead(BUTTON_PIN));

  // 3) even if we want to revert the behavior, ternary operator will do the thing   
  //digitalWrite(LED_PIN, digitalRead(BUTTON_PIN) == HIGH ? LOW : HIGH);
}
