// =====================
// Ethernet - MUST PUT IN MAIN
// =====================
#define ETH_PHY_MDIO 0
#define ETH_PHY_ADDR 1
#define ETH_PHY_MDC 16
#define ETH_PHY_POWER 33
#define ETH_PHY_TYPE ETH_PHY_LAN8720
#define ETH_CLK_MODE ETH_CLOCK_GPIO17_OUT

// Must be after #define
#include <ETH.h>
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

