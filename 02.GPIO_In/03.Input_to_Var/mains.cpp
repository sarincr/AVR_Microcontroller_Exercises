

#include <avr/io.h>


int main (void)
{

    DDRB = 0xFF;   // Set all Pins of PORTB as OUTPUT
    DDRD = 0x00; // Set all Pins of PORTD as INPUT
    int x=0;
    while (1)
    {
      x=PIND & 0x08;
        if (x) 
            PORTB &= ~0x08;     
        else
            PORTB |= 0x08;  
    }
    return 0;
}
