
#include <avr/io.h>
#include <avr/interrupt.h>
int overflow_count=0;  // overflow variable declaration 
int main(void)
{
	DDRB=1<<PORTB5; // Pin 5 of PORT B as Output 
    TCCR0A=1<<WGM01;  // Timer run on CTS mode 
	TCCR0B=(1<<CS02)|(1<<CS00);  // Prescaler value is 1024
	OCR0A=255;  // Timer overflow count = 255 which will create a delay of 
	sei(); // Start an Interrupt 
	TIMSK0=(1<<OCIE0A);
    while (1) 
    {
    }
}

ISR(TIMER0_COMPA_vect)
{
	overflow_count++; // increment overflow flag
	if(overflow_count>61)  // Overflow flag will set up on 0.016s , so it may count upto 61 = 1/0.016
	{
		overflow_count=0;    // Reset counter
		PORTB^=(1<<PORTB5);  // Toggle the ports 
	}
	
}

