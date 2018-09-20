 
 #include <avr/io.h>
 #include <avr/interrupt.h>
 
 int main(void)
 {
	 DDRB = 0xFF;
	 
	 TCCR1B = (1 << WGM12);
	 OCR1A = 15625;
	 TIMSK1 = (1 << OCIE1A);
	 
	 sei();
	 
	 TCCR1B |= (1 << CS12) | (1 << CS10);
	 
	 while(1)
	 {
		 
	 }
 }
 
 ISR(TIMER1_COMPA_vect)
 {
	 PORTB ^= (1 << PORTB5);
 }