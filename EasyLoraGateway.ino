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

// =====================
// OTA - MUST PUT IN MAIN
// =====================
#include <HttpFOTA.h>

// ===================================================
// Main Program
// ===================================================
void setup() {
   setupSerial();
   setupLED();  
   setupEthernet();
   delay(10000);
   setupMQTT();
   setupLora();   
   setupWebServer();
   delay(1000);
   setupOTA();
   delay(5000);
   displayLEDErrorCode();
}

void loop() {  
  //testReceiveLoraMessage();
  //testHttpGet();
  //testMQTT();
  receiveAndForwardLoraMessage();
  runWebServer();
  //getNewOTA();
}

void receiveAndForwardLoraMessage(){
  String message = receiveLoraMessage();
  if(message != ""){    
    forwardNodeMessageToMQTT(message);
  }
}

