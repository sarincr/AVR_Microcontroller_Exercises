#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
  DDRB |= 1<<PB1; // PORT B Pin 1 as Input
  TCCR1A |= 1<<WGM11 ;  //  Fast PWM with ICR1
  TCCR1A |=  1<<COM1A1 | 1<<COM1A0;  //  Set OC1A/OC1B on Compare Match (Set output to highlevel).
  TCCR1B |= 1<<WGM13 | 1<<WGM12 ;  //  Fast PWM with ICR1
  TCCR1B |=  1<<CS11;  //  Prescaler of 1/8 
  ICR1 = 100;  //  16MHz/20000Hz  / 8 Prescaler  = 99
  while (1)
  {
    for(int i=0;i<100;i++)
    {
      OCR1A = i;   // Loop for 0 -100%
      _delay_ms(10);
    }
    for(int i=100;i>0;i--)
    {
      OCR1A = i;  // Loop for 100% -0
      _delay_ms(10);
    }
  }
}
