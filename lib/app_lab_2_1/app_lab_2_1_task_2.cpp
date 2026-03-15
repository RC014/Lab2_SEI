#include "app_lab_2_1_task_2.h"
#include "../dd_led/dd_led.h"
#include <stdio.h>
#include <string.h>
#include <Arduino.h>
//Таск 2 – Мигающий светодиод: Управление мигающим светодиодом, который активен только тогда, когда светодиод из Задачи 1 выключен.
extern int led_frequency;
char task2_message[TASK_MSG_BUFFER_SIZE] = " ";
void app_lab_2_1_task2_setup()
{
}
void app_lab_2_1_task2_loop(led_t* led1, led_t* led2, int tick)
{
static int blink_counter = 0;//тики
if (digitalRead(led1->pin) == LOW) {//если основной светодиод выключен
sprintf(task2_message, "Green led blinking");
// Увеличиваем счётчик тиков
blink_counter++;
// Calculate toggle interval in ms. Adjusted to slow down the fast blink to a visible rate.
int interval = (10000 / led_frequency / 2) / tick; 
if (interval < 1) interval = 1; // Ensure we wait at least 1 tick
if (blink_counter >= interval) {//если прошло достаточно времени
blink_counter = 0;//сброс счётчика
ledToggle(led2);//переключаем состояние светодиода
}
} else {
sprintf(task2_message, "Red led on");
ledOff(led2); // Ensure LED is off when inactive
blink_counter = 0; // Сброс счётчика
}
}
