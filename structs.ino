struct Person
{
    String name;
    int age;
    char gender;
};

void setup()
{
    Serial.begin(9600); // Initialize serial communication for debugging

    // Create an instance of the Person struct
    Person person1;
    person1.name = "Alice";
    person1.age = 30;
    person1.gender = 'F';

    // Print the person's information to the serial monitor
    Serial.print("Name: ");
    Serial.println(person1.name);
    Serial.print("Age: ");
    Serial.println(person1.age);
    Serial.print("Gender: ");
    Serial.println(person1.gender);
}

void loop()
{
    // Your code here
}
