const int ledPin = 9; // Digital PWM output pin for the LED

void setup()
{
    pinMode(ledPin, OUTPUT); // Set the LED pin as an output
}

void loop()
{
    // Change the LED brightness using PWM (0-255)
    for (int brightness = 0; brightness <= 255; brightness++)
    {
        analogWrite(ledPin, brightness);
        delay(10); // Delay for a smooth transition
    }

    for (int brightness = 255; brightness >= 0; brightness--)
    {
        analogWrite(ledPin, brightness);
        delay(10);
    }
}
