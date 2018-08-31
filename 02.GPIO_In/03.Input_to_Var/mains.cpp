

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
        if (x) // Checking port status of PORTD wrto 4th Pin of Port D
            PORTB &= ~0x05;    // Setting up of all the pins of PORT B to Logic High
        else
            PORTB |= 0x05; // Setting up of all the pins of PORT B to Logic Low
    }
    return 0;
}
