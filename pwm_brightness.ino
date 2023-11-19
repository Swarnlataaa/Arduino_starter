const int sensorPin = A0;              // Analog input pin for LM35 sensor
const float referenceVoltage = 5.0;    // Reference voltage (5V) for Arduino
const float temperatureFactor = 100.0; // LM35 temperature sensor factor

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    // Read the analog value from the LM35 sensor
    int sensorValue = analogRead(sensorPin);

    // Convert the analog value to temperature in degrees Celsius
    float temperature = (sensorValue / 1023.0) * referenceVoltage * temperatureFactor;

    // Print the temperature to the Serial Monitor
    Serial.print("Analog Value: ");
    Serial.print(sensorValue);
    Serial.print(", Temperature (°C): ");
    Serial.println(temperature);

    delay(1000); // Delay for 1 second before the next reading
}
