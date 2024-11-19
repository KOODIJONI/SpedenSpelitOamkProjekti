#include "buttons.h"
#include <Arduino.h>

void initButtonsAndButtonInterrupts(void)
{
  for (int i = firstPin; i <= lastPin; i++) {
      pinMode(i, INPUT_PULLUP);
  }
  
  PCICR |= 0b00000100; 
  PCMSK2 |= (1 << BUTTON1) | (1 << BUTTON2) | (1 << BUTTON3) | (1 << BUTTON4) | (1 << START_GAME);
}

ISR(PCINT2_vect) {
  unsigned long currentTime = micros();
  /* if (digitalRead(BUTTON1) == HIGH||digitalRead(BUTTON2) == HIGH||digitalRead(BUTTON3) == HIGH||digitalRead(BUTTON4) == HIGH) {
    if (isDebounce(currentTime)) {
          buttonNumber = -1; 
          resetDebounce(currentTime);
        }  
    }*/


  if (digitalRead(BUTTON1) == LOW) {
   if (isDebounce(currentTime)) {
      buttonNumber = 1; 
      resetDebounce(currentTime);
    }
  }
  else if (digitalRead(BUTTON2) == LOW) {
    if (isDebounce(currentTime)) {
      buttonNumber = 2; 
      resetDebounce(currentTime);
    }
  }
  else if (digitalRead(BUTTON3) == LOW) {
    if (isDebounce(currentTime)) {
      buttonNumber = 3; 
      resetDebounce(currentTime);
    }
  }
  else if (digitalRead(BUTTON4) == LOW) {
if (isDebounce(currentTime)) {
      buttonNumber = 4; 
      resetDebounce(currentTime);
    }  }
  else if (digitalRead(START_GAME) == LOW) {
    if (isDebounce(currentTime)) {
      buttonNumber = 5; 
      resetDebounce(currentTime);
    }
  }
}

void resetDebounce(unsigned long currentTime) {
    lastDebounceTime = currentTime;  
    lastButtonState = HIGH;         
}

bool isDebounce(unsigned long currentTime) {
    return ((currentTime - lastDebounceTime) > debounceDelay);
}

