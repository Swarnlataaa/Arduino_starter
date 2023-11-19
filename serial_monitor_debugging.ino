int sensorValue = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    sensorValue = analogRead(A0);
    Serial.print("Sensor Value: ");
    Serial.println(sensorValue);
    delay(1000);
}
