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
void setup() {
   setupSerial();
   setupLED();  
   setupEthernet();
   delay(5000);
   setupMQTT();
   setupLora();
   delay(5000);
   setupWebServer();
}

void loop() {  
  //testReceiveLoraMessage();
  //testHttpGet();
  //testMQTT();
  receiveAndForwardLoraMessage();
  runWebServer();
}

void receiveAndForwardLoraMessage(){
  String message = receiveLoraMessage();
  if(message != ""){
    Serial.println("Forward to MQTT: " + message);
    publishToMQTT(message);
  }
}

