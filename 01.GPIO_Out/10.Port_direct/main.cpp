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
  DDRB |= (1 << PB5); // Defining 5th Pin of PORT B as output 0b00100000
  DDRB |= (1 << PB4); // Defining 4th Pin of PORT B as output 0b00010000
  while(1) // A infinite loop unless returned 0
  {
    PORTB |=(1 << PB5); //Setting 5th Pin of PORT B to HIGH - 0b00100000
    _delay_ms(1000); // Adding 1000ms second delay
    PORTB &=  0x00;   //Setting 5th Pin of PORT B to LOW -0b00000000
    _delay_ms(1000); // Adding 1000ms second delay
    PORTB |= (1 << PB4); //Setting 4th Pin of PORT B to HIGH  - 0b00010000
    _delay_ms(1000); // Adding 1000ms second delay
    PORTB &=  0x00;   //Setting 4th Pin of PORT B to LOW  - 0b00000000
    _delay_ms(1000); // Adding 1000ms second delay
  }
}
