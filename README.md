# Easy LoRa Gateway
Easy LoRa Gateway is an OPEN SOURCE and easy-to-use LoRa Gateway to connect all types of sensors within 1-10km for home and small business users.

HAVE FUN.

## A. GOALS:
- Business goal: We can commercialize combo of long range sensors to home users, residential houses, buildings and firms. Or even farming areas.
- Technical goal: The gateway is to communicate with IoT sensors within 1-10km. Then the gateway will forward the messages to a centralized server for further processing.

## B. FEATURES
In this project, we would like to create a simple and easy single channel LoRa Gateway for programmers and LoRa lovers to use. This gateway will use an ESP32 with LoRa module (AI-Thinker 32 - SX1278).
Easy LoRa Gateway will have the following features:
1. Ability to receive and transmit Lora packets concurrently (but in single channel of course)
2. Ability to forward Lora messages to a MQTT centralized servers
3. Ability to trigger HTTP requests and ping via Ethernet.
4. Ability to save information to an optional SD Card.
5. Ability to be cloud managed via cloud portral.
6. Ability to display a local web server for basic configuration of all the above.

## C. PROGRESS
### C1. Main contributors
1. Kevin Le V. Dat (HCM)- Computer Science - Engineer - ASP.NET, Linux, Networking, Security
2. Bui H. Cuong (HCM) - Electrical and Electronic Engineering - Engineer - Hardware innovator
3. Dao D. Nam (HCM) - Mechatronic Engineering - Engineer in automotive domain.
4. Truong C. Tham (Da Nang) - Mechatronics - Engineer - R&D for IoT gateway in farming
5. Le C. Binh (HCM) - Senior embedded developer - 4-year experience in automotive domain, 2 year experience in IoT startups
6. Huynh T. Dat (HCM) -  Electronic and Telecommunications - Student of HCMUT - Experience in MQTT, Thingsboard, LoRa
7. Le C. V. Khai (Da Nang) - Electrical & Telecommunication Engineering - Student of Da Nang University of Technology - Web programing, ESP8266, MQTT, LoRa
8. Nguyen T. Trieu (HCM) - QA Engineer - LoRa, ESP, STM, Android App, RF
9. Le H. Cong (HCM) - Electrical & Telecommunication Engineering - Networking, System, Security - New to IoT
10. Le V. Hieu (Ha Noi) - Hanoi University of Science and Technology - Student - High tech farming
11. Nguyen A. Tuan (Ha Noi) -  Military Technology Academy - Student - IoT projects in school.
12. Bui G. Thinh (Da Nang) - Engineer - 2- year experience in ESP8266 and ESP32
13. Nguyen N. Hau (HCM) - Posts and Telecommunications Institute of Technology - Student - Nodejs and realtime monitor with webserver
14. Le Q. Sang (HCM) - Posts and Telecommunications Institute of Technology - Student - Linux, AVR, STM32
15. Cao A. Khoi (USA) - Iowa State University - Computer Engineering - Embedded Systems and Electronic design - IoT Monitor system in farming (using a chain-linked network + 3G), MQTT on ESP32, 8266 platforms, BLE, Android and RTOS.
16. Le V. Thien (HCM) - Meetup 1
17. Nguyen M. Canh (HCM) - Meetup 1

### C2. Source code and Documentation
- Source code: https://github.com/IoTThinks/EasyLoraGateway
- Documentation links: https://github.com/IoTThinks/EasyLoraGateway/wiki
- File Drive (For file documentation and ebooks): https://tinyurl.com/EasyLoRa-Drive

### C3. What is NEW?
<b>Updated 2018-05-02</b>
- Added hardware page for Easy LoRa gateway and node.
- Added base code for Easy LoRa Node.

<b>Updated 2018-04-26</b>
- Support LoRa, MQTT and local Web server
- Able to received Lora packets from a LoRa node and forward to MQTT server.
- Added a simple Web server to display the gateway status

### C4. Todo
<b>New features</b>
- Auto update sketch (firmware) to the gateway
- Save gateway configuration to flash
- Create basic web authentication for management web
- Listen Before Talk to avoid packet collision. (Nguyen Huynh - 2018-04-27)
- Auto retransmit packets if not received an acknowledge from gateway / node. (Suggested by Anthony Vu - 2018-04-28)
- Add Option to gateway: Pull or push messages to nodes (Suggested by Gnourt Gnoc Maht - 2018-05-02)

 ### C5. Useful links
<b>Helpful third-party tools:</b>
- MQTT Client: Used to publish and subcribe MQTT message: http://www.jensd.de/apps/mqttfx/
