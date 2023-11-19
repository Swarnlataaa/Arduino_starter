#include <NewPing.h>

#define TRIGGER_PIN 9
#define ECHO_PIN 10

NewPing sonar(TRIGGER_PIN, ECHO_PIN);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    delay(500);
    unsigned int distance = sonar.ping_cm();
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
}
