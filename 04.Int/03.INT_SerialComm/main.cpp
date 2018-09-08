
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

#define FOSC 16000000	//Define Clock Speed
#define BAUD 9600	//Define Baud Rate
#define UBRRn FOSC/16/BAUD -1  //Baud Rate calculation with respect to FOSC

volatile char ReceivedChar;  // Variable declaration


void initSerial();  // Function Declaration
void enableSerialEcho(); //Function Declaration

void setup()   // Setup initial values
{
  initSerial();
  enableSerialEcho();
}


void initSerial()
{
  UBRR0H = (unsigned char)(UBRRn>>8);  //Assigning Baud Rate upper bits
  UBRR0L = (unsigned char)UBRRn;       //Assigning Baud Rate upper bits

  UCSR0B = (1<<RXEN0) | (1<<TXEN0);    // Enabling Interrupt
  UCSR0C = (1<<USBS0) | (3<<UCSZ00);   // Data bit length and type
}

void enableSerialEcho()
{
  cli(); // Clearing  Interrupt
  UCSR0B |= (1<<RXCIE0);  // Enable RX Complete Interrupt
  sei();
}

ISR(USART_RX_vect)
{
  ReceivedChar = UDR0;
  UDR0 = ReceivedChar;

}
