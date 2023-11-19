#include <AFMotor.h>

AF_DCMotor motor1(1); // Motor 1 is connected to M1 and M2
AF_DCMotor motor2(2); // Motor 2 is connected to M3 and M4

char command; // Variable to store received command from Bluetooth

void setup()
{
    Serial.begin(9600); // Set the baud rate to your Bluetooth module.
}

void loop()
{
    if (Serial.available() > 0)
    {
        command = Serial.read(); // Read the incoming command from Bluetooth

        // Perform action based on the received command
        switch (command)
        {
        case 'F': // Move forward
            motor1.setSpeed(255);
            motor2.setSpeed(255);
            motor1.run(FORWARD);
            motor2.run(FORWARD);
            break;
        case 'B': // Move backward
            motor1.setSpeed(255);
            motor2.setSpeed(255);
            motor1.run(BACKWARD);
            motor2.run(BACKWARD);
            break;
        case 'L': // Turn left
            motor1.setSpeed(200);
            motor2.setSpeed(200);
            motor1.run(BACKWARD);
            motor2.run(FORWARD);
            break;
        case 'R': // Turn right
            motor1.setSpeed(200);
            motor2.setSpeed(200);
            motor1.run(FORWARD);
            motor2.run(BACKWARD);
            break;
        case 'S': // Stop
            motor1.setSpeed(0);
            motor2.setSpeed(0);
            motor1.run(RELEASE);
            motor2.run(RELEASE);
            break;
        }
    }
}
