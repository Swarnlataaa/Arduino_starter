const int ledPin = 13; // Digital output pin for the LED

void setup()
{
    Serial.begin(9600);      // Initialize serial communication at 9600 baud
    pinMode(ledPin, OUTPUT); // Set the LED pin as an output
}

void loop()
{
    if (Serial.available() > 0)
    {                                      // Check if there is incoming data
        char receivedChar = Serial.read(); // Read the incoming character
        if (receivedChar == 'H')
        { // If 'H' is received, turn the LED on
            digitalWrite(ledPin, HIGH);
        }
        else if (receivedChar == 'L')
        { // If 'L' is received, turn the LED off
            digitalWrite(ledPin, LOW);
        }
    }
}
