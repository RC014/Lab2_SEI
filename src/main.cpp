#include <Arduino.h>
#include "../app_lab_2_1/app_lab_2_1.h"

#define USE_APP_LAB_2_1 21
#define APP_USED USE_APP_LAB_2_1
void setup() {
#if APP_USED == USE_APP_LAB_2_1
app_lab_2_1_setup();
#endif
}
void loop() {
#if APP_USED == USE_APP_LAB_2_1
app_lab_2_1_loop();
#endif
}