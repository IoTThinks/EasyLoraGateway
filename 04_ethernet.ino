// ====================================
// Ethernet
// ====================================
// https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFi/examples
static bool eth_connected = false;
WiFiClient netClient;
String ETH_Status;
String ETH_Ip;

void setupEthernet()
{
    WiFi.onEvent(WiFiEvent);
    ETH.begin();
}

void WiFiEvent(WiFiEvent_t event)
{
  switch (event) {
    case SYSTEM_EVENT_ETH_START:
      Serial.println("[ETH] ETH Started");
      //set eth hostname here
      ETH.setHostname("EasyLoraGateway");
      break;
    case SYSTEM_EVENT_ETH_CONNECTED:
      Serial.println("[ETH] ETH Connected");
      ETH_Status = "Connected. No IP Yet";
      break;
    case SYSTEM_EVENT_ETH_GOT_IP:
      Serial.print("[ETH] ETH MAC: ");
      Serial.print(ETH.macAddress());
      Serial.print(", IPv4: ");
      ETH_Ip = ETH.localIP().toString();
      Serial.print(ETH_Ip);
      if (ETH.fullDuplex()) {
        Serial.print(", FULL_DUPLEX");
      }
      Serial.print(", ");
      Serial.print(ETH.linkSpeed());
      Serial.println("Mbps");
      eth_connected = true;
      ETH_Status = "OK";
      break;
    case SYSTEM_EVENT_ETH_DISCONNECTED:
      Serial.println("[ETH] ETH Disconnected");
      eth_connected = false;
      ETH_Status = "Disconnected";
      break;
    case SYSTEM_EVENT_ETH_STOP:
      Serial.println("[ETH] ETH Stopped");
      eth_connected = false;
      ETH_Status = "Stopped";
      break;
    default:
      break;
  }
}

void httpGet(const char * host, uint16_t port)
{
  Serial.print("\n[ETH] Connecting to ");
  Serial.println(host);

  //WiFiClient client;
  if (!netClient.connect(host, port)) {
    Serial.println("[ETH] Connection failed");
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
  httpGet("iotthinks.com", 80);
}
