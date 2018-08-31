//Blinking Selected Pins only , eg : PB5

#ifndef F_CPU
#define F_CPU 16000000UL // Defining CPU Frequency as 16 MHz
#endif

#include <avr/io.h>   // Adding AVR Library.
// https://www.microchip.com/webdoc/AVRLibcReferenceManual/group__avr__io.html
#include <util/delay.h> //Adding delay Library
// Refer https://www.microchip.com/webdoc/AVRLibcReferenceManual/group__util__delay.html
int main(void)
{
for(int i=0x00; i < 0xFF; i++)
{
  DDRB |= i; // Defining 5th Pin of PORT B as output 0b00100000
}
while(1) // A infinite loop unless returned 0
  {
	  for(int i=0x00; i < 0xFF; i++)
	  {
	PORTB |= i; //Setting 5th Pin of PORT B to HIGH - 0b00100000
    _delay_ms(1000); // Adding 1000ms second delay
    PORTB &= 0x00;   //Setting 5th Pin of PORT B to LOW -0b00000000
    _delay_ms(1000); // Adding 1000ms second delay
	  }
  }
  }
