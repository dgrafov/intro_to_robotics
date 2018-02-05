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
* dynamic memory (new/delete)
* separating code to different files
* references, return-by-reference 
* bitwise shift operators

## Notes: 
* Button is a simple class, LedLine can be re-written without dynamic arraynot to put too much in one example. 
LedLine class is used later in ultrasonic example (8) - there we can improve it with a dynamically allocated array


