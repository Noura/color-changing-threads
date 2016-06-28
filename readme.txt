Specify which threads you want to get power and the library will supply power for a set amount of time and then cut power. Could be used to supply power for a limited time to any output pin, just in my case this is designed for supplying power to color-changing threads.

https://github.com/Noura/color-changing-threads.git

Usage Notes
--------------------------------------------------------------------------------
See example Arduino sketch for example usage.

The Threads library is intended to control color-changing threads, where
to get them to change color they need to get power for up to a few seconds,
but they also need to stop getting power before they get burnt! But really
each thread is connected to its own output pin, so more generally this
library can be used for any group of PWM out pins that you want to power on
and off in this manner.

So with this library you can specify which PWM output pins should be turned
on and set it and forget it. The library takes care of supplying power for
the specified amount of time and then turning it off.

You can try out this example using LEDs instead of threads:
Hook up 3 LEDs going from pins 9, 10, and 11,
each going to their own 10K resistor, then to ground.

When you run the sketch, the LEDs should be different brightness levels
because each is getting a different level of power. They should also stay
on for different lengths of time before turning off.
You can adjust the SETTINGS section below to change the brightness and
how long they stay on.

NOTES:

- Each pin gets power for the specified power duration starting from the
first time you tell it to be on, then turns off. If you tell it to be on
again within the power duration window, it won't make the pin stay on for any
additional time - the pin will still turn off after the specified
power duration from the first time you tell that pin to be on. This is to
protect sensitive outputs (such as color-changing conductive threads) that
might be damaged by receiving power for too long.

- If you tell the pin to turn off, it turns off immediately.

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

