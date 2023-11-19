#include <DHT.h>
#include <DHT_U.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define RELAY_PIN 5

char auth[] = "YourAuthToken";
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

DHT_Unified dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

void sendSensorData()
{
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    float temperature = event.temperature;
    Blynk.virtualWrite(V5, temperature);

    dht.humidity().getEvent(&event);
    float humidity = event.relative_humidity;
    Blynk.virtualWrite(V6, humidity);
}

void setup()
{
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    dht.begin();
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW);
    timer.setInterval(10000L, sendSensorData);
}

void loop()
{
    Blynk.run();
    timer.run();
}

BLYNK_WRITE(V1)
{
    int state = param.asInt();
    digitalWrite(RELAY_PIN, state);
}
