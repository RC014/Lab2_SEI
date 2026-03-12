#include "dd_serial_stdio.h"
int srvSerialGetChar(FILE *f)
{
while (!Serial.available()) // asteptam pana cand sunt date disponibile
;
return Serial.read(); // returnam caracterul citit
}
int srvSerialPutChar(char ch, FILE *f)

{
return Serial.write(ch); // scriem caracterul pe seriala
}
void srvSerialStdioSetup()
{
Serial.begin(9600); // setam viteza de comunicatie (9600 simboluri pe secunda)
FILE *srv_serial_stream = fdevopen(srvSerialPutChar,
srvSerialGetChar); // asociem functiile de citire/scriere cu un flux
stdin = srv_serial_stream ; // redirectionam intrarea standard
stdout = srv_serial_stream ; // redirectionam iesirea standard
printf("srvSerial Started\n"); // mesaj de confirmare
}