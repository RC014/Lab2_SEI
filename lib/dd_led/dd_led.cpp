#include "led.h"
#include <Arduino.h>

// Functii helper statice pentru platforma Arduino
static void arduino_setOutput(uint8_t pin, uint8_t state) {
    if (state) {
        pinMode(pin, OUTPUT);
    }
}
static void arduino_setValue(uint8_t pin, uint8_t state) {
    digitalWrite(pin, state);
}
static void arduino_toggle(uint8_t pin) {
    digitalWrite(pin, !digitalRead(pin));
}

/**
 * @brief Initializes the led_t struct with function pointers and sets up the pin.
 *
 * @param led Pointer to the led_t struct to initialize. The `pin` member must be set before calling.
 * @param setOutput Function pointer to set the pin direction (e.g., as output).
 * @param setValue Function pointer to set the pin's state (HIGH/LOW).
 * @param toggle Function pointer to toggle the pin's state.
 */
void myLedSetup(led_t* led,
                void (*setOutput)(uint8_t pin, uint8_t state),
                void (*setValue)(uint8_t pin, uint8_t state),
                void (*toggle)(uint8_t pin))
{
    if (!led) return;

    led->setOutput = setOutput;
    led->setValue = setValue;
    led->toggle = toggle;

    // Configure the pin as output
    if (led->setOutput) {
        led->setOutput(led->pin, DD_LED_OUTPUT);
    }
    // Set initial state to OFF
    if (led->setValue) {
        led->setValue(led->pin, LED_OFF);
    }
}

/**
 * @brief Functie de setup simplificata pentru mediul Arduino.
 *
 * @param led Pointer la structura led_t de initializat.
 * @param pin Pinul Arduino pentru LED.
 */
void myLedArduinoSetup(led_t* led, uint8_t pin) {
    if (!led) return;
    led->pin = pin;
    myLedSetup(led, arduino_setOutput, arduino_setValue, arduino_toggle);
}

void ledOn(led_t* led) {
    if (led && led->setValue) {
        led->setValue(led->pin, LED_ON);
    }
}

void ledOff(led_t* led) {
    if (led && led->setValue) {
        led->setValue(led->pin, LED_OFF);
    }
}

void ledToggle(led_t* led) {
    if (led && led->toggle) {
        led->toggle(led->pin);
    }
}
