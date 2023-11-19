const int ledPin = 13;

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    digitalWrite(ledPin, HIGH);
    delay(1000); // Delay for 1 second
    digitalWrite(ledPin, LOW);
    delay(1000); // Delay for 1 second
}
