const int buttonPin = 2;  // Define the digital input pin for the button
int buttonState = 0;     // Variable to store the button state (LOW or HIGH)

void setup() {
  pinMode(buttonPin, INPUT);  // Set the buttonPin as an input
  Serial.begin(9600);         // Initialize serial communication for debugging
}

void loop() {
  // Read the button state
  buttonState = digitalRead(buttonPin);

  // Check if the button is pressed
  if (buttonState == HIGH) {
    Serial.println("Button is pressed");
  } else {
    Serial.println("Button is not pressed");
  }

  delay(100);  // Delay to avoid rapid readings
}
