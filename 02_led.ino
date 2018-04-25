// ====================================
// LED
// ====================================
#define LED       32

void setupLED() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}

void onLED() {
  digitalWrite(LED, LOW);
}

void offLED() {  
  digitalWrite(LED, HIGH);
}

void loraStartOKLED() {
  Serial.println("Lora starts OK");
  for(int i = 0; i < 10; i++)
  {
    onLED();
    delay(100);
    offLED();
    delay(100);
  }
}

void dataReceivedLED() {
  onLED();
  delay(50);
  offLED();
}

