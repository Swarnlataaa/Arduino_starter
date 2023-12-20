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
    uint8_t system, gyro, accel, mg = 0;
    myIMU.getCalibration(&system, &gyro, &accel, &mg);
    imu::Vector<3> acc = myIMU.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);

    Serial.print(acc.x());
    Serial.print(",");
    Serial.print(acc.y());
    Serial.print(",");
    Serial.print(acc.z());
    Serial.print(",");
    Serial.print(accel);
    Serial.print(",");
    Serial.print(gyro);
    Serial.print(",");
    Serial.print(mg);
    Serial.print(",");
    Serial.println(system);

    delay(BNO055_SAMPLERATE_DELAY_MS);
}
