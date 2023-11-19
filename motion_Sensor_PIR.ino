const int pirPin = 2; // Digital input pin for the PIR sensor

void setup()
{
    Serial.begin(9600);     // Initialize serial communication for debugging
    pinMode(pirPin, INPUT); // Set the PIR pin as an input
}

void loop()
{
    int motionDetected = digitalRead(pirPin);

    if (motionDetected)
    {
        Serial.println("Motion Detected!");
    }
    else
    {
        Serial.println("No Motion");
    }

    delay(1000); // Delay for smoother serial output
}
