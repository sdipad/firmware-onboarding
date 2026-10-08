#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin()
{
    initialized = bme.begin(BMEConstants::I2C_ADDRESS);

    return initialized;
}

float BMEI2CInterface::readTemperature()
{
    if (!initialized)
    {
        // If the sensor is not initialized, return a default value (e.g., 0.0)
        return 0.0f;
    }

    return bme.readTemperature();
}