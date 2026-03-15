#include "app_lab_2_1_task_2.h"

//Task 2- LED intermitent: Controlul unui LED intermitent care este activ doar atunci când LED-ul din Sarcina 1 este oprit.
extern int led_frequency;
char task2_message[TASK_MSG_BUFFER_SIZE] = " ";
void app_lab_2_1_task2_setup()
{
}
void app_lab_2_1_task2_loop(led_t* led1, led_t* led2, int tick)
{
static int blink_counter = 0;
if (digitalRead(led1->pin) == LOW) {//in cazul in care led-ul de baza este stins
sprintf(task2_message, "Green led blinking");
// Marim numarul de tick-uri
blink_counter++;
// Calculate toggle interval in ms. Adjusted to slow down the fast blink to a visible rate.
int interval = (10000 / led_frequency / 2) / tick; 
if (interval < 1) interval = 1; // Ensure we wait at least 1 tick
if (blink_counter >= interval) {//daca a trecut destul timp
blink_counter = 0;//resetam counter-ul
ledToggle(led2);//modificam starea led-urilor
}
} else {
sprintf(task2_message, "Red led on");
ledOff(led2); // Ensure LED is off when inactive
blink_counter = 0; //resetam counter-ul
}
}
