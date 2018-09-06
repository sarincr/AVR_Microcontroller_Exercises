#include <avr/io.h>
int main(void)
{
DDRB |= (1 << PINB5); // PORB Pin 5 as output
int UBRR_Value = 25; //This is for 2400 baud
UBRR0H = (unsigned char) (UBRR_Value >> 8);  //Setting up Baud rate Upper byte
UBRR0L = (unsigned char) UBRR_Value;  //Setting up Baud rate Lower byte
UCSR0B = (1 << RXEN0) | (1 << TXEN0);  // Enable transmit and receive Data Enable
UCSR0C = (1 << USBS0) | (3 << UCSZ00);     //8 Bit Data

unsigned char receiveData;  // Variable declaration
while (1)
{
while (! (UCSR0A & (1 << RXC0)) );  // Wait until data arrives

receiveData = UDR0;  //Store data to Variable

if (receiveData == 0)
	{
	PORTB ^= (1 << PINB5);  // Toggling PORT B5 if received is Zero
	}
}
}
