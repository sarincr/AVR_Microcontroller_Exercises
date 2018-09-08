#include <avr/io.h>
#include <avr/interrupt.h>


int main(void)
{
	// Interrupt is added on PB0/INT0
    DDRB &= ~(1 << DDB0);     //  Set up PB0 pin as Output

    DDRD=0xFF;
    PCICR |= (1 << PCIE0);    // PCIE0 is set to enable PCMSK0
    PCMSK0 |= (1 << PCINT0);  // PCINT0  is set to enable an interrupt on state change

    sei();                    //  Enable interrupts

    while(1)
    {

    }
}



ISR (PCINT0_vect)
{

	PORTD=~PORTD; // Change states of the co
}
