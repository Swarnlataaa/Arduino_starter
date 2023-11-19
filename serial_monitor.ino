const int sensorPin = A0; // Analog input pin for the sensor

void setup()
{
    Serial.begin(9600); // Initialize serial communication at 9600 baud
}

void loop()
{
    int sensorValue = analogRead(sensorPin); // Read sensor data
    Serial.print("Sensor Value: ");
    Serial.println(sensorValue); // Print sensor reading
    delay(1000);                 // Delay for 1 second
}
