#include <avr/io.h>
#include <util/delay.h>



int main(void) //main starts

{
  DDRB = DDRB | ( 1<<3) ; //Make pin 4 of port B as a output
  DDRD = DDRD & ~(1<<5) ; // Make pin 5 of port D as a input
  while (1) //initialize while loop
  {
    if(PIND & (1<<5) ) // if PIN5 of port D is high
    {
    PORTB = PORTB | ( 1<<3) ; //PIN3 of port D is high
    }
    else //otherwise
    {
      PORTB = PORTB &  ~( 1<<3) ; //PIN3 of port D will remain low
    }
  }
}

 
