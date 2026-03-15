#include "app_lab_2_1.h"

#define TIMER_DEFAULT 0
extern int led_frequency;
extern char task_message[TASK_MSG_BUFFER_SIZE];
extern char task2_message[TASK_MSG_BUFFER_SIZE];
void app_lab_2_1_setup()
{
dd_serial_stdio_setup();
srv_os_seq_setup();
}
void app_lab_2_1_loop()
{
static unsigned long last_print_time = 0;
static unsigned long last_tick_time = millis(); // Track time for the OS tick

// 1. Rate-limit terminal printing to every 500ms without blocking the system
if (millis() - last_print_time >= 500) {
    last_print_time = millis();
    printf("\r\nIdle: task1: button %s", task_message);
    printf("\r\nIdle: task2: %s", task2_message);
    printf("\r\nIdle: task3: led frequency = %d", led_frequency);
}

// 2. Execute the OS sequence scheduler exactly once per millisecond
while (millis() - last_tick_time >= 1) {
    last_tick_time++; // Advance the tick tracker by 1ms
    timer_handle_interrupts(TIMER_DEFAULT); // Fire the OS tick
}
}
