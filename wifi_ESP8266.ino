#include <DHT.h>
#include <SoftwareSerial.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

#define WLAN_SSID "YourSSID"             // Wi-Fi network name
#define WLAN_PASS "YourPassword"         // Wi-Fi password
#define AIO_USERNAME "Your_AIO_Username" // Adafruit IO Username
#define AIO_KEY "Your_AIO_Key"           // Adafruit IO Key

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

SoftwareSerial esp8266(7, 8); // RX, TX

Adafruit_MQTT_Client mqtt(&esp8266, AIO_USERNAME, AIO_KEY);

void setup()
{
    Serial.begin(115200);
    dht.begin();

    esp8266.begin(115200);
    esp8266.println("AT+CWJAP=\"" + String(WLAN_SSID) + "\",\"" + String(WLAN_PASS) + "\"");
    while (!esp8266.find("OK"))
        ;

    Serial.println(F("Adafruit MQTT demo"));
    MQTT_connect();
}

void loop()
{
    MQTT_connect();

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t))
    {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }

    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.println(F("°C"));

    // Publish temperature and humidity data to Adafruit IO
    publishToAdafruitIO("temperature", t);
    publishToAdafruitIO("humidity", h);

    delay(60000); // Delay for one minute
}

void MQTT_connect()
{
    int8_t ret;

    if (mqtt.connected())
    {
        return;
    }

    Serial.print("Connecting to MQTT... ");
    while ((ret = mqtt.connect()) != 0)
    { // connect will return 0 for connected
        Serial.println(mqtt.connectErrorString(ret));
        Serial.println("Retrying MQTT connection in 5 seconds...");
        mqtt.disconnect();
        delay(5000); // wait 5 seconds
    }
    Serial.println("MQTT Connected!");
}

void publishToAdafruitIO(const char *feed, float value)
{
    Adafruit_MQTT_Publish mqtt_pub = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/" feed);
    if (!mqtt_pub.publish(value))
    {
        Serial.println(F("Failed to publish data to Adafruit IO!"));
    }
}
