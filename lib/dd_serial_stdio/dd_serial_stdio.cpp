#include "dd_serial_stdio.h"

extern SemaphoreHandle_t xPrintfMutex;
int dd_serial_get_char(FILE *f)
{
    while (!Serial.available())
        ;
    return Serial.read();
}
int dd_serial_put_char(char ch, FILE *f)
{
    return Serial.write(ch);
}
void safe_printf(const char *format, ...)
{
    if (xPrintfMutex != NULL)
    {
        if (xSemaphoreTake(xPrintfMutex, portMAX_DELAY) == pdTRUE)
        {
            va_list args;
            va_start(args, format);
            vprintf(format, args);
            va_end(args);
            xSemaphoreGive(xPrintfMutex);
        }
    }
}
void dd_serial_stdio_setup()
{
    Serial.begin(SERIAL_BAUDRATE);
    FILE *srv_serial_stream = fdevopen(dd_serial_put_char,
                                       dd_serial_get_char);
    stdin = srv_serial_stream;
    stdout = srv_serial_stream;
}