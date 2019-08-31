
#include "anulu3d.h"
#include "ultralcd.h"
#include "temperature.h"
#include "watchdog.h"



//===========================================================================
//=============================   functions      ============================
//===========================================================================
#define PGM_RD_W(x)   (short)pgm_read_word(&x)

void tp_init()
{
  // Use timer0 for temperature measurement
  // Interleave temperature interrupt with millies interrupt
  OCR0B = 128;
  TIMSK0 |= (1<<OCIE0B);  
  
  // Wait for temperature measurement to settle
  delay(250);
}

// Timer 0 is shared with millies
ISR(TIMER0_COMPB_vect)
{
  //these variables are only accesible from the ISR, but static, so they don't lose their value

  static unsigned char temp_state = 0;

  switch(temp_state) {
    case 0: // Prepare TEMP_0
      lcd_buttons_update();
      temp_state = 1;
      break;
    case 1: // Measure TEMP_0
      temp_state = 0;
      break;
   
    
    

  }
}




