#include "Wire.h"
#include "SparkFun_SHTC3.h"

SHTC3 mySHTC3; // Declare an instance of the SHTC3 class

void setup() {
  Serial.begin(115200); // Begin Serial communication
  while (!Serial) {
    ; // Wait for serial port to connect
  }

  Wire.begin(); // Initialize I2C communication
  Serial.println("Starting SHTC3 sensor...");

  if (mySHTC3.begin() == SHTC3_Status_Nominal) {
    Serial.println("SHTC3 started successfully");
  } else {
    Serial.println("SHTC3 initialization failed!");
  }
}

void loop() {
  // Update the sensor readings
  if (mySHTC3.update() == SHTC3_Status_Nominal) {
    float temperatureC = mySHTC3.toDegC(); // Temperature in Celsius
    float temperatureF = mySHTC3.toDegF(); // Temperature in Fahrenheit
    float humidity = mySHTC3.toPercent();  // Humidity in percentage

    // Print the results
    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.print(" °C / ");
    Serial.print(temperatureF);
    Serial.println(" °F");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  } else {
    Serial.println("Sensor reading failed!");
  }

  delay(2000); // Wait 2 seconds before next reading
}
