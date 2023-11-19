const int buttonPin = 2;        // Digital input pin for the button
volatile int buttonPresses = 0; // Counter for button presses

void setup()
{
    pinMode(buttonPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, RISING);
    Serial.begin(9600);
}

void loop()
{
    // Your code here, running continuously
    // You can print the buttonPresses value or perform other tasks
}

void buttonInterrupt()
{
    buttonPresses++; // Increment the button press count
}
