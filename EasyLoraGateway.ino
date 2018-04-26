// =====================
// Ethernet
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
// Lora
// =====================
#define LORA_SS 23
#define LORA_SCK  18
#define LORA_MOSI 5
#define LORA_MISO 36
#define LORA_DIO012 39
#include <SPI.h>
#include <LoRa.h>

// ===================================================
// Main Program
// ===================================================
void setup() {
   setupSerial();
   setupLED();
   
   // Delay to easily see log in serial connection
   delay(5000);
   setupEthernet();
   delay(5000);
   setupLora();
}

void loop() {  
  receiveLoraMessage();
  //testHttpGet();
}
