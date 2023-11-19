const int motor1PWM = 5;  // PWM control for Motor 1
const int motor1Dir1 = 4; // Direction control 1 for Motor 1
const int motor1Dir2 = 3; // Direction control 2 for Motor 1

const int motor2PWM = 6;  // PWM control for Motor 2
const int motor2Dir1 = 7; // Direction control 1 for Motor 2
const int motor2Dir2 = 8; // Direction control 2 for Motor 2

void setup()
{
    Serial.begin(9600);
    pinMode(motor1PWM, OUTPUT);
    pinMode(motor1Dir1, OUTPUT);
    pinMode(motor1Dir2, OUTPUT);

    pinMode(motor2PWM, OUTPUT);
    pinMode(motor2Dir1, OUTPUT);
    pinMode(motor2Dir2, OUTPUT);
}

void loop()
{
    if (Serial.available() > 0)
    {
        char command = Serial.read();

        switch (command)
        {
        case 'F': // Move forward
            moveForward();
            break;
        case 'B': // Move backward
            moveBackward();
            break;
        case 'L': // Turn left
            turnLeft();
            break;
        case 'R': // Turn right
            turnRight();
            break;
        case 'S': // Stop
            stopMoving();
            break;
        }
    }
}

void moveForward()
{
    digitalWrite(motor1Dir1, HIGH);
    digitalWrite(motor1Dir2, LOW);
    analogWrite(motor1PWM, 255);

    digitalWrite(motor2Dir1, HIGH);
    digitalWrite(motor2Dir2, LOW);
    analogWrite(motor2PWM, 255);
}

void moveBackward()
{
    digitalWrite(motor1Dir1, LOW);
    digitalWrite(motor1Dir2, HIGH);
    analogWrite(motor1PWM, 255);

    digitalWrite(motor2Dir1, LOW);
    digitalWrite(motor2Dir2, HIGH);
    analogWrite(motor2PWM, 255);
}

void turnLeft()
{
    digitalWrite(motor1Dir1, LOW);
    digitalWrite(motor1Dir2, HIGH);
    analogWrite(motor1PWM, 200);

    digitalWrite(motor2Dir1, HIGH);
    digitalWrite(motor2Dir2, LOW);
    analogWrite(motor2PWM, 200);
}

void turnRight()
{
    digitalWrite(motor1Dir1, HIGH);
    digitalWrite(motor1Dir2, LOW);
    analogWrite(motor1PWM, 200);

    digitalWrite(motor2Dir1, LOW);
    digitalWrite(motor2Dir2, HIGH);
    analogWrite(motor2PWM, 200);
}

void stopMoving()
{
    digitalWrite(motor1Dir1, LOW);
    digitalWrite(motor1Dir2, LOW);
    analogWrite(motor1PWM, 0);

    digitalWrite(motor2Dir1, LOW);
    digitalWrite(motor2Dir2, LOW);
    analogWrite(motor2PWM, 0);
}
