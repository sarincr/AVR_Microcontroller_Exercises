#include <util/delay.h>
int  duty_cycle=0;	// Initialise the Duty Cycle variable 
int main(void)
{

    DDRB |= (1<<PORTB1); // PORTB Pin 1 as OUTPUT
    ICR1 = 0x00FF; // Max count of Timer 1 to 0xFF
    TCCR1A |= (1 << COM1A1)|(1 << COM1B1); //Set OC1A/OC1B on Compare Match, clear OC1A/OC1B at BOTTOM (inverting mode)
    TCCR1A |= (1 << WGM11); // PWM, Phase Correct, 9-bit
    TCCR1B |= (1 << WGM12)|(1 << WGM13);  // CTC Mode -  set Fast PWM mode using ICR1 as TOP
    TCCR1B |= (1 << CS10);     // No presc

  for(;;) // Infinte loop 
  {            
    for(duty_cycle=0;duty_cycle < 255;duty_cycle++)   
    {
      OCR1A=duty_cycle;
       _delay_ms(10);
    }
     for(duty_cycle=255;duty_cycle>0;duty_cycle--)   
    {
      OCR1A=duty_cycle;
       _delay_ms(10);
    }
   
  }
       
}
