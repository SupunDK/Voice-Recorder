/*
 * Recorder.cpp
 *
 * Created: 5/19/2021 6:10:29 PM
 *  Author: Wikum JCK
 */ 
//Functions for Serial Out
#include <avr/io.h>

void UART_Init(unsigned int baud){
	unsigned int ubrr = (16000000/16/baud-1);
	UBRR0H =(unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B =(1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
}

void UART_putc(unsigned char data)
{
	// wait for transmit buffer to be empty
	while(!(UCSR0A & (1 << UDRE0)));
	// load data into transmit register
	UDR0 = data;
}

/*Sending a String*/
void UART_puts(char* s)
{
	// transmit character until NULL is reached
	while(*s > 0) UART_putc(*s++);
}