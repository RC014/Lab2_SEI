#ifndef SRV_OS_SEQ_H
#define SRV_OS_SEQ_H
#include <stdio.h>
#define APP_LAB_2_1_TSK_REC (TIME_SEC/2)/SRV_OS_SYS_TICK //ms
#define APP_LAB_2_1_TSK_OFFSET TIME_SEC/SRV_OS_SYS_TICK //ms
#define SRV_OS_SYS_TICK 1//ms
#define TIME_SEC 10
#ifdef __cplusplus
extern "C" {
#endif
void timer_handle_interrupts(int timer); // <-- оставляем оригинальное имя
#ifdef __cplusplus
}
#endif
void srv_os_seq_setup();
#endif /* SRV_OS_SEQ_H */