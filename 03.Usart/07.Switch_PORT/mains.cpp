#include <avr/io.h>
#include <util/delay.h>
char x;
static void
serial_init(unsigned int bittimer)
{

	UBRR0H = (unsigned char) (bittimer >> 8);
	UBRR0L = (unsigned char) bittimer;
	UCSR0C = (3 << UCSZ00);
 	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	return;
}

static unsigned char serial_read()
{
	while( !(UCSR0A & (1 << RXC0)) );
	return UDR0;
}

static void serial_write(unsigned char c)
{
	while ( !(UCSR0A & (1 << UDRE0)) );
	UDR0 = c;
}

#define SPEED 9600

int main (void)
{
    DDRB=0xFF;
	serial_init( ( F_CPU / SPEED / 16 ) - 1);

	while (1)
	{

    x=serial_read();
    serial_write(x);
    	switch(x)
    	{
    	case 'a':
    	{
		PORTB=1<<PB5;
		break;
    	}
    	case 'b':
    	{
    		PORTB=0<PB5;
    		break;
		}
    }
	}
	return 0;
}

