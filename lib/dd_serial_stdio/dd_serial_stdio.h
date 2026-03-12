#ifndef DD_SERIAL_STDIO_H_
#define DD_SERIAL_STDIO_H_
#include <stdio.h>
#include <Arduino_FreeRTOS.h>
#include "semphr.h"
int srv_serial_put_char(char ch, FILE *f);
int srv_serial_get_char(FILE *f);
void safe_printf(const char* format, ...);
void srv_serial_stdio_setup();
#endif // SRV_SERIAL_STDIO_H_
