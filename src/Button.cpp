#include "Button.h"

int _buttonPin;

Button::Button(int buttonPin) {
    _buttonPin = buttonPin;
    pinMode(_buttonPin, INPUT_PULLUP);
}

bool Button::isPressed() {
    return !digitalRead(_buttonPin);
}