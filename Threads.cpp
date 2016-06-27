/*
   Threads.cpp - for managing threads changing colors
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

#include "Threads.h"

Threads::Threads(void)
{
}

// _N: the number threads in use
// _pins: which pins go to the threads
// _powerLevels: how much power to give to each thread (0-255 for analogWrite)
// _powerDurations: how long to supply power to each thread (milliseconds)
void Threads::init(int _N, int* _pins, int* _powerLevels, unsigned long* _powerDurations)
{
    N = _N;
    for (int i = 0; i < N; i++) {
        pins[i] = _pins[i];
        powerLevels[i] = _powerLevels[i];
        powerDurations[i] = _powerDurations[i];
        analogWrite(pins[i], 0);
        powered[i] = 0;
        prevOn[i] = false;
    }
}

// _threadsOn: which threads should be on (color changed)
void Threads::update(bool* _threadsOn)
{
    unsigned long now = millis();
    for (int i = 0; i < N; i++) {
        // if thread is supposed to be off, set power to 0
        if (!_threadsOn[i]) {
            analogWrite(pins[i], 0);
            continue;
        } 
        // OK thread is supposed to be on
        // if the thread just got turned on, we should start supplying power
        if (!prevOn[i]) {
            analogWrite(pins[i], powerLevels[i]);
            powered[i] = now;
            continue;
        }
        // OK so the thread already started getting power
        // if it has been getting power for a while, set power to 0
        if ( (now - powered[i]) > powerDurations[i] ) {
            analogWrite(pins[i], 0);
        }
    } 

    // update prevOn
    for (int i = 0; i < N; i++) {
        prevOn[i] = _threadsOn[i];
    }
}
