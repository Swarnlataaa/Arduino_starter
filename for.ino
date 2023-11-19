const int ledPin = 13; // Digital output pin for the LED

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    for (int i = 0; i < 5; i++)
    {
        digitalWrite(ledPin, HIGH); // Turn the LED on
        delay(500);                 // Wait for 0.5 seconds
        digitalWrite(ledPin, LOW);  // Turn the LED off
        delay(500);                 // Wait for 0.5 seconds
    }
    // The LED will blink 5 times, and the loop will repeat.
}
