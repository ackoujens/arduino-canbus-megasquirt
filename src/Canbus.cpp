#include "Canbus.h"

int _greenLED;
  
Canbus::Canbus(int greenLED) {
    _greenLED = greenLED;

    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
}

void Canbus::on() {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void Canbus::off() {
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}