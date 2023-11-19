const int numReadings = 5;
int temperatures[numReadings];

void setup()
{
    Serial.begin(9600); // Initialize serial communication for debugging
}

void loop()
{
    // Read temperature values and store them in the array
    for (int i = 0; i < numReadings; i++)
    {
        temperatures[i] = analogRead(A0);
        delay(1000); // Delay for 1 second between readings
    }

    // Calculate the average temperature
    int sum = 0;
    for (int i = 0; i < numReadings; i++)
    {
        sum += temperatures[i];
    }
    float average = float(sum) / numReadings;

    // Print the average temperature to the serial monitor
    Serial.print("Average Temperature: ");
    Serial.println(average);

    delay(5000); // Delay for 5 seconds before the next reading
}
