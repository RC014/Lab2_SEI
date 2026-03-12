#ifndef CONFIG_H
#define CONFIG_H

// LED Pins
#define RED_LED 12   // numarul 12 este pinul fizic de pe placa arduino pentru ledul rosu
#define GREEN_LED 11 // numarul 11 este pinul fizic de pe placa arduino pentru ledul verde

// LCD I2C Configuration
#define I2C_ADDR 0x27    // Adresa I2C a ecranului LCD
#define LCD_COLUMNS 16   // Numarul de coloane al ecranului LCD
#define LCD_ROWS 2       // Numarul de randuri al ecranului LCD

// Keypad Configuration
#define KEYPAD_ROWS 4    // Numarul de randuri al tastaturii
#define KEYPAD_COLS 4    // Numarul de coloane al tastaturii

// Keypad Pin Definitions
#define KEYPAD_R1_PIN 0
#define KEYPAD_R2_PIN 1
#define KEYPAD_R3_PIN 2
#define KEYPAD_R4_PIN 3
#define KEYPAD_C1_PIN 4
#define KEYPAD_C2_PIN 5
#define KEYPAD_C3_PIN 6
#define KEYPAD_C4_PIN 7

#endif
