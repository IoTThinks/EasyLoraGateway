// ====================================
// Lora
// https://github.com/sandeepmistry/arduino-LoRa/blob/master/API.md
// ====================================
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



void setupLora() {
  Serial.println("Setting up LoRa");
  
  SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_SS);
  LoRa.setPins(LORA_SS, LORA_RESET, LORA_DIO012);
  LoRa.setSpreadingFactor(LORA_SF);
  LoRa.setCodingRate4(LORA_CR); //4/5
  LoRa.setSignalBandwidth(LORA_BW);
  LoRa.setPreambleLength(LORA_PREAMBLE_LENGTH);
  delay(1000);
  
  while (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");    
    delay(1000);
  }

  loraStartOKLED();

  // register the receive callback
  //LoRa.onReceive(onReceive);

  // put the radio into receive mode
  //LoRa.receive();
}

void onReceive(int packetSize) {
  // received a packet
  Serial.print("Received packet '");

  // read packet
  for (int i = 0; i < packetSize; i++) {
    Serial.println((char)LoRa.read());
  }

  // print RSSI of packet
  Serial.print("' with RSSI ");
  Serial.println(LoRa.packetRssi());
}

int counter = 0;
void sendLoraMessage(){
  Serial.println("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("This is Easy Lora Gateway ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(5000);
}

String receiveLoraMessage(){
    // try to parse packet
  int packetSize = LoRa.parsePacket();
  String receivedLoraMessage="";
  
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      receivedLoraMessage +=(char)LoRa.read();
    }

    // Print message
    Serial.print(receivedLoraMessage);
    
    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
    dataReceivedLED();
  }

  return receivedLoraMessage;
}

void testReceiveLoraMessage() {
  receiveLoraMessage();
}

