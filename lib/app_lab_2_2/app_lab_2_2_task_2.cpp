#include "app_lab_2_2_task_2.h"
#include "../dd_led/dd_led.h"
#include "../dd_serial_stdio/dd_serial_stdio.h"
#define GREEN_LED 7
#define TASK_2_REC 50
#define TASK_2_OFFSET 50
//task 2
//Ожидает поднятия семафора от первой задачи, увеличивает переменную (N = N +1)
//и отправляет в буфер последовательность из N байт (1,2,3,..N) каждые 50 мс.
//Затем управляет светодиодом, который мигает N раз (ON — 300 мс, OFF — 500мс).
int task_N_cnt = 0;
extern SemaphoreHandle_t xSemaphore;
extern QueueHandle_t xQueue; // Queue handle
void app_lab_2_2_task_2_setup()
{
my_led_setup(GREEN_LED); // Initialize the LED
}
void task_2(void *pvParameters)
{
vTaskDelay(TASK_2_OFFSET / portTICK_PERIOD_MS);
while (1)
{
//ждем поднятия семафора от первой задачи
if (xSemaphoreTake(xSemaphore, portMAX_DELAY) == pdTRUE)
{//увеличиваем переменную N на 1
safe_printf("task_2: Семафор обнаружен\n");
task_N_cnt++;
//отправляем в очередь последовательность из N байт (1,2,3,..N) каждые 50 мс
for(int i = 0; i < task_N_cnt; i++)
{
xQueueSend(xQueue, &i, portMAX_DELAY);
//с интервалом в 50 мс
vTaskDelay(TASK_2_REC / portTICK_PERIOD_MS);
}
//safe_printf("\ntask_2: отправлено в очередь %d байт\n",task_N_cnt);
safe_printf("\nСветодиод мигает\n");
for(int i = 0; i < task_N_cnt; i++)
{
led_on(GREEN_LED); //заменить на зеленый
vTaskDelay(300 / portTICK_PERIOD_MS);
led_off(GREEN_LED);
vTaskDelay(500 / portTICK_PERIOD_MS);
}
}
vTaskDelay(500 / portTICK_PERIOD_MS);
}
}
