#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int CE_PIN = 7;
const int CSN_PIN = 8;

const byte address[] = "00001";

RF24 radio(CE_PIN, CSN_PIN); 

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
