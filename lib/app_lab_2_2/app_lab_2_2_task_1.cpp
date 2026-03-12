#include "app_lab_2_2_task_1.h"
#include "../dd_led/dd_led.h"
#include "../dd_button/dd_button.h"
#include "../dd_serial_stdio/dd_serial_stdio.h"

#define ONE_SEC 1000 //ms
#define TASK_1_REC 10 // Task period in ms, to match comments
#define TASK_1_OFFSET 0 // portTICK_PERIOD_MS
#define RED_LED 8
#define RED_BUTTON 9
int task1_led_time_cnt = -1;
extern SemaphoreHandle_t xSemaphore;
void app_lab_2_2_task_1_setup()
{
myButtonArduinoSetup(btn, btn->pin);
my_led_setup(RED_LED);
}
//При нажатии на кнопку зажигает светодиод на 1 секунду.
// Задача генерирует семафор и имеет периодичность 10 мс.
void task_1(void *pvParameters)
{
TickType_t xLastWakeTime = xTaskGetTickCount(); // Get the current tick count
vTaskDelay(TASK_1_OFFSET / portTICK_PERIOD_MS); // Delay for the offset time
while (1)
{
if(my_button_is_pressed(RED_BUTTON) && task1_led_time_cnt <0)
{
task1_led_time_cnt = ONE_SEC / TASK_1_REC; // так как светодиод будет гореть 10 мс
led_on(RED_LED);
safe_printf("Кнопка нажата\n");
}
vTaskDelayUntil(&xLastWakeTime, TASK_1_REC/ portTICK_PERIOD_MS);
//для переодичности 10
if(task1_led_time_cnt > 0)
{
task1_led_time_cnt--;
led_on(RED_LED);
safe_printf("Светодиод горит\n");
}
else if(task1_led_time_cnt == 0)
{
led_off(RED_LED); // Turn off the LED after 1 second
safe_printf("Светодиод не горит\n");
//поднимаем семафор
xSemaphoreGive(xSemaphore);
safe_printf("task_1: Семафор поднят\n");
task1_led_time_cnt--;
}
}
}