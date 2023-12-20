#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <math.h>
float thetaM;
float phiM;
float thetaFold = 0;
float thetaFnew;
float phiFold = 0;
float phiFnew;
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
    thetaM = -atan2(acc.x() / 9.8, acc.z() / 9.8) / 2 / 3.141592654 * 360;
    phiM = -atan2(acc.y() / 9.8, acc.z() / 9.8) / 2 / 3.141592654 * 360;
    phiFnew = .95 * phiFold + .05 * phiM;
    thetaFnew = .95 * thetaFold + .05 * thetaM;
    Serial.print(acc.x() / 9.8);
    Serial.print(",");
    Serial.print(acc.y() / 9.8);
    Serial.print(",");
    Serial.print(acc.z() / 9.8);
    Serial.print(",");
    Serial.print(accel);
    Serial.print(",");
    Serial.print(gyro);
    Serial.print(",");
    Serial.print(mg);
    Serial.print(",");
    Serial.print(system);
    Serial.print(",");
    Serial.print(thetaM);
    Serial.print(",");
    Serial.print(phiM);
    Serial.print(",");
    Serial.print(thetaFnew);
    Serial.print(",");
    Serial.println(phiFnew);

    phiFold = phiFnew;
    thetaFold = thetaFnew;

    delay(BNO055_SAMPLERATE_DELAY_MS);
}