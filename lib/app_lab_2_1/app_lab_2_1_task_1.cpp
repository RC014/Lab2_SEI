#include "app_lab_2_1_task_1.h"
#include "../dd_led/dd_led.h"
#include "../dd_button/dd_button.h"
#include <stdio.h>
#include <string.h>
#include <Arduino.h>
//Таск 1: изменение состояния светодиода по нажатию кнопки.
char task_message[64] = " ";
void app_lab_2_1_task1_setup()
{
printf("TASK1: Настройка\n");
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
strcpy(task_message, "нажата");
if (!was_pressed) {
    ledToggle(led);
}
}
else
{
//printf("TASK1: Кнопка отпущена\n");
strcpy(task_message, "отпущена");
}
was_pressed = (btn_val == 1);
/*while(my_button_is_pressed());//в этом случае программа бы застряла и
напрасно тратила процессорное время
printf("Кнопка отпущена\n");
//led_off(RED_LED);
delay(300);//debounce delay
*/
}