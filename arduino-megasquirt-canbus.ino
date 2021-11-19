/*
  MegaSquirt CAN bus

  Sends and receives data from and to MegaSquirt.

  A lot of data can be sent over a CAN network and makes it easier on wiring.
  Everything can be connected to this CAN node and act as an extention to the
  current MegaSquirt expandability.

  by Jens Ackou
*/

//#include <SPI.h>
#include "src/Canbus.h"

//int analogValue = 0;
Canbus MSCan;

void setup() {
  Serial.begin(9600); // baud rate serial monitor
  MSCan.init();
  Serial.println("Main: Setup completed");
}

void loop() {
  MSCan.set();
  MSCan.send();
  //MSCan.receive();
  delay(1000);
}
