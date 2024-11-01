// Define the pin for analog reading
const int analogPin = A3;    // Pin connected to AN of LV-MaxSonar-EZ3
const int ledPin = 13;       // Pin connected to the LED (you can change this pin as needed)

// Define the range for turning on the LED
const float lowerThreshold = 23.0;  // Lower limit of the range in inches
const float upperThreshold = 25.0;  // Upper limit of the range in inches

void setup() {
  // Start the serial communication
  Serial.begin(9600);

  // Set the pin modes
  pinMode(analogPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the analog value from the sensor
  int sensorValue = analogRead(analogPin);

  // Convert the analog value to voltage (assuming a 5V system)
  float voltage = sensorValue * (5.0 / 1024.0);

  // Convert the voltage to distance (in inches)
  float distanceInches = voltage / 0.0098;  // LV-MaxSonar-EZ3 outputs 9.8mV per inch

  // Round the distance value to avoid floating-point precision issues
  float roundedDistance = round(distanceInches * 10.0) / 10.0;

  // Check if the distance is within the range (23 to 25 inches)
  if (roundedDistance >= lowerThreshold && roundedDistance <= upperThreshold) {
    // If the distance is within the range, turn on the LED
    digitalWrite(ledPin, HIGH);
    Serial.println("Distance is within 23 to 25 inches. LED is ON.");
    Serial.println(roundedDistance);
  } else {
    // If the distance is outside the range, turn off the LED
    digitalWrite(ledPin, LOW);
    Serial.println("Distance is outside 23 to 25 inches. LED is OFF.");
     Serial.println(roundedDistance);
  }

  // Wait for a short period before taking another reading
  delay(500);
}
