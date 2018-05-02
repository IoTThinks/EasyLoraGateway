// =====================================================
// SAMPLE EASY LORA NODE - BASED ON HELTEC LORA WIFI 32
// =====================================================
#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>  
#include "SSD1306.h"

// To map ESP32's PIN to LoRa module
#define SCK     5    // GPIO5  -- SX1278's SCK
#define MISO    19   // GPIO19 -- SX1278's MISO
#define MOSI    27   // GPIO27 -- SX1278's MOSI
#define SS      18   // GPIO18 -- SX1278's CS
#define RST     14   // GPIO14 -- SX1278's RESET
#define DI0     26   // GPIO26 -- SX1278's IRQ(Interrupt Request)
#define BAND    433E6

// Temp, to count sent messages
unsigned int counter = 0;

// Init OLED
SSD1306 display(0x3c, 4, 15);

// Packet content
String rssi = "RSSI --";
String packSize = "--";
String packet ;

void setup() {
  // Init OLED
  pinMode(16,OUTPUT);
  pinMode(25,OUTPUT);
  
  digitalWrite(16, LOW);    // set GPIO16 low to reset OLED
  delay(50); 
  digitalWrite(16, HIGH); // while OLED is running, must set GPIO16 in high

  // Init Serial
  Serial.begin(9600);
  while (!Serial);

  // Sending LoRa message
  Serial.println();
  Serial.println("LoRa Sender Test");

  // Init LoRa module via SPI in ESP32
  SPI.begin(SCK,MISO,MOSI,SS);

  // Set LoRa's most important PINs
  LoRa.setPins(SS,RST,DI0);

  // Set frequency for LoRa
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  
  //  LoRa.onReceive(cbk);
  //  LoRa.receive();

  // Init the OLED and font
  Serial.println("init ok");
  display.init();
  display.flipScreenVertically();  
  display.setFont(ArialMT_Plain_10);
  delay(1500);
}

void loop() {
  // Clear OLED and set font
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);

  // Display sending LoRa packet
  display.drawString(0, 0, "Sending packet: ");
  display.drawString(90, 0, String(counter));
  display.display();

  // Sending LoRa packet as Hello 1, Hello 2...
  LoRa.beginPacket();
  LoRa.print("Hello ");
  LoRa.print(counter);
  LoRa.endPacket();

  // Increase counter for next message.
  counter++;

  // Blink the LED for each LoRa send
  digitalWrite(25, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(25, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
