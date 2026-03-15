#include "app_lab_2_1_task_1.h"

//Таск 1: изменение состояния светодиода по нажатию кнопки.
char task_message[TASK_MSG_BUFFER_SIZE] = " ";
void app_lab_2_1_task1_setup()
{
}
void app_lab_2_1_task1_loop(led_t* led, button_t* btn)
{
static bool was_pressed = false;

// Activate this button for stdio
myButtonArduinoSetup(btn, btn->pin);

int btn_val = 0;
scanf("%1d", &btn_val); // Read exactly 1 char to prevent infinite loop

if(btn_val == 1)
{
//printf("TASK1: Кнопка нажата\n");
sprintf(task_message, "pressed");
if (!was_pressed) {
    ledToggle(led);
}
}
else
{
//printf("TASK1: Кнопка отпущена\n");
sprintf(task_message, "released");
}
was_pressed = (btn_val == 1);
}