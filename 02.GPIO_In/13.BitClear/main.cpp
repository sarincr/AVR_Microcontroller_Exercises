 #include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  DDRB |= 1 << PINB3;
  DDRD &= ~(1 << PIND5);
  PORTD |= 1 << PIND5;
  while (1)
  {
    PORTB ^= 1 << PINB3;
    if (bit_is_clear(PIND, 5))
    {
      _delay_ms(1000);
    }
    else
    {
      _delay_ms(100);
    }
  }
}
