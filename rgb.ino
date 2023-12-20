int redPin = 8;
int greenPin = 9;
int bluePin = 10;
String myColor;
String msg = "What Colour Do You Want?";
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:
    Serial.println(msg);
    while (Serial.available() == 0)
    {
    }
    myColor = Serial.readString();

    if (myColor == "red")
    {
        digitalWrite(redPin, HIGH);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, LOW);
    }
    if (myColor == "green")
    {
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, HIGH);
        digitalWrite(bluePin, LOW);
    }
    if (myColor == "blue")
    {
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, HIGH);
    }
    if (myColor == "off")
    {
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, LOW);
    }

    if (myColor == "aqua")
    {
        digitalWrite(redPin, LOW);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 80);
    }
}