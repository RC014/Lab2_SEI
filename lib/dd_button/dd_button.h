#ifndef DD_BUTTON_H
#define DD_BUTTON_H

#include <stdint.h>
#include <stdio.h>

/**
 * @brief Struct to hold button driver state and function pointers.
 * Modeled after led_t in dd_led.
 */
typedef struct {
    uint8_t pin;
    
    // Function pointer to read the raw pin state
    int (*readPin)(uint8_t pin);
    
    // File stream to allow stdio operations (scanf)
    FILE stream;
} button_t;

/**
 * @brief Generic setup function for the button driver.
 * Configures function pointers and initializes the stdio stream.
 * 
 * @param btn Pointer to the button structure.
 * @param readPin Function pointer to read hardware pin state.
 */
void myButtonSetup(button_t* btn,
                   int (*readPin)(uint8_t pin));

/**
 * @brief Arduino-specific setup.
 * Configures the pin as INPUT_PULLUP and sets up the stdin stream.
 * 
 * @param btn Pointer to the button structure.
 * @param pin The Arduino pin number.
 */
void myButtonArduinoSetup(button_t* btn, uint8_t pin);

#endif // DD_BUTTON_H
