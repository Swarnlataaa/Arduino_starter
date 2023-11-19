#include <DHT.h>

#define DHTPIN 2      // Pin where the DHT sensor is connected
#define DHTTYPE DHT22 // DHT 22 (AM2302) sensor is used

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
    Serial.begin(9600);
    dht.begin();
}

void loop()
{
    delay(2000); // Wait for 2 seconds
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\tTemperature: ");
    Serial.println(temperature);
}
