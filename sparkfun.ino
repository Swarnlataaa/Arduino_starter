#include <SparkFunBME280.h>

BME280 sensor; // Create an instance of the BME280 sensor

void setup()
{
    Serial.begin(9600);
    if (!sensor.begin())
    {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1)
            ;
    }
}

void loop()
{
    delay(2000);
    float tempC = sensor.readTempC();
    float humidity = sensor.readFloatHumidity();
    float pressurePa = sensor.readFloatPressure();

    Serial.print("Temperature (C): ");
    Serial.println(tempC, 2);
    Serial.print("Humidity (%): ");
    Serial.println(humidity, 2);
    Serial.print("Pressure (Pa): ");
    Serial.println(pressurePa, 2);
}
