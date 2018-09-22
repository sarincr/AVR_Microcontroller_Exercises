#include <util/delay.h>
int duty_cycle;
 
int main(void)
{
TCNT1=0;
DDRB|=(1<<PB2)|(1<<PB1);  // PB2  as output
TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<COM1B0); //Set OC1A/OC1B on Compare Match when up-counting. ClearOC1A/OC1B on Compare Match when down-counting..
TCCR1B|=(1<<WGM13); //  PWM, Phase and Frequency Correct with ICR1
TCCR1B|=(1<<CS11)|(1<<CS10);  // clkI/O/64 (From prescaler)

/* Using the ICR1 Register for defining TOP works well when using fixed TOP values. By using ICR1, the
OCR1A Register is free to be used for generating a PWM output on OC1A. However, if the base PWM */

ICR1=0x00FF;// Input Capture Register (ICR1)
    while(1)
    {
      
      for(duty_cycle=0;duty_cycle <300;duty_cycle++)
      {
      OCR1B=duty_cycle;
       _delay_ms(10);
     }
     for(duty_cycle=300;duty_cycle>0;duty_cycle--)  
     {
      OCR1B=duty_cycle;
       _delay_ms(10);
    }
  }
}
