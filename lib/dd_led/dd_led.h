#ifndef LED_H
#define LED_H

#include <stdint.h>

#define DD_LED_OUTPUT 1

enum ledState{
    LED_OFF = 0,
    LED_ON,
    LED_TOGGLE
};

typedef struct{
    uint8_t pin;
    void (*setOutput)(uint8_t pin, uint8_t state);
    void (*setValue)(uint8_t pin, uint8_t state);
    void (*toggle)(uint8_t pin);
} led_t;

void myLedSetup(led_t* led,
                void (*setOutput)(uint8_t pin, uint8_t state),
                void (*setValue)(uint8_t pin, uint8_t state),
                void (*toggle)(uint8_t pin));
void myLedArduinoSetup(led_t* led, uint8_t pin);
void ledOn(led_t* led);
void ledOff(led_t* led);
void ledToggle(led_t* led);

#endif /* LED_H */