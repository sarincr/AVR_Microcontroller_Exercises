// Create a Dancing light of 8 LEDs connected to PORT B
#include <avr/io.h> // Adding GPIO Libraries
#include <util/delay.h>   //Adding a delay

#define DELAYTIME 1000 // Setting Delay of 1000

int main(void)
{
  int i=0;  // Set some random variable i=0
  DDRB = 0xFF;   // Setting up of all Pins of PORT B as Output
  while (1)
  {
	  while (i < 7)
	  {
		  PORTB = PORTB + i;   // Adding 'i'th port of PORTB to Logic High
		  _delay_ms(DELAYTIME);  // Add a delay
		  i = i + 1;   //increment i
	  }

	  while (i > 0)
	  {
		  PORTB = PORTB - i;   // Adding 'i'th port of PORTB to Logic High
		  _delay_ms(DELAYTIME);  // Add a delay
		  i = i - 1;   //increment i
	  }
  }
  return 0;
}
