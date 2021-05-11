/*
 * SD-Card.cpp
 *
 * Created: 4/24/2021 1:35:39 PM
 * Author : WikumJCK
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "pff.h"
#include "diskio.h"

#define F_CPU 16000000
#define BUAD 9600
#define UBRR (F_CPU/16/BUAD-1)


uint8_t RecBtn = 2; //Pins for Recording and Playing the voice Samples
uint8_t PlayBtn =3;

uint8_t led1  = 5;
uint8_t led2  = 6;

void USRT_Init(unsigned int ubrr);
void Serial_Out(const char* mess);


BYTE res;
FATFS fs; //Mounting SD card
DIR dir; // File Directory Object
FILINFO fno; //File information





int main(void)
{
	PORTB = 0b101011;//Setting up pins for SD card
	DDRB = 0b001110;
	
	USRT_Init(UBRR);

	//Initializing disk and Mount disk and checking
	res = disk_initialize();
	if (res ==0)
	{
		Serial_Out("1");
	}
	if (pf_mount(&fs)==FR_DISK_ERR)
	{
		Serial_Out("2");
	}
	if (pf_open("wav.txt")==FR_OK)
	{
		Serial_Out("3");
	}


	//Configuring Pins
	DDRD = 0b11110011;//Setting RecBtn and PlayBtn as Inputs
	PORTD = 0b00001100;//Adding Input pull up to that buttons
	
	EIMSK = (1<< INT0)|(1<<INT1);//Adding External interrupts
	EICRA =  (1<<ISC00) |(1<<ISC01)|(1<<ISC10)|(1<<ISC11);  //Interrupt occur at rising edge

	sei();
	
	while (1)
	{
		_delay_ms(500);
	}

	return 0;
}

//Interrupts for buttons
ISR(INT0_vect){
	PORTD ^=(1<<led1);
	//ReadFile();
}

ISR(INT1_vect){
	PORTD ^=(1<<led2);
	_delay_ms(500);
}


//Fuctions for Serial Out
void USRT_Init(unsigned int ubrr){
	UBRR0H =(unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B =(1<<TXEN0);
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
}

void Serial_Out(const char* mess){
	for (uint8_t i=0;i<sizeof(mess);i++)
	{
		while (!(UCSR0A & (1<<UDRE0)));
		UDR0 = mess[i];
	}
}



