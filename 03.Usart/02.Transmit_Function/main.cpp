#include <avr/io.h>
#include <string.h>
#define F_CPU 16000000
#define BUAD 9600
#define BUAD_RATE_CALC ((F_CPU/16/BUAD) - 1)

void serialSetup(void);
void serialSend(char* sendString);

char ar[]= "hello worlds";

void serialSetup()
{
     
    UBRR0H = (BUAD_RATE_CALC >> 8);
    UBRR0L = BUAD_RATE_CALC;
    UCSR0B = (1 << TXEN0)| (1 << TXCIE0) | (1 << RXEN0) | (1 << RXCIE0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);  
}
void serialSend(char* sendString)
{
     for (int i = 0; i < strlen(sendString); i++){
         while (( UCSR0A & (1<<UDRE0))  == 0){};
         UDR0 = sendString[i];
     }
}

int main(void)
{
    serialSetup();
    while(1)
    {
      serialSend(ar);
     }
}
