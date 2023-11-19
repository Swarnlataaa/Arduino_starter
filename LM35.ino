const int tempPin = A0; // Analog input pin for the LM35 sensor

void setup()
{
    Serial.begin(9600); // Initialize serial communication for debugging
}

void loop()
{
    // Read the analog value from the LM35
    int sensorValue = analogRead(tempPin);

    // Convert the analog value to temperature in Celsius
    float temperature = (sensorValue * 0.48876);

    // Print the temperature to the serial monitor
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");

    delay(1000); // Delay for smoother serial output
}
