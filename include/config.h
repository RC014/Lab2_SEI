#ifndef CONFIG_H
#define CONFIG_H

//Viteza serial
#define SERIAL_BAUDRATE 9600

// LED Pins
#define RED_LED 3    // numarul 3 este pinul fizic de pe placa arduino pentru ledul rosu
#define GREEN_LED 2  // numarul 2 este pinul fizic de pe placa arduino pentru ledul verde

// Button Pins
#define RED_BUTTON_PIN 10
#define INC_BUTTON_PIN 8
#define DEC_BUTTON_PIN 9

// System Configuration
#define SYSTEM_TIMER TIMER_DEFAULT // Timer to be used by the OS

// Task Configuration
#define TASK_MSG_BUFFER_SIZE 64    // Size of the message buffer for Task 1

// OS Configuration
#define SRV_OS_SYS_TICK 1          // System tick value passed to tasks (1ms)
#define TASK_REC_UI 20             // UI Tasks (Buttons) run every 20ms
#define TASK_REC_LED 1             // LED Task runs every 1ms
#define APP_LAB_2_1_TSK_OFFSET 0   // Initial offset
#define TIME_SEC 10

#define OS_TIMER_PRESCALER 3       // 3 = Prescaler 64 (for AVR)
#define OS_TIMER_ADJUSTMENT 249    // 16MHz / 64 / 1000Hz - 1 = 249

// Driver Configuration
#define DD_LED_OUTPUT 1            // Configures LED pin as output

// Led Frequency COnfiguration
#define MAX_LED_FREQUENCY 100      
#define MIN_LED_FREQUENCY 2       

enum ledState{
    LED_OFF = 0,
    LED_ON,
    LED_TOGGLE
};

#endif