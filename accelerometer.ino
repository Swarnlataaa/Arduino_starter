/*BNO055*/
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

#define BNO055_SAMPLERATE_DELAY_MS (100)

Adafruit_BNO055 myIMU = Adafruit_BNO055();

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    myIMU.begin();
    delay(1000);
    int8_t temp = myIMU.getTemp();
    myIMU.setExtCrystalUse(true);
}

void loop()
{
    // put your main code here, to run repeatedly:
    imu::Vector<3> acc = myIMU.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);

    Serial.print(acc.x());
    Serial.print(",");
    Serial.print(acc.y());
    Serial.print(",");
    Serial.println(acc.z());

    delay(BNO055_SAMPLERATE_DELAY_MS);
}