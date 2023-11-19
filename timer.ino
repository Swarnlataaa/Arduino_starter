const int ledPin = 13; // LED connected to digital pin 13
unsigned long previousMillis = 0;
const long interval = 1000; // 1 second interval

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;
        digitalWrite(ledPin, !digitalRead(ledPin)); // Toggle the LED state
    }
}
