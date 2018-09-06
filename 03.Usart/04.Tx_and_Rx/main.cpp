 #include <avr/io.h>
 #include <util/delay.h>
 #include <stdlib.h>
                                                      // include LCD library
#define FOSC 16000000                       // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD -1

 void uart_init (void)
 {
     UBRR0H=(MYUBRR>>8);
     UBRR0L=MYUBRR;                                                 //set baud rate
     UCSR0B|=(1<<TXEN0)|(1<<RXEN0);                     //enable receiver and transmitter
     UCSR0C|=(1<<UCSZ00)|(1<<UCSZ01);// 8bit data format
 }

 // function to send data - NOT REQUIRED FOR THIS PROGRAM IMPLEMENTATION
 void uart_transmit (unsigned char data)
 {
     while (!( UCSR0A & (1<<UDRE0)));                  // wait while register is free
     UDR0 = data;                                                     // load data in the register
 }

 // function to receive data
 unsigned char uart_recieve (void)
 {
     while(!(UCSR0A) & (1<<RXC0));                     // wait while data is being received
     return UDR0;                                                     // return 8-bit data
 }

 // main function: entry point of program
 int main (void)
 {
     unsigned char a;
     char buffer[10];

     uart_init();                                                    // initialize UART

     while(1)
     {

         uart_transmit( uart_recieve());

         _delay_ms(1000);
     }

     return 0;
 }
