#include "semphr.h"

Semaphore::Semaphore(int initial_count) {
    count = initial_count;
}

void Semaphore::wait() {
    while (true) {
        noInterrupts();
        if (count > 0) {
            count--;
            interrupts();
            return;
        }
        interrupts();
        // Allow interrupts to fire while waiting, so signal() can be called
    }
}

void Semaphore::signal() {
    noInterrupts();
    count++;
    interrupts();
}
