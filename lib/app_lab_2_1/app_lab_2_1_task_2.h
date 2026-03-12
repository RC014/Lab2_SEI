#ifndef APP_LAB_2_1_TASK_2_H
#define APP_LAB_2_1_TASK_2_H

#include "../dd_led/dd_led.h"
#include "../../include/config.h"

void app_lab_2_1_task2_setup();
void app_lab_2_1_task2_loop(led_t* led_pin1, led_t* led_pin2, int tick);
#endif /* APP_LAB_2_1_TASK_2_H */