

#include <avr/io.h>

int main (void)
{

    DDRB = 0xFF;   // Set all Pins of PORTB as OUTPUT
    DDRD &= 0xFF; // Set all Pins of PORTD as INPUT
    PORTD |= 0x04;
    PORTD |= 0x06;
    int x=0,y=0;
    while (1)
    {
    	x=PIND & 0x04;
    	y=PIND & 0x05;
        if (x==1 && y==1)
            PORTB &= ~0x05;
        if (x==0 && y==0)
            PORTB |= 0x05;
    }
    return 0;
}
