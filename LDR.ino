const int ldrPin = A0; // Analog input pin for the LDR

void setup()
{
    Serial.begin(9600); // Initialize serial communication for debugging
}

void loop()
{
    // Read the analog value from the LDR
    int sensorValue = analogRead(ldrPin);

    // Print the LDR value to the serial monitor
    Serial.print("Light Intensity: ");
    Serial.println(sensorValue);

    delay(1000); // Delay for smoother serial output
}
