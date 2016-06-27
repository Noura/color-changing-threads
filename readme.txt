Specify which threads you want to get power and the library will supply power for a set amount of time and then cut power. Could be used to supply power for a limited time to any output pin, just in my case this is designed for supplying power to color-changing threads.

https://github.com/Noura/color-changing-threads.git

Usage Notes
--------------------------------------------------------------------------------
Example usage:

    #include <Threads.h>
    #define N_THREADS 3
    ...
    Threads myThreads;
    int threadPins[] = {9, 10, 11};
    int threadPowerLevels[] = {255, 150, 100}; // 0-255 for analogWrite calls
    unsigned long threadPowerDurations[] = {5000, 4000, 1000}; // milliseconds
    bool threadsOn[N_THREADS];
    ...
    setup() {
        ...
        myThreads.init(N_THREADS, threadPins, threadPowerLevels, threadPowerDurations);
        for (int i = 0; i < N_THREADS; i++) {
            threadsOn[i] = false;
        }
    }
    loop() {
        threadsOn[0] = true;
        myThreads.update(threadsOn); 
    }


Installation
--------------------------------------------------------------------------------

To install this library, just place this entire folder as a subfolder in the directory where your Arduino sketches are stored by default. Probably something like ~/Documents/Arduino/libraries 

When installed, this library should look like:

libraries/Threads                (this library's folder)
libraries/Threads/Threads.cpp    (the library implementation file)
libraries/Threads/Threads.h      (the library description file)
libraries/Threads/examples       (the examples in the "open" menu)
libraries/Threads/readme.txt     (this file)

Building
--------------------------------------------------------------------------------

After this library is installed, you just have to start the Arduino application.
You may see a few warning messages as it's built.

To use this library in a sketch, go to the Sketch | Import Library menu and
select Threads.  This will add a corresponding line to the top of your sketch:
#include <Threads.h>

To stop using this library, delete that line from your sketch.

