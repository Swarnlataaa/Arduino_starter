int count = 1;

void setup()
{
    Serial.begin(9600); // Initialize serial communication for debugging
}

void loop()
{
    while (count <= 5)
    {
        Serial.println(count);
        count++;
        delay(1000); // Wait for 1 second
    }
    // The loop will keep counting and printing until count reaches 6.
}
