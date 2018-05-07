// ===================================================
// Put all pin mappings and library here
// ===================================================
// ====================================
// Serial
// ====================================
#define BAUD_RATE 9600

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
// MQTT
// =====================
#include <MQTT.h>

// =====================
// LoRa
// =====================
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

// =====================
// OTA
// =====================
#include <ArduinoOTA.h>

// =====================
// rOTA
// =====================
#include <HttpFOTA.h>

// =====================
// LED
// =====================
#define LED       32

// =====================
// PREFERENCES
// =====================
#include <Preferences.h>




