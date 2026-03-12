#include "app_lab_2_2.h"
#include <Arduino.h>
#include "../dd_serial_stdio/dd_serial_stdio.h"
#include <Arduino_FreeRTOS.h>
#include "../dd_led/dd_led.h"
#include "../dd_button/dd_button.h"
#include "semphr.h"
#include "app_lab_2_2_task_1.h"
#include "app_lab_2_2_task_2.h"
#include "app_lab_2_2_task_3.h"
SemaphoreHandle_t xSemaphore = NULL; // Semaphore handle
QueueHandle_t xQueue = NULL; // Queue handle
SemaphoreHandle_t xPrintfMutex = NULL;
void app_lab_2_2_setup()
{
srv_serial_stdio_setup();
app_lab_2_2_task_1_setup();
app_lab_2_2_task_2_setup();
// Create the semaphore
xSemaphore = xSemaphoreCreateBinary(); // Create a binary semaphore
// Create the queue
xQueue = xQueueCreate(100, sizeof(int));
xPrintfMutex = xSemaphoreCreateMutex();
xTaskCreate(task_1, "Task 1", 1000, NULL, 1, NULL);
xTaskCreate(task_2, "Task 2", 1000, NULL, 1, NULL);
xTaskCreate(task_3, "Task 3", 1000, NULL, 1, NULL);
vTaskStartScheduler(); // Start the scheduler
}
void app_lab_2_2_loop()
{
}
