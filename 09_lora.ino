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

void setupLora() {
  Serial.println("Setting up LoRa");
  
  SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_SS);
  LoRa.setPins(LORA_SS, -1, LORA_DIO012);
  LoRa.setSpreadingFactor(7);
  LoRa.setCodingRate4(5); //4/5
  LoRa.setSignalBandwidth(125E3);
  LoRa.setPreambleLength(8);
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

void receiveLoraMessage(){
    // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
    dataReceivedLED();
  }
}

