#ifndef APP_LAB_2_1_TASK_1_H
#define APP_LAB_2_1_TASK_1_H

#include "../../include/config.h"
#include "../dd_led/dd_led.h"
#include "../dd_button/dd_button.h"
#include <stdio.h>
#include <string.h>
#include <Arduino.h>

void app_lab_2_1_task1_setup();
void app_lab_2_1_task1_loop(led_t *led_pin1, button_t *btn);

#endif /* APP_LAB_2_1_TASK_1_H */