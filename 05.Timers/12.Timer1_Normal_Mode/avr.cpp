#include <avr/io.h>
 

int main(void)
{
     
   DDRB |= (1 << PB5)|(1 << PB4);
 
   TCCR1B |= (1 << CS12)|(1 << CS10); // Prescale of 1/1024
  
   TCNT1 = 0; // TCNT0 value is set to zero at start 
 
    while(1)  // Infinite loop
    {
       
        if (TCNT1 >= 10000)
        {
            PORTB ^= (1 << PB5);   // Toggle port b   
            TCNT1= 0;   // Timer count to zero          
        }
        
        if (TCNT1 >= 5000)
        {
            PORTB ^= (1 << PB4);   // Toggle port b   
                    
        }
    }
}
