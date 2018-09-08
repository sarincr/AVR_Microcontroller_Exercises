#include <avr/io.h>
#include <stdint.h>            // has to be added to use uint8_t
#include <avr/interrupt.h>    // Needed to use interrupts


int main(void)
{
	DDRB=(1<<PB4);
	EICRA=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
	EIMSK=(1<<INT1) | (1<<INT0);
	EIFR=(1<<INTF1) | (1<<INTF0);
	PCICR= (0<<PCIE2) | (0<<PCIE1) | (0<<PCIE0);

    sei();                     // turn on interrupts

    while(1)
    {
        /*main program loop here */
    }
}



ISR (INT0_vect)
{
	PORTB=~PORTB;
}


