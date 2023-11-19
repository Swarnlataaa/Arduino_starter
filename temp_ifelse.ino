const int temperaturePin = A0; // Analog input pin for the temperature sensor

void setup()
{
    Serial.begin(9600); // Initialize serial communication for debugging
}

void loop()
{
    // Read the temperature from the sensor
    int temperature = analogRead(temperaturePin);

    // Convert the analog value to temperature in Celsius
    float celsius = (temperature * 0.48876);

    // Check the temperature and print a message
    if (celsius < 20.0)
    {
        Serial.println("It's too cold!");
    }
    else if (celsius >= 20.0 && celsius < 25.0)
    {
        Serial.println("The temperature is just right.");
    }
    else
    {
        Serial.println("It's getting warm.");
    }

    delay(1000); // Delay for smoother serial output
}
