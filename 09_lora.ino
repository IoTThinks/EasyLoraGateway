// ====================================
// Lora
// https://github.com/sandeepmistry/arduino-LoRa/blob/master/API.md
// ====================================
#define LORA_SS 23
#define LORA_SCK  18
#define LORA_MOSI 5
#define LORA_MISO 36
#define LORA_DIO012 39
#include <SPI.h>
#include <LoRa.h>

// Definitions
// CC2530 ZNP SPI interface
#define LORA_SS   23
#define LORA_SCK   18
#define LORA_MOSI  5
#define LORA_MISO  36
#define LORA_DIO012      39
#define LORA_RESET  -1 // Not in used

#define LORA_SF 7
#define LORA_CR 4 //4/5
#define LORA_BW 125E3
#define LORA_PREAMBLE_LENGTH  8

// Status
String LORA_Status = "Not Initialized";
String LORA_Lastreceived_Msg ="--No data--";

// Setup Lora
void setupLora() {
  Serial.println("[LoRa] Setting up LoRa");
  
  SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_SS);
  LoRa.setPins(LORA_SS, LORA_RESET, LORA_DIO012);
  LoRa.setSpreadingFactor(LORA_SF);
  LoRa.setCodingRate4(LORA_CR); //4/5
  LoRa.setSignalBandwidth(LORA_BW);
  LoRa.setPreambleLength(LORA_PREAMBLE_LENGTH);
  delay(1000);
  
  while (!LoRa.begin(433E6)) {
    Serial.println("[LoRa] Starting LoRa failed!");    
    LORA_Status="FAILED";
    delay(1000);
  }

  LORA_Status = "OK";
}

// NOT tested yet
void sendLoraMessage(String message){
  Serial.println("[LoRa]=> Sending packet: " + message);

  // send packet
  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();
}

String receiveLoraMessage(){
    // try to parse packet
  int packetSize = LoRa.parsePacket();
  String receivedLoraMessage="";
  
  if (packetSize) {
    // received a packet
    Serial.print("[LoRa]<= Received packet: '");

    // read packet
    while (LoRa.available()) {
      receivedLoraMessage +=(char)LoRa.read();
    }

    // Print message
    Serial.print(receivedLoraMessage);
    LORA_Lastreceived_Msg = receivedLoraMessage;
    
    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }

  return receivedLoraMessage;
}

void testReceiveLoraMessage() {
  receiveLoraMessage();
}

