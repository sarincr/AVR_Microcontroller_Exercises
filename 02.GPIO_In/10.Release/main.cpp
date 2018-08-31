#include <avr/io.h>
int main(void)
{
	DDRB |= 1 << PINB5; //Set Zeroth pin of Port B as Output
	DDRD &= ~(1 << PIND2); //Set First pin of Port B as Output which is taken as input
	int Pressed = 0; //Initialize the variable Pressed to Zero

	while (1)
	{
		if (bit_is_clear(PIND, 2)) //Check is the Button on PIN B1 is pressed
		{
			if (Pressed == 0) // Check button is released
			{
				PORTB ^= 1 << PINB5; //Toggle the LED connected to PIN B5
				Pressed = 1;
			}
		}
		else
		{
			Pressed = 0; // This will differ the button unpressed from released
		}
	}
}
