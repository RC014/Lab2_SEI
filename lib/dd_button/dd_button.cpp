#include "dd_button.h"
#include <Arduino.h>

// Static reference to the active button for the stdin callback
// (Needed because standard FILE get/put callbacks don't always pass context in all AVR libc versions)
static button_t* active_stdin_button = NULL;

// Helper function that acts as the 'get' method for the stdio stream
static int button_getchar(FILE *stream) {
    if (!active_stdin_button || !active_stdin_button->readPin) {
        return _FDEV_EOF;
    }

    // State machine to alternate between sending the value and a delimiter (space)
    // This ensures scanf("%d") can read consecutive values correctly.
    static bool send_delimiter = false;

    if (send_delimiter) {
        send_delimiter = false;
        return ' '; // Return space as delimiter
    }

    send_delimiter = true;

    // Read the hardware
    int pin_state = active_stdin_button->readPin(active_stdin_button->pin);

    // Convert logic: INPUT_PULLUP means LOW is pressed.
    // We return '1' for Pressed, '0' for Released.
    if (pin_state == LOW) {
        return '1';
    } else {
        return '0';
    }
}

// Arduino-specific hardware read
static int arduino_readPin(uint8_t pin) {
    return digitalRead(pin);
}

void myButtonSetup(button_t* btn, int (*readPin)(uint8_t pin)) {
    if (!btn) return;

    btn->readPin = readPin;

    // Initialize the stream structure manually for AVR-Libc
    // We set the get function to our wrapper
    btn->stream.get = button_getchar;
    btn->stream.put = NULL; // Read-only
    btn->stream.flags = _FDEV_SETUP_READ;
    btn->stream.udata = NULL; 

    // Assign this button as the global stdin source
    active_stdin_button = btn;
    stdin = &btn->stream;
}

void myButtonArduinoSetup(button_t* btn, uint8_t pin) {
    if (!btn) return;
    
    btn->pin = pin;
    pinMode(pin, INPUT_PULLUP);
    
    // Call generic setup to configure function pointers and stdio
    myButtonSetup(btn, arduino_readPin);
    
    // Optional: Log initialization
    // Note: Since we just hijacked stdin, stdout (Serial) should still work for printf
    printf("Button on pin %d configured as stdin stream.\n", pin);
}
