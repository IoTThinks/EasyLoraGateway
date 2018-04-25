// ===================================================
// Main Program
// ===================================================
void setup() {
   setupSerial();
   setupLED();
   setupLora();
}

void loop() {
  //sendLoraMessage();
  receiveLoraMessage();
}
