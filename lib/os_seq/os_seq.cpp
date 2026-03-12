#include "os_seq.h"
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

// Button Driver Instances
button_t btn_task1;
button_t btn_task3_inc;
button_t btn_task3_dec;

// LED Driver Instances
led_t led_red;
led_t led_green;

void srv_os_seq_setup()
{
myLedArduinoSetup(&led_red, RED_LED);
myLedArduinoSetup(&led_green, GREEN_LED);

myButtonArduinoSetup(&btn_task1, RED_BUTTON_PIN);
myButtonArduinoSetup(&btn_task3_inc, INC_BUTTON_PIN);
myButtonArduinoSetup(&btn_task3_dec, DEC_BUTTON_PIN);

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
app_lab_2_1_tsk1_cnt = APP_LAB_2_1_TSK_REC / SRV_OS_SYS_TICK; //reset counter
app_lab_2_1_task1_loop(&led_red, &btn_task1);
printf("Task1 выполняется\n");
}
if(--app_lab_2_1_tsk2_cnt <= 0)//every 1000ms
{
app_lab_2_1_tsk2_cnt = APP_LAB_2_1_TSK_REC / SRV_OS_SYS_TICK; //reset counter
app_lab_2_1_task2_loop(&led_red, &led_green, SRV_OS_SYS_TICK);
//SRV_OS_SYS_TICK = 1ms
printf("Task2 выполняется\n");
}
if (--app_lab_2_1_tsk3_cnt <= 0) {
app_lab_2_1_tsk3_cnt = APP_LAB_2_1_TSK_REC / SRV_OS_SYS_TICK;
app_lab_2_1_task3_loop(&btn_task3_inc, &btn_task3_dec);
printf("Task3 выполняется\n");
}
}
