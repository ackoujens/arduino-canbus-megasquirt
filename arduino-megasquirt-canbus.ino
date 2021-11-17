/*
  MegaSquirt CAN bus

  Sends and receives data from and to MegaSquirt.

  A lot of data can be sent over a CAN network and makes it easier on wiring.
  Everything can be connected to this CAN node and act as an extention to the
  current MegaSquirt expandability.

  by Jens Ackou
*/

#include "src/Canbus.h"
#include "src/Button.h"

// Objects
Canbus canbusInstance1(1);

// the setup function runs once when you press reset or power the board
void setup() {
}

// the loop function runs over and over again forever
void loop() {
  canbusInstance1.on();
  delay(5000);
  canbusInstance1.off();
  delay(5000);

  Serial.println("LOOP DONE");
}