

#define F_CPU 8000000UL    
#include <avr/io.h>   
#include <util/delay.h>  
#include <stdlib.h>  

void ADC_Init()    
{
  DDRB = 1<<PB5;    
  ADCSRA = 0x87;   
  ADMUX = 0x40;  
}

int ADC_Read(char channel)
{
  ADMUX = 0x40 | (channel & 0x07); 
  ADCSRA |= (1<<ADSC);
  while (!(ADCSRA & (1<<ADIF)));  
  ADCSRA |= (1<<ADIF); 
  _delay_ms(1);   
  return ADCW; 
}



int main(void)
{
  int ADC_X_VALUE,ADC_Y_VALUE,ADC_Z_VALUE;
  double Axout,Ayout,Azout,theta, psy, phi,roll,pitch,yaw;
  Serial.begin(9600);  
  ADC_Init();  
  DDRB |= 1<<PB1; // PORT B Pin 1 as Input
  TCCR1A |= 1<<WGM11 ;  //  Fast PWM with ICR1
  TCCR1A |=  1<<COM1A1 | 1<<COM1A0;  //  Set OC1A/OC1B on Compare Match (Set output to highlevel).
  TCCR1B |= 1<<WGM13 | 1<<WGM12 ;  //  Fast PWM with ICR1
  TCCR1B |=  1<<CS11;  //  Prescaler of 1/8 
  ICR1 = 100;  //  16MHz/20000Hz  / 8 Prescaler  = 99
  sei();

  while(1)
  {
    ADC_X_VALUE = ADC_Read(0); 
    ADC_Y_VALUE = ADC_Read(1);
    ADC_Z_VALUE = ADC_Read(2);
    Axout = (((double)(ADC_X_VALUE*5)/1.024)-1600.0)/330.0; 
    Ayout =5+ (((double)(ADC_Y_VALUE*5)/1.024)-1600.0)/330.0;
    Azout = (((double)(ADC_Z_VALUE*5)/1.024)-1600.0)/330.0;
    Ayout=10*Ayout;
    OCR1A=Ayout;

    Serial.println(ADC_X_VALUE);
    Serial.println(Ayout);
    Serial.println( Azout);
    Serial.println(".........................");


    _delay_ms(1000);
    
  }
}
