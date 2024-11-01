#define TOUCH_PIN 10 

#define ledpin 12 // Define the pin where the touch sensor is connected

void setup() {
  Serial.begin(9600);        // Start serial communication
  pinMode(TOUCH_PIN, INPUT); // Set touch sensor pin as input
  pinMode(ledpin,OUTPUT);
}

void loop() {
  int touchState = digitalRead(TOUCH_PIN);  // Read the touch sensor

  if (touchState == HIGH) {  // If sensor is touched
    digitalWrite(ledpin,HIGH);
    Serial.println("touched");
  } else {
    Serial.println("Not touched");
    digitalWrite(ledpin,LOW);
  }
  
  delay(200);  // Add a small delay for readability
}