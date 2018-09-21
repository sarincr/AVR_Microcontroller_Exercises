#include<avr/io.h>
#include <util/delay.h>
int  duty_cycle=0;	// Initialise the Duty Cycle variable 
int main(void)
{
  DDRD = 1<<PD6;     // Set PORTD Pin 6 as Output
  
  // FPWM frequency = fclk / (N * 256), Where N is the Prescaler
  // Prescaler = 64 / clk
  // f_PWM = 16000000 / (64 * 256) = 976 Hz
  

  TCCR0A|=(1<<COM0A1); //  Clear OC0A on Compare Match when up-counting. Set OC0A on Compare Match when down-counting.
  TCCR0A|=(1<<COM0B1); // Clear OC0B on Compare Match, set OC0B at BOTTOM, (non-inverting mode)
  TCCR0A|=(1<< WGM01)|(1<< WGM00); //  Fast PWM
  TCCR0B|= (1<<CS01)| (1<<CS00);  // Used 1/64 clk Prescaler

 

  for(;;) // Infinte loop 
  {            
    for(duty_cycle=0;duty_cycle < 255;duty_cycle++)   
    {
      OCR0A=duty_cycle;
       _delay_ms(10);
    }
   
  }
       
}
