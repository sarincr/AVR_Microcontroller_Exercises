#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB |= (1 << DDB4)|(1<<DDB4); // Setting up PB4 and PB5 as Output
	DDRB &= ~(1 << DDD2);  // Setting up PD2 as Input


		while (1)
		{

			if (!(PIND&(1<<PIND2)))  // Checking if status of PD2 is High, PIND returns Status of Port D
			{
				PORTB ^= (1<<PINB4)^(1<<PINB5);  // Toggle PB5 and PB4 to Logic High
				_delay_ms(300);  // Add a delay of 300ms.
			}
		}
}
