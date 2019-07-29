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
  DDRB |= (1<<5); // Defining 5th Pin of PORT B as output
  DDRB |= (1<<4); // Defining 4th Pin of PORT B as output
  while(1) // A infinite loop unless returned 0
  {
    PORTB |=(1<<5); //Setting 5th Pin of PORT B to HIGH
    _delay_ms(100); // Adding 1000ms second delay
    PORTB &= ~(1 << 5);   //Setting 5th Pin of PORT B to LOW
    _delay_ms(100); // Adding 1000ms second delay
    PORTB |=(1<<4); //Setting 4th Pin of PORT B to HIGH
    _delay_ms(100); // Adding 1000ms second delay
    PORTB &= ~(1 << 4);   //Setting 4th Pin of PORT B to LOW
    _delay_ms(100); // Adding 1000ms second delay
  }
}
