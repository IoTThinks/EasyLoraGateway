# EasyLoraGateway
EasyLoraGateway is an easy-to-use Lora Gateway for home users and small businesses.

In this project, we would like to create a simple and easy single channel Lora Gateway for programmers and Lora lovers to use. This gateway will use an ESP32 with Lora module (AI-Thinker 32 - SX1278) from CloudFermi http://www.cloudfermi.com.
EasyLoraGateway will have the following features:
1. Ability to receive and transmit Lora packets concurrently (but in single channel of course)
2. Ability to forward Lora messages to a centralized servers (MQTT?)
3. Ability to trigger HTTP requests and ping via Ethernet.
4. Ability to save information to an optional SD Card.
5. Ability to be cloud managed via cloud portral.
6. Ability to display a local web server for basic configuration of all the above.

We will have a full box package at http://iotthinks.com (Coming soon).
HAVE FUN.

<b>TODO - New features</b>
- Auto update sketch (firmware) to the gateway
- Save gateway configuration to flash
- Create basic web authentication for management web

<b>Updated 2018-04-26</b>
- Support Lora, MQTT and local Web server
- Able to received Lora packets from a Lora node and forward to MQTT server.
- Added a simple Web server to display the gateway status

 
<h2>Helpful third-party tools:</h2>
- MQTT Client: Used to publish and subcribe MQTT message: http://www.jensd.de/apps/mqttfx/
