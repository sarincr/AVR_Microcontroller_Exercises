// Create a Dancing light with binary counter of 8 LEDs connected to PORT B
#include <avr/io.h> // Adding GPIO Libraries
#include <util/delay.h>   //Adding a delay

#define DELAYTIME 1000 // Setting Delay of 1000

int main(void)
{
  int i=0;  // Set some random variable i=0  DDRB = 0xFF;   // Setting up of all Pins of PORT B as Output
  while (1)
  {
	  for (i = 0; i < 255; i++)
	  {
		  PORTB |= (1 << i);
	      _delay_ms(DELAYTIME);
	  }
  }
  return 0;
}
