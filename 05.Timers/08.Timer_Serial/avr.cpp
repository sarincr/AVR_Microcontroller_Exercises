#include <util/delay.h>
int  duty_cycle=0;	// Initialise the Duty Cycle variable 
#define F_CPU 16000000  // Setting CPU Speed to 16 MHz
#define BUAD 9600  // Setting required Baud Rate variable to 9600
#define BUAD_RATE_CALC ((F_CPU/16/BUAD) - 1)
int main(void)
{

    DDRB |= (1<<PORTB1); // PORTB Pin 1 as OUTPUT
    ICR1 = 0x00FF; // Max count of Timer 1 to 0xFF
    TCCR1A |= (1 << COM1A1)|(1 << COM1B1); //Set OC1A/OC1B on Compare Match, clear OC1A/OC1B at BOTTOM (inverting mode)
    TCCR1A |= (1 << WGM11); // PWM, Phase Correct, 9-bit
    TCCR1B |= (1 << WGM12)|(1 << WGM13);  // CTC Mode -  set Fast PWM mode using ICR1 as TOP
    TCCR1B |= (1 << CS10);     // No presc
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
  for(;;) // Infinte loop 
  {            
    for(duty_cycle=0;duty_cycle < 255;duty_cycle++)   
    {
      OCR1A=duty_cycle;
       _delay_ms(10);
    }
     for(duty_cycle=255;duty_cycle>0;duty_cycle--)   
    {
      OCR1A=duty_cycle;
       _delay_ms(10);
       serial_write(duty_cycle);
    }
   
  }
       
}



char serial_write(unsigned char c)
{
	while ( !(UCSR0A & (1 << UDRE0)) );
	UDR0 = c;
}
