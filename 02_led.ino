// ====================================
// LED
// ====================================
#define LED       32
String LED_STATUS = "Not initalized";

void setupLED() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  LED_STATUS = "OK";
}

void onLED() {
  digitalWrite(LED, LOW);
}

void offLED() {  
  digitalWrite(LED, HIGH);
}

void ethStartOKLED() {
  Serial.println("ETH starts OK. Got IP.");
  for(int i = 0; i < 5; i++)
  {
    onLED();
    delay(50);
    offLED();
    delay(50);
  }
}

void loraStartOKLED() {
  Serial.println("Lora starts OK");
  for(int i = 0; i < 10; i++)
  {
    onLED();
    delay(50);
    offLED();
    delay(50);
  }
}

void dataReceivedLED() {
  onLED();
  delay(50);
  offLED();
}

