
#include <avr/io.h>


int main(void)
{
	DDRD |= 0xFF;
	// PD6 is now an output

	OCR0B = 128;
	// set PWM for 50% duty cycle


	TCCR2A |= (1 << COM2A1);
	// set none-inverting mode

	TCCR2A |= (1 << WGM21) | (1 << WGM20);
	// set fast PWM Mode

	TCCR2B |= (1 << CS21);
	// set prescaler to 8 and starts PWM


	while (1);
	{
		// we have a working Fast PWM
	}
}