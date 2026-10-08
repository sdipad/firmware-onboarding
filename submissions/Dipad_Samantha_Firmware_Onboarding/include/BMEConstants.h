#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    // BME280 I2C address.
    // Most breakout boards use 0x76 or 0x77.
    constexpr uint8_t I2C_ADDRESS = 0x76;

    // Arduino Uno onboard LED.
    constexpr uint8_t LED_PIN = LED_BUILTIN;

    // SPI chip-select pin.
    constexpr uint8_t SPI_CS_PIN = 10;

    // Temperature range used to map temperature to blink speed.
    constexpr float MIN_TEMPERATURE_C = 0.0f;
    constexpr float MAX_TEMPERATURE_C = 40.0f;

    // Blink interval limits in milliseconds.
    constexpr unsigned long SLOW_BLINK_INTERVAL_MS = 100;
    constexpr unsigned long FAST_BLINK_INTERVAL_MS = 1000;

    // How often the temperature is sampled.
    constexpr unsigned long SENSOR_READ_INTERVAL_MS = 250;
}
