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
    imu::Vector<3> gyro = myIMU.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
    imu::Vector<3> mag = myIMU.getVector(Adafruit_BNO055::VECTOR_MAGNETOMETER);

    Serial.print(acc.x());
    Serial.print(",");
    Serial.print(acc.y());
    Serial.print(",");
    Serial.print(acc.z());
    Serial.print(",");

    Serial.print(gyro.x());
    Serial.print(",");
    Serial.print(gyro.y());
    Serial.print(",");
    Serial.print(gyro.z());
    Serial.print(",");
    Serial.print(mag.x());
    Serial.print(",");
    Serial.print(mag.y());
    Serial.print(",");
    Serial.println(mag.z());

    delay(BNO055_SAMPLERATE_DELAY_MS);
}