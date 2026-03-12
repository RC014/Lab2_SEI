#include "app_lab_2_1_task_1.h"
#include "../dd_led/dd_led.h"
#include "../dd_button/dd_button.h"
#include <stdio.h>
#include <Arduino.h>
//Таск 1: изменение состояния светодиода по нажатию кнопки.
char task_message[64] = " ";
void app_lab_2_1_task1_setup()
{
printf("TASK1: Настройка\n");
}
void app_lab_2_1_task1_loop(int led_pin1, int button_pin)
{
if(my_button_is_pressed(button_pin))//no spin lock
{
//printf("TASK1: Кнопка нажата\n");
strcpy(task_message, "нажата");
ledToggle(led_pin1);
}
else
{
//printf("TASK1: Кнопка отпущена\n");
strcpy(task_message, "отпущена");
}
/*while(my_button_is_pressed());//в этом случае программа бы застряла и
напрасно тратила процессорное время
printf("Кнопка отпущена\n");
//led_off(RED_LED);
delay(300);//debounce delay
*/
}