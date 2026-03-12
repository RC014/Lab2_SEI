#include "app_lab_2_1.h"
#include <Arduino.h>
#include "../dd_serial_stdio/dd_serial_stdio.h"
#include "../os_seq/os_seq.h"
//#include "app_lab_2_1_task_1.h"
#define TIMER_DEFAULT 0
extern int led_frequency;
extern char task_message[TASK_MSG_BUFFER_SIZE];
extern char task2_message[TASK_MSG_BUFFER_SIZE];
void app_lab_2_1_setup()
{
ddSerialStdioSetup();
srv_os_seq_setup();
printf("\r\napp_lab 2_1 setup");
}
void app_lab_2_1_loop()
{
printf("\r\nIdle: task1: buton %s", task_message);
printf("\r\nIdle: task2: %s", task2_message);
printf("\r\nIdle: task3: frecventa ledurilor = %d", led_frequency);
timer_handle_interrupts(TIMER_DEFAULT);
delay(2000);//system tick
}
