

#include <avr/io.h>

int main (void)
{

    DDRB = 0xFF;   // Set all Pins of PORTB as OUTPUT
    DDRD &= 0xFF; // Set all Pins of PORTD as INPUT
    PORTD |= 0x04;
    int x=0;
    while (1)
    {
      x=PIND & 0x04;
       if (~x)
            PORTB &= ~0x05;
       if (x)

            PORTB |= 0x05;
    }
    return 0;
}
