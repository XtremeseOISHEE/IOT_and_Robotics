#define LEDButton 2  // GPIO2 for D4

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEDButton, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LEDButton, LOW);
  delay(500);                      
  
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(LEDButton, HIGH);
  delay(500);
}
