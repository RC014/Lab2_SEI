#ifndef SRV_OS_SEQ_H
#define SRV_OS_SEQ_H

#include <stdio.h>
#include <timer-api.h>
#include "../../include/config.h"
#include "../app_lab_2_1/app_lab_2_1_task_1.h"
#include "../app_lab_2_1/app_lab_2_1_task_2.h"
#include "../app_lab_2_1/app_lab_2_1_task_3.h"
#include "../dd_led/dd_led.h"
#include "../dd_button/dd_button.h"

#define APP_LAB_2_1_TSK_REC (TIME_SEC/2)/SRV_OS_SYS_TICK //ms

#define TIME_SEC 10
#ifdef __cplusplus
extern "C" {
#endif
void timer_handle_interrupts(int timer); // <-- оставляем оригинальное имя
#ifdef __cplusplus
}
#endif
void srv_os_seq_setup();
#endif /* SRV_OS_SEQ_H */