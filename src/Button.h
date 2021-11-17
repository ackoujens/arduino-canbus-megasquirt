#ifndef btn
#define btn

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class Button {
    public:
        Button(int buttonPin);

        bool isPressed();
};
#endif