// ====================================
// Ethernet
// ====================================
// https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFi/examples
static bool eth_connected = false;
WiFiClient netClient;
String ETH_STATUS;
String ETH_IP;

void setupEthernet()
{
    WiFi.onEvent(WiFiEvent);
    ETH.begin();
}

void WiFiEvent(WiFiEvent_t event)
{
  switch (event) {
    case SYSTEM_EVENT_ETH_START:
      Serial.println("ETH Started");
      //set eth hostname here
      ETH.setHostname("EasyLoraGateway");
      break;
    case SYSTEM_EVENT_ETH_CONNECTED:
      Serial.println("ETH Connected");
      ETH_STATUS = "Connected. No IP Yet";
      break;
    case SYSTEM_EVENT_ETH_GOT_IP:
      Serial.print("ETH MAC: ");
      Serial.print(ETH.macAddress());
      Serial.print(", IPv4: ");
      ETH_IP = ETH.localIP().toString();
      Serial.print(ETH_IP);
      if (ETH.fullDuplex()) {
        Serial.print(", FULL_DUPLEX");
      }
      Serial.print(", ");
      Serial.print(ETH.linkSpeed());
      Serial.println("Mbps");
      eth_connected = true;
      ethStartOKLED();
      ETH_STATUS = "Connected. IP: " + ETH_IP;
      break;
    case SYSTEM_EVENT_ETH_DISCONNECTED:
      Serial.println("ETH Disconnected");
      eth_connected = false;
      ETH_STATUS = "Not Connected";
      break;
    case SYSTEM_EVENT_ETH_STOP:
      Serial.println("ETH Stopped");
      eth_connected = false;
      ETH_STATUS = "Not Connected";
      break;
    default:
      break;
  }
}

void httpGet(const char * host, uint16_t port)
{
  Serial.print("\nconnecting to ");
  Serial.println(host);

  //WiFiClient client;
  if (!netClient.connect(host, port)) {
    Serial.println("connection failed");
    return;
  }
  
  netClient.printf("GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
  while (netClient.connected() && !netClient.available());
  while (netClient.available()) {
    Serial.write(netClient.read());
  }

  Serial.println("closing connection\n");
  netClient.stop();
}

void testHttpGet()
{
  if (eth_connected) {
    httpGet("iotthinks.com", 80);
  }
  else  {
    Serial.println("Ethernet not connected");
  }
  delay(1000);
}
