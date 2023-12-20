from imu import MPU6050
from machine import I2C,Pin
import math
import time
 
i2c=I2C(0, sda=Pin(16), scl=Pin(17), freq=400000)
mpu = MPU6050(i2c)
 
roll=0
pitch=0
 
while True:
    xAccel=mpu.accel.x
    yAccel=mpu.accel.y
    zAccel=mpu.accel.z
    pitch=math.atan(yAccel/zAccel)
    roll=math.atan(xAccel/zAccel)
    pitchDeg=pitch/(2*math.pi)*360
    rollDeg=roll/(2*math.pi)*360
    print('pitch: ',pitchDeg, 'roll: ',rollDeg)
    time.sleep(.05)