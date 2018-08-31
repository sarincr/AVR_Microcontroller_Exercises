
#include <avr/io.h>   // Adding AVR Library.
// https://www.microchip.com/webdoc/AVRLibcReferenceManual/group__avr__io.html

void delay_ms(unsigned int k)
{
    volatile unsigned int i;
    for(i = 0; i <= k; i++);
}


int main(void)
{
  DDRB |= 0x20; // Defining 5th Pin of PORT B as output 0b00100000

  while(1) // A infinite loop unless returned 0
  {
    PORTB |= 0x20; //Setting 5th Pin of PORT B to HIGH - 0b00100000
    delay_ms(26000); // Adding second delay
    PORTB &=  0x00;   //Setting 5th Pin of PORT B to LOW -0b00000000
    delay_ms(26000); // Adding  delay

  }
}
