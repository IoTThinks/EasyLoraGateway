// Provide Web GUI to manage the gateway
// https://randomnerdtutorials.com/esp32-web-server-arduino-ide/
/*
 * Rui Santos 
 * Complete Project Details http://randomnerdtutorials.com
*/
WiFiServer server(80);

// Client variables 
char linebuf[80];
int charcount=0;

void setupWebServer() {
  // Can not get if starts OK
  server.begin();
  Serial.println("Web server should be at http://" + ETH_IP);
}

void runWebServer() {
  // listen for incoming clients
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New client");
    memset(linebuf,0,sizeof(linebuf));
    charcount=0;
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        //read char by char HTTP request
        linebuf[charcount]=c;
        if (charcount<sizeof(linebuf)-1) charcount++;
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println();
          client.println("<!DOCTYPE HTML><html><head>");
          client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"></head>");
          client.println("<body style=\"background-color:lightblue;\">");
          client.println("<h1>Easy LoRa Gateway</h1>");
          client.println("<h2>1. Basic Information</h2>");
          client.println("<p>LED Status: " + LED_STATUS + "</p>");
          client.println("<p>LAN Status: " + ETH_STATUS + "</p>");
          client.println("<p>LoRa Status: " + LORA_STATUS + "</p>");
          client.println("<p>MQTT Status: " + MQTT_STATUS + "</p>");
          client.println("<h2>2. Gateway Activities</h2>");
          client.println("<p>Last Received Lora Message: " + LORA_LASTRECEIVED_MSG + "</p>");
          client.println("<p>Last Forwarded MQTT Message: " + MQTT_LASTSENT_MSG + "</p>");
          client.println("<h2>3. Configuration</h2>");
          client.println("<p>LED <a href=\"onled\"><button>ON</button></a>&nbsp;<a href=\"offled\"><button>OFF</button></a></p>");         
          client.println("</body>");
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
          if (strstr(linebuf,"GET /onled") > 0){
            Serial.println("LED ON");
            onLED();
          }
          else if (strstr(linebuf,"GET /offled") > 0){
            Serial.println("LED OFF");
            offLED();
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
    client.stop();
    Serial.println("client disconnected");
  }
}
