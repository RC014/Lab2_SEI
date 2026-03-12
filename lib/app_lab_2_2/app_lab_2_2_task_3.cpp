#include "app_lab_2_2_task_3.h"
#include "../dd_serial_stdio/dd_serial_stdio.h"
#define TASK_3_REC 200
#define TASK_3_OFFSET 100
//task 3
//каждые 200 мс читает буфер и отображает считанные байты в терминале через STDIO
//При обнаружении байта 0 — переходит на новую строку.
extern QueueHandle_t xQueue;
void task_3(void *pvParameters)
{
vTaskDelay(TASK_3_OFFSET / portTICK_PERIOD_MS);
while (1)
{
int data; // Buffer to store received data
// Read from the queue every 200 ms
while (xQueueReceive(xQueue, &data, TASK_3_REC / portTICK_PERIOD_MS)
== pdTRUE)
{ if (data == 0) // If the received byte is 0, print a new line
{
safe_printf("\nБуффер содержит: 0,"); // Print a new line
}
else
{
safe_printf("%d,", data); // Print the received byte
}
}
}
}