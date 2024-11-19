#ifndef BUTTONS_H
#define BUTTONS_H
#include <arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#define BUTTON1 2
#define BUTTON2 3
#define BUTTON3 4
#define BUTTON4 5
#define START_GAME 6
const byte firstPin = 2;
const byte lastPin =  5; 

extern volatile int buttonNumber;
extern volatile long lastDebounceTime;
extern volatile bool lastButtonState; 
const unsigned long debounceDelay = 50000;

bool areInterruptsEnabled(void);
void resetDebounce(unsigned long currentTime);
bool isDebounce(unsigned long currentTime);
void initButtonsAndButtonInterrupts(void);
void buttonISR(void);


ISR(PCINT2_vect); 
#endif;