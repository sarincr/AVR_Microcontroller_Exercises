#include <avr/io.h>
#define BIT_IS_SET(byte, bit) (byte & (1 << bit))
#define BIT_IS_CLEAR(byte, bit) (!(byte & (1 << bit)))

int main (void)
{

    DDRB = 0xFF;   // Set all Pins of PORTB as OUTPUT
    DDRD &= 0x00; // Set all Pins of PORTD as INPUT
    while (1)
    {

        if (BIT_IS_CLEAR(PIND, PD5))   
            PORTB |= (1<<PB3);    
        else
            PORTB &= ~(1<<PB3);
    }
    return 0;
}
