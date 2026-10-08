#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class BMEI2CInterface
{
public:

    BMEI2CInterface() = default;

    bool begin();
    float readTemperature();

private:
    Adafruit_BME280 bme;  // BME280 sensor object
    bool initialized = false;  // Flag to track if the sensor is initialized

};
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;