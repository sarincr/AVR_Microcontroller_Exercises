#include <avr/io.h>

int main(void)
{
   DDRB = 0xFF;   //PORTB output
   DDRD = 0x00;   //PORTD input

   while(1)
   {
       PORTB = PIND;   //value on PORTD to PORTB
   }
}
