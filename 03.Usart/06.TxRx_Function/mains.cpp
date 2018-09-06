#include <avr/io.h>
#include <util/delay.h>

static void
serial_init(unsigned int bittimer)
{
	/* Set the baud rate */
	UBRR0H = (unsigned char) (bittimer >> 8);
	UBRR0L = (unsigned char) bittimer;
	/* set the framing to 8N1 */
	UCSR0C = (3 << UCSZ00);
	/* Engage! */
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	return;
}

static unsigned char
serial_read(void)
{
	while( !(UCSR0A & (1 << RXC0)) );
	return UDR0;
}

static void
serial_write(unsigned char c)
{
	while ( !(UCSR0A & (1 << UDRE0)) );
	UDR0 = c;
}

#define SPEED 9600

int main (void)
{
	/* let the preprocessor calculate this */
	serial_init( ( F_CPU / SPEED / 16 ) - 1);

	while (1) {
		/* read a character and echo back the next one */
		serial_write( serial_read());
	}
	return 0;
}

