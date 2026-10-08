#include "LEDController.h"

void LEDController::begin()
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);
    ledState = LOW;
    lastBlinkTime = millis();
}

void LEDController::update(float temperature)
{
    unsigned long currentTime = millis();

    if (currentTime - lastBlinkTime >= blinkInterval)
    {
        lastBlinkTime = currentTime;
        ledState = !ledState; // Toggle LED state
        digitalWrite(BMEConstants::LED_PIN, ledState);
    }
}

void LEDController::setBlinkInterval(float temperature)
{
    // Map the temperature to a blink interval between SLOW_BLINK_INTERVAL_MS and FAST_BLINK_INTERVAL_MS
    if (temperature < BMEConstants::MIN_TEMPERATURE_C)
    {
        blinkInterval = BMEConstants::SLOW_BLINK_INTERVAL_MS;
    }
    else if (temperature > BMEConstants::MAX_TEMPERATURE_C)
    {
        blinkInterval = BMEConstants::FAST_BLINK_INTERVAL_MS;
    }
    else
    {
        // Linear interpolation between the two intervals based on temperature
        float ratio = (temperature - BMEConstants::MIN_TEMPERATURE_C) / 
                      (BMEConstants::MAX_TEMPERATURE_C - BMEConstants::MIN_TEMPERATURE_C);
        blinkInterval = static_cast<unsigned long>(
            BMEConstants::SLOW_BLINK_INTERVAL_MS + 
            ratio * (BMEConstants::FAST_BLINK_INTERVAL_MS - BMEConstants::SLOW_BLINK_INTERVAL_MS)
        );
    }
}