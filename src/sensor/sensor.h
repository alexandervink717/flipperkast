#ifndef SENSOR_H
#define SENSOR_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void sensorSetup(); // Initialize the sensor
bool sensorBallDetectedLow(); // Check if a ball is detected at low
bool bumperDetected(); // Check if a bumper is detected
bool flipperButtonRechts(); // Check if the right flipper button is pressed
bool flipperButtonLinks(); // Check if the left flipper button is pressed
bool tilted(); // Check if the machine is tilted

#ifdef __cplusplus
}
#endif

#endif
