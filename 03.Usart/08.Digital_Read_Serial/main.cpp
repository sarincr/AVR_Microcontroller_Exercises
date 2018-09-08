#include <avr/io.h>
#define F_CPU 16000000  // Setting CPU Speed to 16 MHz
#define BUAD 9600  // Setting required Baud Rate variable to 9600
#define BUAD_RATE_CALC ((F_CPU/16/BUAD) - 1)
 char ar[]= "c";
int main(void)
{
	UBRR0H = (BUAD_RATE_CALC>> 8); // Upper bit of Baud Rate
	UBRR0L = BUAD_RATE_CALC; // Lower bit of Baud Rate
     DDRB=0xFF;
     DDRD=0x00;

    UCSR0C |= (1 << UCSZ01);  //8 bit data format
    UCSR0C |= (1 << UCSZ00);  //8 bit data format
	UCSR0B |= (1 << TXEN0); // Enabling transmitting
	UCSR0B |= (1 << RXEN0);  // Enabling Receiving
	UCSR0B |= (1 << TXCIE0); // Enabling Transmitter interrupt.
	UCSR0B |= (1 << RXCIE0);	 // Enabling Receiver interrupt.
    while(1)
    {

    	 if (PIND & (1<<PD2))  // Comparing the status of Pin 2 of Port D with PIND register
    	 {
    	            PORTB |= (1<<PB5);   // Setting up Fifth Pin of Port 5 to Logic High
    	            ar[0]= "0";
    	 }
    	 else
    	 {
    	            PORTB &= ~(1<<PB5); // Setting up Fifth Pin of Port 5 to Logic High
    	            ar[0]= "1";
    	 }
    	 while (( UCSR0A & (1<<UDRE0))  == 0){}; // Waits until transmission bit is ready
    	     	UDR0 = ar[0];


    }
}
