char userChoice;

void setup()
{
    Serial.begin(9600); // Initialize serial communication for debugging
}

void loop()
{
    do
    {
        Serial.println("Choose A or B: ");
        while (!Serial.available())
        {
            // Wait for user input
        }
        userChoice = Serial.read();
    } while (userChoice != 'A' && userChoice != 'B');
    Serial.print("You chose: ");
    Serial.println(userChoice);
}
