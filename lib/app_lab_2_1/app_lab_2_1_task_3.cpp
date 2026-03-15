#include "app_lab_2_1_task_3.h"
#include <stdio.h>
#include "../dd_button/dd_button.h"

//Задача 3 – Переменная состояния: Увеличение/уменьшение переменной при нажатии двух разных кнопок.
//Переменная отражает количество повторений/времени,
// в течение которого светодиод из Задачи 2 находится в определённом состоянии
int led_frequency;
void app_lab_2_1_task3_setup()
{
led_frequency = MIN_LED_FREQUENCY; // стартовое значение
}
void app_lab_2_1_task3_loop(button_t* btn1, button_t* btn2)
{
static bool btn1_was_pressed = false;
static bool btn2_was_pressed = false;
int val = 0;

// Process Button 1 (Increase)
myButtonArduinoSetup(btn1, btn1->pin);
scanf("%1d", &val);
if (val == 1 && !btn1_was_pressed) {
    if (led_frequency < MAX_LED_FREQUENCY) led_frequency+=1;
    printf("\r\nFrequency increased");
}
btn1_was_pressed = (val == 1);

// Process Button 2 (Decrease)
myButtonArduinoSetup(btn2, btn2->pin);
scanf("%1d", &val);
if (val == 1 && !btn2_was_pressed) {
    if (led_frequency > MIN_LED_FREQUENCY) led_frequency-=1;
    printf("\r\nFrequency decreased");
}
btn2_was_pressed = (val == 1);
}