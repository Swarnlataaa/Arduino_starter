const int potentiometerPin = A0; // Analog input pin for the potentiometer

void setup()
{
    Serial.begin(9600); // Initialize serial communication for debugging
}

void loop()
{
    // Read the analog value from the potentiometer (0-1023)
    int sensorValue = analogRead(potentiometerPin);

    // Print the sensor value to the serial monitor
    Serial.println("Potentiometer Value: " + String(sensorValue));

    delay(100); // Delay for smoother serial output
}
