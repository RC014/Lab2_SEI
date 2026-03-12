#ifndef DD_SERIAL_STDIO_H_
#define DD_SERIAL_STDIO_H_
#include <stdio.h>
#include <Arduino.h>
int srvSerialPutChar(char ch, FILE *f);
int srvSerialGetChar(FILE *f);
void srvSerialStdioSetup();
#endif // SRV_SERIAL_STDIO_H_