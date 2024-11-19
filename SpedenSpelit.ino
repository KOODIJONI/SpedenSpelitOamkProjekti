#include "display.h"
#include "buttons.h"
#include "leds.h"
#include "SpedenSpelit.h"

volatile int buttonNumber = -1;          
volatile bool newTimerInterrupt = false;  
volatile long lastDebounceTime;
volatile bool lastButtonState = LOW; 
volatile int lastButtonPressed = 0;
void setup()
{
  /*
    Initialize here all modules
  */
  Serial.begin(9600);
  initButtonsAndButtonInterrupts();
}
void loop()
{
 
  Serial.write(random(5,9));
  
  
  if(buttonNumber>=0)
  {
    

    Serial.write(buttonNumber);
    Serial.println(buttonNumber);
     // start the game if buttonNumber == 4
     // check the game if 0<=buttonNumber<4
     buttonNumber = -1;
  }
  delay(100);
  if(newTimerInterrupt == true)
  {
     // new random number must be generated
     // and corresponding let must be activated
  }
}

void initializeTimer(void)
{
	// see requirements for the function from SpedenSpelit.h
}
ISR(TIMER1_COMPA_vect)
{
  /*
  Communicate to loop() that it's time to make new random number.
  Increase timer interrupt rate after 10 interrupts.
  */
  
}


void checkGame(byte nbrOfButtonPush)
{
	// see requirements for the function from SpedenSpelit.h
}


void initializeGame()
{
	// see requirements for the function from SpedenSpelit.h
}

void startTheGame()
{
   // see requirements for the function from SpedenSpelit.h
}

