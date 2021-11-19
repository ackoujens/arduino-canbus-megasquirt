#include "Canbus.h"
#include <Arduino.h>
#include "mcp_can.h"

// Constants
const int SPI_CS_PIN = 10;

// Variables
long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];
char msgString[128];
#define CAN_INT 2 //set INT to pin 2 (receiving)

MCP_CAN CAN(SPI_CS_PIN); //set CS pin to 10
byte _data[8] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
  
Canbus::Canbus() {}

void Canbus::init(){
    if(CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK){
        Serial.println("Canbus: MCP2515 Initialized Successfully!");
    } else { Serial.println("Canbus: Error Initializing MCP2515..."); }
  
    CAN.setMode(MCP_NORMAL);   // Change to normal mode to allow messages to be transmitted
    pinMode(CAN_INT, INPUT); //configuring pin for /INT input (receiving)
}

void Canbus::set() {
    Serial.println("Canbus: EMPTY set() METHOD");
}

void Canbus::send() {
    // send data:  ID = 0x100, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
    byte sendStatus = CAN.sendMsgBuf(0x100, 0, 8, _data);
    if(sendStatus == CAN_OK){
        Serial.println("Canbus: Message Sent Successfully!");
    } else { Serial.println("Canbus: Error Sending Message..."); }
    
    delay(100);   // send data per 100ms
}
/*
void Canbus::receive() {
    if(!digitalRead(CAN_INT)){ //If CAN0_INT pin is low, read receive buffer
    
        CAN.readMsgBuf(&rxId, &len, rxBuf); //Read data: len = data length, buf = data byte(s)
    
        if((rxId & 0x80000000) == 0x80000000){ //Determine if ID is standard (11 bits) or extended (29 bits)
            sprintf(msgString, "Extended ID: 0x%.8lX  DLC: %1d  Data:", (rxId & 0x1FFFFFFF), len);
        } else { sprintf(msgString, "Standard ID: 0x%.3lX       DLC: %1d  Data:", rxId, len); }
        Serial.print(msgString);
  
        if((rxId & 0x40000000) == 0x40000000){ //Determine if message is a remote request frame.
            sprintf(msgString, " REMOTE REQUEST FRAME");
            Serial.print(msgString);
        } else {
            for(byte i = 0; i<len; i++) {
                sprintf(msgString, " 0x%.2X", rxBuf[i]);
                Serial.print(msgString);
            }
        }
    }
    Serial.println();
}
*/