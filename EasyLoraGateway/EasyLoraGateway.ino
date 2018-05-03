// Include required EasyLoraGateway libraries
#include "EasyLoraGateway.h"

// ===================================================
// Main Program
// ===================================================
// This runs once when the gateway boots. 
// The delay is not neccessary and just to avoid component re-initizalized by other compopents.
// setupXXX functions are placed in module files
void setup() {  
   setupSerial();
   setupLED();  
   setupEthernet();
   delay(1000);
   setupMQTT();
   setupLoRa();   
   setupWebServer();
   delay(10000);
   setupOTA();
   delay(1000);
   displayLEDErrorCode();
}

// Do the real works here
void loop() {  
  // Working
  receiveAndForwardLoRaMessage();
  processMQTTMessages();
  runWebServer();
  
  // TODO: When to accept OTA update?
  waitingForOTA();
}

// Need to flush buffer to send or receive MQTT messages
void processMQTTMessages() {
  // Send / receive from MQTT buffer
  flushMQTTBuffer();
}

// Receive LoRa message and send to MQTT Server
void receiveAndForwardLoRaMessage(){
  String message = receiveLoRaMessage();
  if(message != ""){    
    forwardNodeMessageToMQTT(message);
    dataReceivedLED();
  }
}

