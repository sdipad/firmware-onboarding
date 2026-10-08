#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

BMESPIInterface bmeSPI;
LEDController led;

void setup()
{
    Serial.begin(9600);
    led.begin();

    if(!bmeSPI.begin())
    {
        Serial.println("Failed to initialize BME280 sensor");
        while(1); // Halt execution if sensor initialization fails
    }

    Serial.println("BME280 sensor initialized successfully");
}

void loop()
{
    const float temperature = bmeSPI.readTemperature();

    Serial.print("Temperature (SPI): ");
    Serial.print(temperature);
    Serial.println(" °C");

    led.update(temperature);
    delay(BMEConstants::SENSOR_READ_INTERVAL_MS);
}