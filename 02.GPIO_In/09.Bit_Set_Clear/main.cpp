#include <avr/io.h>
#define BIT_IS_SET(byte, bit) (byte & (1 << bit))
#define BIT_IS_CLEAR(byte, bit) (!(byte & (1 << bit)))

int main (void)
{

    DDRB = 0xFF;   // Set all Pins of PORTB as OUTPUT
    DDRD &= 0xFF; // Set all Pins of PORTD as INPUT
    while (1)
    {

        if (BIT_IS_CLEAR(PIND, PD2))  // Comparing the status of Pin 2 of Port D with PIND register
            PORTB |= (1<<PB5);   // Setting up Fifth Pin of Port 5 to Logic High
        else
            PORTB &= ~(1<<PB5); // Setting up Fifth Pin of Port 5 to Logic High
    }
    return 0;
}
