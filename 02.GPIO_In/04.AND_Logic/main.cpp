

#include <avr/io.h>


int main (void)
{

    DDRB = 0xFF;   // Set all Pins of PORTB as OUTPUT
    DDRD = 0x00; // Set all Pins of PORTD as INPUT
    int x=0;
    while (1)
    {
      x=PIND & 0x08;
      x=PIND & 0x10;
      if (x==1 && y==1)
      PORTB &= ~0x05;
      if (x==0 && y==0)
      PORTB |= 0x05;  
    }
    return 0;
}
