/*
   Threads.h - for managing threads changing colors
   2016 Noura Howell
   https://github.com/Noura/simple-spike-detection

   NOTE: thread "on" means color-changed
         thread "powered" means receiving power
         A thread can be "on" while not receiving power, because after it
         receives power for a little while, it will still be color-changed
         until it cools down. This library helps manage that difference so
         you can just specify which threads you want to be on at any given
         time and this library supplies power appropriately. 
   */

#ifndef Threads_h
#define Threads_h

#include <PrintArray.h>
#include <Arduino.h>
#include <HardwareSerial.h>

#define MAX_N_THREADS 10

class Threads
{
    public:
        Threads(void);
        void init(int, int*, int*, unsigned long*);
        void update(bool*);

    private:
        // the number of threads
        int N;
        // which pins go to the threads
        int pins[MAX_N_THREADS];
        // how much power to give to each thread (0-255 for analogWrite)
        int powerLevels[MAX_N_THREADS];
        // how long to supply power to each thread (milliseconds)
        unsigned long powerDurations[MAX_N_THREADS];
        
        // which pins (i.e. threads) are currently receiving power
        // the millis() timestamp at which they started receiving power
        unsigned long powered[MAX_N_THREADS];
        // the threads that were supposed to be on during the last update
        bool prevOn[MAX_N_THREADS];
};

#endif

