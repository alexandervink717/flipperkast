#include <Wire.h>
#include <Arduino.h>

#include "sensor.h"
#include "../config.h"

const int MPUaddr = 0x68;

void sensorSetup()
{
    // tilt
    Wire.beginTransmission(MPUaddr); // open connection
    Wire.write(0x6B);                // PWR_MGMT_1 register
    Wire.write(0);                   // set to zero (wakes up the MPU-6050)
    Wire.endTransmission(true);      // close connection


}

bool sensorBallDetectedLow()
{
    // Implementation for detecting a ball
    return false;
}


bool bumperDetected()
{
    // Implementation for detecting a bumper
    return false;
}

bool flipperButton(char LorR)
{
    // Implementation for detecting the left flipper button
    return false;
}

int16_t acX, acY, acZ, totalXY;

bool tilted()
{
    Wire.beginTransmission(MPUaddr);    // open connection
    Wire.write(0x3B);                   // start with register 0x3B (ACCEL_XOUT_H)
    Wire.endTransmission(false);        // keep connection open
    Wire.requestFrom(MPUaddr, 6, true); // request 6 registers
    int acXH = Wire.read();             // register 0x3B
    int acXL = Wire.read();             // register 0x3C
    int acYH = Wire.read();             // register 0x3D
    int acYL = Wire.read();             // register 0x3E
    int acZH = Wire.read();             // register 0x3F
    int acZL = Wire.read();             // register 0x40

    //combine high and low bytes and take absolute values
    acX = abs((acXH << 8) | acXL);
    acY = abs((acYH << 8) | acYL);
    acZ = abs((acZH << 8) | acZL);

    totalXY = acX + acY;
    
    if (totalXY > DemplePuntForTilt)
    {
        return true;
    } else
    {
        return false;
    }
    
}