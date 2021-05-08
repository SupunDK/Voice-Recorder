/*
 * GccApplication.c
 *
 * Author : CodE_BlacK
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "i2c.h"
#include "LCD_I2C.h"
#include <avr/interrupt.h>

int pointer=1;

void updateMenu() {
	switch (pointer) {
		case 0:
		pointer = 4;
		lcd_clrscr();
		lcd_msg(" Song3");
		lcd_cmd(0xc0);			/*Move cursor to the beginning of second line*/
		lcd_msg(">Song4");
		break;
		case 1:
		lcd_clrscr();
		lcd_msg(">Song1");
		lcd_cmd(0xc0);
		lcd_msg(" Song2");
		break;
		case 2:
		lcd_clrscr();
		lcd_msg(" Song1");
		lcd_cmd(0xc0);
		lcd_msg(">Song2");
		break;
		case 3:
		lcd_clrscr();
		lcd_msg(">Song3");
		lcd_cmd(0xc0);
		lcd_msg(" Song4");
		break;
		case 4:
		lcd_clrscr();
		lcd_msg(" Song3");
		lcd_cmd(0xc0);
		lcd_msg(">Song4");
		break;
		case 5:
		pointer = 1;
		lcd_clrscr();
		lcd_msg(">Song1");
		lcd_cmd(0xc0);
		lcd_msg(" Song2");
		break;
	}
}

void executeAction() {
	switch (pointer) {
		case 1:
		lcd_clrscr();
		lcd_msg(">Playing Song1");
		_delay_ms(150);
		break;
		case 2:
		lcd_clrscr();
		lcd_msg(">Playing Song2");
		_delay_ms(150);
		break;
		case 3:
		lcd_clrscr();
		lcd_msg(">Playing Song3");
		_delay_ms(150);
		break;
		case 4:
		lcd_clrscr();
		lcd_msg(">Playing Song4");
		_delay_ms(150);
		break;
	}
}

volatile uint8_t portdhistory = 0xFF;

ISR (PCINT2_vect){
	uint8_t intreading = PIND & 0x38; //Status of interrupt pins
	uint8_t change = intreading ^ portdhistory; //Check the toggled buttons
	portdhistory = intreading; //Save the current status
	
	switch(change){
		case 0x10:
		if (PIND & 0x10){		//rec is pressed
			lcd_clrscr();
			lcd_msg("Recording...");						
		}
		break;
		case 0x20:
		if (PIND & 0x20){		//stop is pressed
			lcd_clrscr();
			lcd_msg("Recording finished");
			_delay_ms(200);
			updateMenu();
		}
		break;
		case 0x8:
		if (PIND & 0x8){		//menu is pressed
			lcd_clrscr();
			updateMenu();
		}
		break;
	}
}


int main(void)
{
    i2c_init();
	i2c_start();
	i2c_write(0x70);
	lcd_init();
	lcd_msg("Voice Recorder");		/* write string on 1st line of LCD*/
	
	_delay_ms(100);
	updateMenu();
	
	DDRD = 0x00;   // Make all PD pins as input
	PORTD |= 0xFF; // Enable pull up at all PD pins
	PCICR |= (1<<PCIE2);
	PCMSK2 |= (1<<PCINT20) | (1<<PCINT21)| (1<<PCINT19);
	sei();
	
    while (1) 
    {	
		if ((PIND & 0x02)==0x00){		/*TRUE if the down button(PD1) is pressed*/
			++pointer;
			updateMenu();
			while ((PIND & 0x02)==0x00);
		}
		if ((PIND & 0x01)==0x00){		/*TRUE if the up button(PD0) is pressed*/
			--pointer;
			updateMenu();
			while ((PIND & 0x01)==0x00);
		}
		if ((PIND & 0x04)==0x00){ /*TRUE if the down button(PD1) is pressed*/
			executeAction();
			updateMenu();
			while ((PIND & 0x04)==0x00);
		}
    }
}

