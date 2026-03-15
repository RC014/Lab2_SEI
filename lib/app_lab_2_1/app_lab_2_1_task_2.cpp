#include "app_lab_2_1_task_2.h"

// Task 2- LED intermitent: Controlul unui LED intermitent care este activ doar atunci când LED-ul din Sarcina 1 este oprit.
extern int led_frequency;
char task2_message[TASK_MSG_BUFFER_SIZE] = " ";
void app_lab_2_1_task2_setup()
{
}
void app_lab_2_1_task2_loop(led_t *led1, led_t *led2, int tick)
{
    static int blink_counter = 0;
    if (digitalRead(led1->pin) == LOW)
    {
        sprintf(task2_message, "Green led blinking");

        blink_counter++;

        int interval = (10000 / led_frequency / 2) / tick;
        if (interval < 1)
            interval = 1;
        if (blink_counter >= interval)
        {
            blink_counter = 0;
            ledToggle(led2);
        }
    }
    else
    {
        sprintf(task2_message, "Red led on");
        ledOff(led2);
        blink_counter = 0;
    }
}
