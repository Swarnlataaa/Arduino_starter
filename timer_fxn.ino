const int ledPin = 13;            // Digital output pin for the LED
unsigned long previousMillis = 0; // Stores the last time the LED was updated
const long interval = 1000;       // Interval in milliseconds (1 second)

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    unsigned long currentMillis = millis(); // Get the current time

    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;             // Save the last time the LED was updated
        digitalWrite(ledPin, !digitalRead(ledPin)); // Toggle the LED state
    }

    // Your other code can run here without blocking the LED blinking
}
