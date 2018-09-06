#include <avr/io.h>
#define F_CPU 16000000  // Setting CPU Speed to 16 MHz
#define BUAD 9600  // Setting required Baud Rate variable to 9600
#define BUAD_RATE_CALC ((F_CPU/16/BUAD) - 1)   // =0x67 Calculating Baud rate from CPU speed and Required Baud rate


int main(void)
{
	char ar[]= "Hello  ";  //Character to be send
    UBRR0H = (0x67>> 8); // Upper bit of Baud Rate
	UBRR0L = 0x67; // Lower bit of Baud Rate


    UCSR0C |= (1 << UCSZ01);  //8 bit data format
    UCSR0C |= (1 << UCSZ00);  //8 bit data format
	UCSR0B |= (1 << TXEN0); // Enabling transmitting
	UCSR0B |= (1 << RXEN0);  // Enabling Receiving
	UCSR0B |= (1 << TXCIE0); // Enabling Transmitter interrupt.
	UCSR0B |= (1 << RXCIE0);	 // Enabling Receiver interrupt.
    while(1)
    {
    	 for (int i = 0; i < 6; i++)
    	    {
    		 // UDRE0 bit indicates whether Transmit data buffer Data Register empty

    		 	 while (( UCSR0A & (1<<UDRE0))  == 0){}; // Waits until transmission bit is ready
    	         UDR0 = ar[i];
    	      }
    }
}
