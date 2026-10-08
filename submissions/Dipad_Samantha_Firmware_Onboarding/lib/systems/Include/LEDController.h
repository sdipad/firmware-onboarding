#pragma once
#include <Arduino.h>
#include <BMEConstants.h>

class LEDController
{
    public:
        LEDController() = default;
        void begin();
        void update(float temperature);

    private:
        void setBlinkInterval(float temperature);
        bool ledState = false;
        unsigned long lastBlinkTime = 0;
        unsigned long blinkInterval = BMEConstants::SLOW_BLINK_INTERVAL_MS;
};