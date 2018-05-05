# Easy LoRa Gateway
Easy LoRa Gateway is an easy-to-use LoRa Gateway for home users and small businesses.

In this project, we would like to create a simple and easy single channel LoRa Gateway for programmers and LoRa lovers to use. This gateway will use an ESP32 with LoRa module (AI-Thinker 32 - SX1278).
Easy LoRa Gateway will have the following features:
1. Ability to receive and transmit Lora packets concurrently (but in single channel of course)
2. Ability to forward Lora messages to a MQTT centralized servers
3. Ability to trigger HTTP requests and ping via Ethernet.
4. Ability to save information to an optional SD Card.
5. Ability to be cloud managed via cloud portral.
6. Ability to display a local web server for basic configuration of all the above.

HAVE FUN.

## What is NEW?
<b>Updated 2018-05-02</b>
- Added hardware page for Easy LoRa gateway and node.
- Added base code for Easy LoRa Node.

<b>Updated 2018-04-26</b>
- Support LoRa, MQTT and local Web server
- Able to received Lora packets from a LoRa node and forward to MQTT server.
- Added a simple Web server to display the gateway status

## TODO
<b>New features</b>
- Auto update sketch (firmware) to the gateway
- Save gateway configuration to flash
- Create basic web authentication for management web
- Listen Before Talk to avoid packet collision. (Nguyen Huynh - 2018-04-27)
- Auto retransmit packets if not received an acknowledge from gateway / node. (Suggested by Anthony Vu - 2018-04-28)
- Add Option to gateway: Pull or push messages to nodes (Suggested by Gnourt Gnoc Maht - 2018-05-02)

 ## LINKS
<h2>Helpful third-party tools:</h2>
- MQTT Client: Used to publish and subcribe MQTT message: http://www.jensd.de/apps/mqttfx/
