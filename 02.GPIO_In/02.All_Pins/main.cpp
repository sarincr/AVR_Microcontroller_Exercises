#include <avr/io.h>
#include <util/delay.h>



int main(void) //main starts

{
  DDRB = 0xFF ; 
  DDRD = 0x00;
  while (1)  
  {
    if(PIND & (1<<5) ) 
    {
    PORTB = 0xFF;  
    }
    else  
    {
      PORTB = 0x00 ;
    }
  }
}

 
