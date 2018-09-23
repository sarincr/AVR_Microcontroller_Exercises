
#include <avr/io.h>
#include <stdint.h>       
int  ADCval, ADCvalue; 

int main(void)
{
    int ADCvalue,ADCval;// Varible for ADC Declaration 
    DDRB=1<<PB5;  // Port B , Pin 5 is made as Output 
    ADMUX = 0x01; // Select  ADC1/PC1
    ADMUX |= (1 << REFS0);    //  AVCC with external capacitor at AREF pin
    ADMUX &= ~(1 << ADLAR);   //  ADLAR: ADC Left Adjust Result
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);    // 128 prescale for 16Mhz
    ADCSRA |= (1 << ADEN);    // ADC Enable. Writing this bit to one enables the ADC. By writing it to zero, the ADC is turned off. 
    ADCSRA |= (1 << ADATE);   // Set ADC Auto Trigger Enable
    ADCSRB = 0;               // 0 for free running mode
    ADCSRA |= (1 << ADIE);    // Enable Interrupts 
    sei();

    
    while (1)
    {
        
    }
}


ISR(ADC_vect)   //ADC_Interupt
{
            ADCval = ADCL;     // First 8 Bit value 
            ADCvalue = (ADCH << 8) + ADCval;  // Total value = H+L
            if(ADCvalue>500)
            {
              PORTB=1<<PB5;  // PORTB to High
            }
            if(ADCvalue<500)
            {
              PORTB=0x00;  // PORTB to Low
            }
}
