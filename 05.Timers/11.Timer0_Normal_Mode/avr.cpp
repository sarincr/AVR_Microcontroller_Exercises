#include <avr/io.h>
 

int main(void)
{
     
   DDRB |= (1 << PB5);
 
   TCCR0B |= (1 << CS00)|(1 << CS02); // Prescale of 1/1024
  
   TCNT0 = 0; // TCNT0 value is set to zero at start 
 
    while(1)  // Infinite loop
    {
       
        if (TCNT0 >= 255)
        {
            PORTB ^= (1 << PB5);   // Toggle port b   
            TCNT0 = 0;   // Timer count to zero          
        }
    }
}
