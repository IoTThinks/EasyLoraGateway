// Provide Web GUI to manage the gateway
// https://randomnerdtutorials.com/esp32-web-server-arduino-ide/
// Global variables
String WEBSERVER_Status = "Not Initialized";
WiFiServer webServer(80);

// Client variables 
char linebuf[80];
int charcount=0;

void setupWebServer() {
  // Can not get if starts OK
  webServer.begin();
  Serial.println("[WEBSERVER] Web server should be at http://" + ETH_Ip);
  WEBSERVER_Status = "OK";
}

void runWebServer() {
  // listen for incoming clients
  WiFiClient webClient = webServer.available();
  if (webClient) {
    Serial.println("[WEBSERVER] New webClient");
    memset(linebuf,0,sizeof(linebuf));
    charcount=0;
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (webClient.connected()) {
      if (webClient.available()) {
        char c = webClient.read();
        Serial.write(c);
        //read char by char HTTP request
        linebuf[charcount]=c;
        if (charcount<sizeof(linebuf)-1) charcount++;
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          webClient.println("HTTP/1.1 200 OK");
          webClient.println("Content-Type: text/html");
          webClient.println("Connection: close");  // the connection will be closed after completion of the response
          webClient.println();
          webClient.println("<!DOCTYPE HTML><html><head>");
          webClient.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"></head>");
          webClient.println("<body style=\"background-color:lightblue;\">");
          webClient.println("<h1>Easy LoRa Gateway</h1>");
          webClient.println("<h2>1. Basic Information</h2>");
          webClient.println("<p>LAN Status: " + ETH_Status + "</p>");
          webClient.println("<p>LoRa Status: " + LORA_Status + "</p>");
          webClient.println("<p>MQTT Status: " + MQTT_Status + "</p>");
          webClient.println("<p>OTA Status: " + OTA_Status + "</p>");
          webClient.println("<h2>2. Gateway Activities</h2>");
          webClient.println("<p>Last Received Lora Message: " + LORA_Lastreceived_Msg + "</p>");
          webClient.println("<p>Last Forwarded MQTT Message: " + MQTT_Lastsent_Msg + "</p>");
          webClient.println("<h2>3. Configuration</h2>");
          webClient.println("<p>LED <a href=\"ledon\"><button>ON</button></a>&nbsp;<a href=\"ledoff\"><button>OFF</button></a></p>");
          webClient.println("<p>OTA <a href=\"otaon\"><button>ON</button></a>&nbsp;<a href=\"otaoff\"><button>OFF</button></a></p>");
          webClient.println("</body>");
          webClient.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
          if (strstr(linebuf,"GET /ledon") > 0){
            Serial.println("[WEBSERVER] LED ON");
            onLED();
          }
          else if (strstr(linebuf,"GET /ledoff") > 0){
            Serial.println("[WEBSERVER] LED OFF");
            offLED();
          }
          else if (strstr(linebuf,"GET /otaon") > 0){
            Serial.println("[WEBSERVER] OTA ON");
            onOTA();
          }
          else if (strstr(linebuf,"GET /otaoff") > 0){
            Serial.println("[WEBSERVER] OTA OFF");
            offOTA();
          }
         
          // you're starting a new line
          currentLineIsBlank = true;
          memset(linebuf,0,sizeof(linebuf));
          charcount=0;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);

    // close the connection:
    webClient.stop();
    Serial.println("[WEBSERVER] webClient disconnected");
  }
}
