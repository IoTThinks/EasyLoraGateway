// https://github.com/256dpi/arduino-mqtt
// =====================
// MQTT
// =====================
#include <MQTT.h>

// Definitions
#define mqttBrokerServer "broker.shiftr.io"
#define mqttNamespace "vinhdat82~easyloragateway"
#define mqttUsername "iotthinks"
#define mqttSecret "easyloragateway"
#define mqttTopic_FromNodes "/iotthinks/easyloragateway/nodes/from/messages"

MQTTClient mqttClient;

unsigned long lastMillis = 0;

String MQTT_Status = "Not Initialized";
String MQTT_Lastsent_Msg = "--No data--";

void setupMQTT() {
  // Should be connected to internet
  mqttClient.begin(mqttBrokerServer, netClient);
  mqttClient.onMessage(mqttMessageReceived);

  connectToMQTT();
}

void connectToMQTT() {
  while (!eth_connected) {
    Serial.println("[MQTT] ETH not connected. Try to reconnect ETH.");
    setupEthernet();
    delay(1000);
  }

  while (!mqttClient.connect(mqttNamespace, mqttUsername, mqttSecret)) {
    Serial.println("[MQTT] MQTT not connected. Try to reconnect to MQTT.");
    delay(1000);
  }

  Serial.println("[MQTT] Connected to MQTT.");
  MQTT_Status = "OK";
  
  mqttClient.subscribe("/hello");
  // mqttClient.unsubscribe("/hello");
}

void mqttMessageReceived(String &topic, String &payload) {
  Serial.println("[MQTT]<= Received message from MQTT: " + payload + " [Topic: " + topic + "]");
}

void publishToMQTT(String topic, String message) {
  Serial.println("[MQTT]=> Send message to MQTT: " + message + " [Topic: " + topic + "]");
  
  //The loop() function is a built in function that will read the receive and send buffers
  // and process any messages it finds.
  mqttClient.loop(); // Why need this?
  delay(10);
  
  if (!mqttClient.connected()) {
    connectToMQTT();
  }

  mqttClient.publish(topic, message);
  MQTT_Lastsent_Msg = message;
}

void forwardNodeMessageToMQTT(String message)
{
  publishToMQTT(mqttTopic_FromNodes, message);  
}

void testMQTT() {
  // publish a message roughly every second.
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
    publishToMQTT("/hello", "Easy Lora Gateway");
  }
}
