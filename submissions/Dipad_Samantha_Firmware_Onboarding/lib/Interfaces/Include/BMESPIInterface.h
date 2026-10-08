#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class BMESPIInterface
{
public:

    BMESPIInterface() = default;
    
    bool begin();
    float readTemperature();

private:
    Adafruit_BME280 bme;  // BME280 sensor object
    bool initialized = false;  // Flag to track if the sensor is initialized

};
using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;