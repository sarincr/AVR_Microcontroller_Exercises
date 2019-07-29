# include <avr/io.h>

int main (void)
{
   DDRB = (1<<PB5); // Setting up Fifth Pin of Port B as Output  
   DDRD &= ~(1 << PD2);  // Setting up Second Pin of Port D as Input. AND will add 0 to that point

    while (1)
    {
        if (PIND & (1<<PD2))  // Comparing the status of Pin 2 of Port D with PIND register
        {
            PORTB |= (1<<PB5);   // Setting up Fifth Pin of Port 5 to Logic High
        }
        else
        {
            PORTB &= ~(1<<PB5); // Setting up Fifth Pin of Port 5 to Logic High
        }
    }
    return 0;
}
