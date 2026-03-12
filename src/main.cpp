#include <Arduino.h>
#include "../app_lab_2_1/app_lab_2_1.h"
#include "../app_lab_2_2/app_lab_2_2.h"


#define USE_APP_LAB_2_1 21
#define USE_APP_LAB_2_2 22

#define APP_USED USE_APP_LAB_2_2
void setup() {
#if APP_USED == USE_APP_LAB_2_1
app_lab_2_1_setup();
#elif APP_USED == USE_APP_LAB_2_2
app_lab_2_2_setup();
#endif
}
void loop() {
#if APP_USED == USE_APP_LAB_2_1
app_lab_2_1_loop();
#elif APP_USED == USE_APP_LAB_2_2
app_lab_2_2_loop();
#endif
}