# 5. Dice game (binary)

## Description 
When the button is pressed, four LEDs perform a simple animation, when the button is released, 
LEDs show a random number between 1 and 12 in binary representation

## Hardware used
* Arduino Uno R3
* Breadboard
* 4 * 1 KOhm resistor
* 4 * LED
* 1 * 10 KOhm resistor
* 1 * Button

## New hardware knowledge

## New C++ knowledge
* classes: constructors, destructors, public/private members, in-class initializers, const member functions
* dynamic memory (new/delete) (optional)
* separating code to different files
* references, return-by-reference 
* bitwise shift operators
* Arduino libraries

## Notes
* Button is a simple class, LedLine uses dynamic memory, but it's presented as a library so one can avoid explaining
it at the moment and come back to it in the following examples (e.g. 8. Ultrasonic) 

## Requirements
* LedLine library must be imported to Arduino IDE. See libraries/README.md and libraries/LedLine


