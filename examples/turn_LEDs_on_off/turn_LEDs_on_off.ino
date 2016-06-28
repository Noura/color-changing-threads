/* LEDs On and Off - Example Sketch for Threads library
   2016 Noura Howell
   https://github.com/Noura/color-changing-threads.git

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
   
*/   

#include <PrintArray.h>
#include <Threads.h>

// SETTINGS ///////////////////////////////////////////////////
// how many outputs we are using
#define N_PINS 3
// where the outputs are connected
int pins[] = {9, 10, 11};
// how much power to give to each pin (PWM: 0-255)
int powerLevels[] = {15, 25, 255};
// how long to supply power to each pin (ms)
unsigned long powerDurations[] = {5000, 4000, 1000};
///////////////////////////////////////////////////////////////


// specify which LEDs we want to be on at any given time
bool pinsOn[N_PINS];
Threads myBasicController;

void setup() {  
  // all pins off to begin with
  for (int i = 0; i < N_PINS; i++) {
    pinsOn[i] = false;
    analogWrite(pins[i], 0);
  }
  myBasicController.init(N_PINS, pins, powerLevels, powerDurations);
}

void loop() {
  // choose which pins you want to be on or off
  pinsOn[0] = true;
  pinsOn[1] = true;
  pinsOn[2] = true;

  // then update them
  myBasicController.update(pinsOn);
}
