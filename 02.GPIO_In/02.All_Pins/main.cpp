

#include <avr/io.h>


int main (void)
{

    DDRB = 0xFF;   // Set all Pins of PORTB as OUTPUT
    DDRD &= 0xFF; // Set all Pins of PORTD as INPUT
    PORTD |= 0x04;

    while (1)
    {
        if (PIND & 0x04) // Checking port status of PORTD wrto 4th Pin of Port D
            PORTB &= ~0xFF;    // Setting up of all the pins of PORT B to Logic High
        else
            PORTB |= 0xFF; // Setting up of all the pins of PORT B to Logic Low
    }
    return 0;
}
