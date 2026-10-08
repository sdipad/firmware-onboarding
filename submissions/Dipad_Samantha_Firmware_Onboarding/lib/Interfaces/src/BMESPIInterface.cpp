#include "BMESPIInterface.h"

bool BMESPIInterface::begin()
{
    initialized = bme.begin(BMEConstants::SPI_CS_PIN
    );

    return initialized;
}

float BMESPIInterface::readTemperature()
{
    if (!initialized)
    {
        // If the sensor is not initialized, return a default value (e.g., 0.0)
        return 0.0f;
    }

    return bme.readTemperature();
}