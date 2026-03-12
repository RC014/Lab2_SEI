#include "app_lab_2_1.h"
#include <Arduino.h>
#include "../dd_serial_stdio/dd_serial_stdio.h"
#include "../os_seq/os_seq.h"
//#include "app_lab_2_1_task_1.h"
#define TIMER_DEFAULT 0
extern int led_frequency;
extern char task_message[64];
extern char task2_message[64];
void app_lab_2_1_setup()
{
srv_serial_stdio_setup();
srv_os_seq_setup();
printf("app_lab 2_1 setup\n");
}
void app_lab_2_1_loop()
{
printf("Idle: task1: buton %s\n", task_message);
printf("Idle: task2: %s\n", task2_message);
printf("Idle: task3: frecventa ledurilor = %d\n", led_frequency);
timer_handle_interrupts(TIMER_DEFAULT);
delay(2000);//system tick
}
