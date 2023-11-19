#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10                 // Slave Select Pin
#define RST_PIN 9                 // Reset Pin
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.

#define SERVO_PIN 6
Servo servo;

void setup()
{
    Serial.begin(9600); // Initialize serial communications with the PC
    SPI.begin();        // Init SPI bus
    mfrc522.PCD_Init(); // Init MFRC522 card

    servo.attach(SERVO_PIN); // Attach the servo motor to pin 6
    unlockDoor();            // Initially, unlock the door
}

void loop()
{
    // Look for new cards
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
    {
        // Print UID
        Serial.print("Card UID: ");
        dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
        Serial.println();

        // Check if the card is authorized
        if (isAuthorizedCard(mfrc522.uid.uidByte, mfrc522.uid.size))
        {
            Serial.println("Access granted");
            unlockDoor();
            delay(5000); // Keep the door unlocked for 5 seconds
            lockDoor();
        }
        else
        {
            Serial.println("Access denied");
        }

        // Halt PICC
        mfrc522.PICC_HaltA();
        // Stop encryption on PCD
        mfrc522.PCD_StopCrypto1();
    }
}

void dump_byte_array(byte *buffer, byte bufferSize)
{
    for (byte i = 0; i < bufferSize; i++)
    {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }
}

bool isAuthorizedCard(byte *cardUID, byte uidSize)
{
    // Replace the following line with the UID of your authorized card
    byte authorizedCard[] = {0xAA, 0xBB, 0xCC, 0xDD};

    if (uidSize != sizeof(authorizedCard))
    {
        return false;
    }

    for (byte i = 0; i < uidSize; i++)
    {
        if (cardUID[i] != authorizedCard[i])
        {
            return false;
        }
    }

    return true;
}

void unlockDoor()
{
    servo.write(90); // Assuming 90 degrees is the unlocked position
}

void lockDoor()
{
    servo.write(0); // Assuming 0 degrees is the locked position
}
