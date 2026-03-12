#include "app_lab_2_1_task_1.h"
#include "../dd_led/dd_led.h"
#include "../dd_button/dd_button.h"
#include <stdio.h>
#include <string.h>
#include <Arduino.h>


//Таск 1: изменение состояния светодиода по нажатию кнопки.
char task_message[TASK_MSG_BUFFER_SIZE] = " ";
void app_lab_2_1_task1_setup()
{
printf("\r\nTASK1: Setting up");
}
void app_lab_2_1_task1_loop(led_t* led, button_t* btn)
{
static bool was_pressed = false;

// Activate this button for stdio
myButtonArduinoSetup(btn, btn->pin);

int btn_val = 0;
scanf("%d", &btn_val); // Read '1' (pressed) or '0' (released)

if(btn_val == 1)
{
//printf("TASK1: Кнопка нажата\n");
strcpy(task_message, "\r\npressed");
if (!was_pressed) {
    ledToggle(led);
}
}
else
{
//printf("TASK1: Кнопка отпущена\n");
strcpy(task_message, "\r\nreleased");
}
was_pressed = (btn_val == 1);
}