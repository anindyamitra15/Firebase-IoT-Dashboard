#include "Interval.h"
//dependency: Arduino.h for millis()
#include "Arduino.h"

/* sets the value of the delay in microseconds */
void Interval::setDelay(unsigned long delay_ms)
{
    delay = delay_ms;
}

void Interval::setTicker(bool setTick) {
    ticking = setTick;
}

/* tick checks if the threshold time is elapsed
    if so, it calls the function in the parameter */
void Interval::tick(void (*task)())
{
    // updates the current elapsed time
    currt = millis();
    /* checks if the time elapsed is greater
        than the previous call timestamp by the delay ms*/
    if (ticking && (currt - prevt) >= delay)
    {
        //calls the scheduled task
        task();
        // updates the previous time
        prevt = millis();
    }
}