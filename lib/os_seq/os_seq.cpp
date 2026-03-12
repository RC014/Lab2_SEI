#include "os_seq.h"
#include <timer-api.h>
#include "../app_lab_2_1/app_lab_2_1_task_1.h"
#include "../app_lab_2_1/app_lab_2_1_task_2.h"
#include "../app_lab_2_1/app_lab_2_1_task_3.h"
#include "../dd_led/dd_led.h"
#include "../dd_button/dd_button.h"
int app_lab_2_1_tsk1_cnt = APP_LAB_2_1_TSK_OFFSET;
int app_lab_2_1_tsk2_cnt = APP_LAB_2_1_TSK_OFFSET;
int app_lab_2_1_tsk3_cnt = APP_LAB_2_1_TSK_OFFSET;
#define RED_LED 3
#define GREEN_LED 2
#define RED_BUTTON_PIN 10
#define INC_BUTTON_PIN 8
#define DEC_BUTTON_PIN 9
void srv_os_seq_setup()
{
my_led_setup(RED_LED);
my_led_setup(GREEN_LED);
my_button_setup(RED_BUTTON_PIN);
my_button_setup(INC_BUTTON_PIN);
my_button_setup(DEC_BUTTON_PIN);
// Initialize the timer for 1Hz
timer_init_ISR_1Hz(TIMER_DEFAULT);
app_lab_2_1_tsk1_cnt = APP_LAB_2_1_TSK_OFFSET;
app_lab_2_1_tsk2_cnt = APP_LAB_2_1_TSK_OFFSET;
app_lab_2_1_tsk3_cnt = APP_LAB_2_1_TSK_OFFSET;
app_lab_2_1_task1_setup();
app_lab_2_1_task2_setup();
app_lab_2_1_task3_setup();
}
void timer_handle_interrupts(int timer){
if(--app_lab_2_1_tsk1_cnt <= 0)//every 1000ms
{
app_lab_2_1_tsk1_cnt = APP_LAB_2_1_TSK_REC / SRV_OS_SYS_TICK; //reset
counter
app_lab_2_1_task1_loop(RED_LED, RED_BUTTON_PIN);
printf("Task1 выполняется\n");
}
if(--app_lab_2_1_tsk2_cnt <= 0)//every 1000ms
{
app_lab_2_1_tsk2_cnt = APP_LAB_2_1_TSK_REC / SRV_OS_SYS_TICK; //reset
counter
app_lab_2_1_task2_loop(RED_LED, GREEN_LED, SRV_OS_SYS_TICK);
//SRV_OS_SYS_TICK = 1ms
printf("Task2 выполняется\n");
}
if (--app_lab_2_1_tsk3_cnt <= 0) {
app_lab_2_1_tsk3_cnt = APP_LAB_2_1_TSK_REC / SRV_OS_SYS_TICK;
app_lab_2_1_task3_loop(INC_BUTTON_PIN, DEC_BUTTON_PIN);
printf("Task3 выполняется\n");
}
}
