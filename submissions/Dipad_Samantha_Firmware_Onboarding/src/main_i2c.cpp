#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

BMEI2CInterface bmeI2C;
LEDController led;

void setup()
{
    Serial.begin(9600);
    led.begin();

    if(!bmeI2C.begin())
    {
        Serial.println("Failed to initialize BME280 sensor");
        while(1); // Halt execution if sensor initialization fails
    }

    Serial.println("BME280 sensor initialized successfully");

}

void loop()
{
    float temperature = bmeI2C.readTemperature();

    Serial.print("Temperature: ");
    Serial.println(temperature, 2);

    if (isnan(temperature))
    {
        Serial.println("ERROR: BME280 returned NaN");
    }

    led.update(temperature);

    delay(BMEConstants::SENSOR_READ_INTERVAL_MS);
}