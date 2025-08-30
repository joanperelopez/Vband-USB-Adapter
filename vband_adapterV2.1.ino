#include <Keyboard.h>
#include <Bounce2.h>

//This program acts a USB interface for a CW paddle or straight key for VBand Virtual CW Band.
//Original idea by Tony Milluzzi, KD8RTT using Keyboard library example as starting point.

// Declaring bounce objects
//Bounce dahState = Bounce();     
//Bounce ditState = Bounce();
Bounce2::Button dahState = Bounce2::Button();
Bounce2::Button ditState = Bounce2::Button();

//declaring paddle input pins
const int dah = 3;          
const int dit = 2;

int retardo=35;       // Delay value


void setup() {
  Keyboard.begin();

  dahState.interval(10); 
  ditState.interval(10); 

  dahState.attach(dah, INPUT_PULLUP);
  ditState.attach(dit, INPUT_PULLUP);

  dahState.setPressedState(LOW); 
  ditState.setPressedState(LOW); 

  dahState.interval(5);                 // Debouncing time in ms
  ditState.interval(5);
}


void loop() {

  
  ditState.update();
 
 //replaces left paddle input with dit using "[" as defined by VBand website
  if (ditState.pressed()) {
    Keyboard.press('[');
    delay(retardo);
  }

 if (ditState.released()) {
    Keyboard.release('[');
    delay(retardo); 
  }

dahState.update();

//replaces right paddle input with dah using "]" as defined by VBand website
  if (dahState.pressed()) {
    Keyboard.press(']');
    delay(retardo);
  } 
 
  if (dahState.released()) {
    Keyboard.release(']');
    delay(retardo);  
  }
  

}