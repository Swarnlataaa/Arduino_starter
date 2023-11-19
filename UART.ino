Sending and receiving data over UART (Universal Asynchronous Receiver-Transmitter) for serial communication is a fundamental skill for interfacing with various devices, such as GPS modules, displays, or other microcontrollers. In this example, we'll use an Arduino to communicate with a GPS module via UART and display the received data on the Serial Monitor.

**Components Needed**:
- Arduino board (e.g., Arduino Uno)
- GPS module with UART interface
- Jumper wires

**Circuit Connection**:
1. Connect the GPS module's TX (transmit) pin to the Arduino's RX (receive) pin (e.g., connect GPS TX to Arduino RX).
2. Connect the GPS module's RX (receive) pin to the Arduino's TX (transmit) pin (e.g., connect GPS RX to Arduino TX).
3. Connect the GPS module's GND (ground) pin to the Arduino's GND.

**Arduino Code**:

```cpp
#include <SoftwareSerial.h>

SoftwareSerial gpsSerial(2, 3); // RX, TX

void setup()
{
    Serial.begin(9600);    // Serial Monitor for debugging
    gpsSerial.begin(9600); // GPS module communication
}

void loop()
{
    if (gpsSerial.available())
    {
        char c = gpsSerial.read();
        Serial.write(c);
    }
}
```

**Explanation**:
1. We include the SoftwareSerial library to create a software-based serial communication interface (`gpsSerial`) on pins 2 and 3. These pins are used for the RX (receive) and TX (transmit) connections to the GPS module.

2. In the `setup()` function, we initialize the communication with the GPS module and set the baud rate to match the module's configuration (usually 9600 baud).

3. The `loop()` function continuously checks if data is available from the GPS module using `gpsSerial.available()`.

4. If data is available, we read it character by character using `gpsSerial.read()` and send it to the Serial Monitor using `Serial.write()`. This allows you to see the GPS data on the Serial Monitor.

To use this code, connect your GPS module, upload the sketch to your Arduino, and open the Serial Monitor. You should see the GPS data stream displayed in the Serial Monitor. The specific data format from your GPS module may vary, so you may need to parse and process the data according to your requirements.

Remember to configure the GPS module to the appropriate baud rate and data format as specified in its datasheet or documentation.

This example can serve as a starting point for interfacing with various UART-based devices like GPS modules, GSM modules, or displays, allowing you to exchange data with them and use the received information in your projects.