#include "app_lab_2_1_task_3.h"
#include <stdio.h>
#include "../dd_button/dd_button.h"
#define MAX_LED_FREQUENCY 100 // Максимальная частота
#define MIN_LED_FREQUENCY 20 // Минимальная частота
//Задача 3 – Переменная состояния: Увеличение/уменьшение переменной при нажатии двух разных кнопок.
//Переменная отражает количество повторений/времени,
// в течение которого светодиод из Задачи 2 находится в определённом
состоянии
int led_frequency;
void app_lab_2_1_task3_setup()
{
printf("TASK3: Настройка\n");
led_frequency = MIN_LED_FREQUENCY; // стартовое значение
}
void app_lab_2_1_task3_loop(int button_pin1, int button_pin2)
{
if (my_button_is_pressed(button_pin1)) {
if (led_frequency < MAX_LED_FREQUENCY) led_frequency+=10; //
ограничим максимум
printf("Частота увеличена\n");
}
if (my_button_is_pressed(button_pin2)) {
if (led_frequency > MIN_LED_FREQUENCY) led_frequency-=10; //
ограничим минимум
printf("Частота уменьшена\n");
}
}