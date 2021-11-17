#ifndef tl
#define tl

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class Canbus {
  public:
    // Constructor
    Canbus(int greenLED = 0);

    // Methods
    void on();
    void off();

  private:
};
#endif