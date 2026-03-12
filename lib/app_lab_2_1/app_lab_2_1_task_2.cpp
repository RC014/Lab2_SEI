#include "app_lab_2_1_task_2.h"
#include "../dd_led/dd_led.h"
#include <stdio.h>
#include <string.h>
#include <Arduino.h>
//Таск 2 – Мигающий светодиод: Управление мигающим светодиодом, который активен только тогда, когда светодиод из Задачи 1 выключен.
extern int led_frequency;
char task2_message[64] = " ";
void app_lab_2_1_task2_setup()
{
printf("TASK2: Настройка\n");
}
void app_lab_2_1_task2_loop(led_t* led1, led_t* led2, int tick)
{
static int blink_counter = 0;//тики
if (digitalRead(led1->pin) == LOW) {//если основной светодиод выключен
strcpy(task2_message, "мигает зеленый светодиод");
// Увеличиваем счётчик тиков
blink_counter++;
int interval = (100 / led_frequency) / tick;//как часто мигает светодиод
if (blink_counter >= interval) {//если прошло достаточно времени
blink_counter = 0;//сброс счётчика
ledToggle(led2);//переключаем состояние светодиода
/*
if (led_state)
led_on(led_pin2);
else
led_off(led_pin2);*/
}
} else {
strcpy(task2_message, "горит красный светодиод");
ledOff(led2); // Ensure LED is off when inactive
blink_counter = 0; // Сброс счётчика
}
}
