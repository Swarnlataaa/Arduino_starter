#include <LiquidCrystal.h>

const int temperaturePin = A0;  // Analog input for temperature sensor (LM35)
const int soilMoisturePin = A1; // Analog input for soil moisture sensor
const int fanPin = 7;           // Digital output for exhaust fan
const int pumpPin = 8;          // Digital output for water pump

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LCD display

void setup()
{
    Serial.begin(9600);
    pinMode(fanPin, OUTPUT);
    pinMode(pumpPin, OUTPUT);
    lcd.begin(16, 2); // Initialize the LCD
    lcd.clear();
    lcd.print("Greenhouse Ctrl");
}

void loop()
{
    // Read sensor values
    int temperature = analogRead(temperaturePin);
    int moisture = analogRead(soilMoisturePin);

    // Convert sensor readings to physical values
    float tempC = (temperature * 0.48876);
    int moisturePercentage = map(moisture, 1023, 0, 0, 100);

    // Display sensor data on the LCD
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(tempC);
    lcd.print("C");
    lcd.setCursor(8, 1);
    lcd.print("Moisture: ");
    lcd.print(moisturePercentage);
    lcd.print("%");

    // Control the fan based on temperature
    if (tempC > 30.0)
    {
        digitalWrite(fanPin, HIGH); // Turn on exhaust fan
    }
    else
    {
        digitalWrite(fanPin, LOW); // Turn off exhaust fan
    }

    // Control the water pump based on soil moisture
    if (moisturePercentage < 30)
    {
        digitalWrite(pumpPin, HIGH); // Turn on water pump
    }
    else
    {
        digitalWrite(pumpPin, LOW); // Turn off water pump
    }

    // Print sensor data to the serial monitor for debugging
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("°C, Moisture: ");
    Serial.print(moisturePercentage);
    Serial.println("%");

    delay(5000); // Read sensor data and control devices every 5 seconds
}
