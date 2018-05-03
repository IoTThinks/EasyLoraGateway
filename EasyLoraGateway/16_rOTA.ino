// NOT WORKING YET
// ====================================
// Auto update firmware OTA via mqtt
// https://diyprojects.io/arduinoota-esp32-wi-fi-ota-wireless-update-arduino-ide
// http://www.iotsharing.com/2017/11/firmware-update-ota-for-esp32-using-http.html
// https://github.com/nhatuan84/esp32-http-fota
// ====================================
// Definitions
#define OTA_TOPIC "/iotthinks/easyloragateway/nodes/to/ota"

// Global variables
String OTA_Status = "OFF";

void setupROTA() {
  
}

void onOTA() {
  // TODO: CHECK MQTT connection
  OTA_Status = "ON";  
  mqttClient.subscribe(OTA_TOPIC);
  
  //The loop() function is a built in function that will read the receive and send buffers
  // and process any messages it finds.
  mqttClient.loop(); // Why need this?
  delay(10);
}

void offOTA() {
  // TODO: CHECK MQTT connection
  OTA_Status = "OFF";  
  mqttClient.unsubscribe(OTA_TOPIC);
}

// =================================
void getNewOTA() {
  if (!mqttClient.connected()) {
    connectToMQTT();
  }

  mqttClient.subscribe(OTA_TOPIC);
}

