#include <avr/io.h>
#include <avr/interrupt.h>

// global variable to count the number of overflows
volatile uint8_t tot_overflow;

// initialize timer, interrupt and variable
void timer0_init()
{
	// set up timer with prescaler = 256
	TCCR0A |= (1 << CS02);
	
	// initialize counter
	TCNT0 = 0;
	
	// enable overflow interrupt
	TIMSK0 |= (1 << TOIE0);
	
	// enable global interrupts
	sei();
	
	// initialize overflow counter variable
	tot_overflow = 0;
}

// TIMER0 overflow interrupt service routine
// called whenever TCNT0 overflows
ISR(TIMER0_OVF_vect)
{
	// keep a track of number of overflows
	tot_overflow++;
}

int main(void)
{
	// connect led to pin PB5
	DDRB = (1 << PORTB5);
	
	// initialize timer
	timer0_init();
	
	// loop forever
	while(1)
	{
		// check if no. of overflows = 254
		if (tot_overflow >= 254)  // NOTE: '>=' is used
		{
			// check if the timer count reaches 53
			if (TCNT0 >=1)
			{
				PORTB ^= (1 << PORTB5);    // toggles the led
				TCNT0 = 0;            // reset counter
				tot_overflow = 0;     // reset overflow counter
			}
		}
	}
}