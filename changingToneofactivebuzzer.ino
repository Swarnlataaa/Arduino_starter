int buzzPin = 8;
int dt1 = 1;
int dt2 = 2;
int j;
void setup()
{
    // put your setup code here, to run once:
    pinMode(buzzPin, OUTPUT);
}

void loop()
{
    for (j = 1; j <= 100; j = j + 1)
    {
        digitalWrite(buzzPin, HIGH);
        delay(dt1);
        digitalWrite(buzzPin, LOW);
        delay(dt1);
    }
    for (j = 1; j <= 100; j = j + 1)
    {
        digitalWrite(buzzPin, HIGH);
        delay(dt2);
        digitalWrite(buzzPin, LOW);
        delay(dt2);
    }
}