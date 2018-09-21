#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
  DDRB |= 1<<PB1; // PORT B Pin 1 as Input
  TCCR1A |= 1<<WGM11 ;  //  Fast PWM with ICR1
  TCCR1A |=  1<<COM1A1 | 1<<COM1A0;  //  Set OC1A/OC1B on Compare Match (Set output to highlevel).
  TCCR1B |= 1<<WGM13 | 1<<WGM12 ;  //  Fast PWM with ICR1
  TCCR1B |=  1<<CS12;  //  Prescaler of 1/256 
  ICR1 = 31;  //  16MHz/2000Hz  / 256 Prescaler  = 31
  while (1)
  {
    for(int i=0;i<31;i++)
    {
      OCR1A = i;   // Loop for 0 -100%
      _delay_ms(100);
    }
    for(int i=31;i>0;i--)
    {
      OCR1A = i;  // Loop for 100% -0
      _delay_ms(10);
    }
  }
}
