#ifndef __INTERVAL_H__
#define __INTERVAL_H__

/*
    Interval library by AKM-machine (xD)
    used to call the Scheduled task
    after a certain interval

    Note: If you call delay() inside the loop() or while(1)
    having a value higher than the minimum schedule delay 
    time, then the schedules get delayed as well !!
*/

class Interval
{
    // methods accesible outside
    // described in ./Interval.cpp
    public:
        void setDelay(unsigned long);
        void setTicker(bool);
        void tick(void (*func) ());

    // variables to store the timings
    private:
        bool ticking;
        unsigned long currt;
        unsigned long prevt;
        unsigned long delay;
};

#endif
