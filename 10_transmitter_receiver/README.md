# 10. Radio transmitter and receiver

## Description
Tranmitter board is contnuously sending messages via radio channnel. Receiver board gets the messages 
and prints them to the console output.

## Hardware used
* 2 * Arduino Uno R3
* 2 * NRF24L01

## New hardware knowledge
* NRF24L01

## New C++ knowledge
* switch

## Requirements
* [RF24](https://github.com/nRF24/RF24) library must be imported to Arduino IDE (available in Arduino IDE library manager).

## Notes
* This example can be used to test NRF24L01 radio modules
* There is one sketch for the transmitter and the receiver
* Arduino SPI pins from ICSP head are connected to GPIO pins in the following way:
  * ICSP 4 (MOSI) -> GPIO 11
  * ICSP 1 (MISO) -> GPIO 12
  * ICSP 3 (SCK) -> GPIO 13 




