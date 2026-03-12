#ifndef SMPHR_H
#define SMPHR_H

#include <Arduino.h>

/**
 * @brief Simple counting semaphore for synchronizing
 * tasks or interrupts (e.g., waiting for an Ultrasonic Echo ISR).
 */
class Semaphore {
private:
    volatile int count;

public:
    /**
     * @brief Construct a new Semaphore object
     * @param initial_count Initial value (default 0)
     */
    Semaphore(int initial_count = 0);

    /**
     * @brief Wait (P) operation. Decrements the semaphore.
     * Blocks (spins) if count is 0 until signaled by an interrupt.
     */
    void wait();

    /**
     * @brief Signal (V) operation. Increments the semaphore.
     * Safe to call from inside an ISR.
     */
    void signal();
};

#endif // SMPHR_H
