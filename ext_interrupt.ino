const int buttonPin = 2; // External interrupt pin
volatile int buttonPresses = 0;

void setup()
{
    pinMode(buttonPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, FALLING);
    Serial.begin(9600);
}

void loop()
{
    // Your main code goes here
}

void buttonInterrupt()
{
    buttonPresses++;
    Serial.print("Button Presses: ");
    Serial.println(buttonPresses);
}
