/*
 * lcdatmel.c
 *
 * Created: 22/04/2021 12:37:40
 * Author : HP
 */ 


#define F_CPU 8000000UL					/* Define CPU Frequency 8MHz */
#include <avr/io.h>						/* Include AVR std. library file */
#include <util/delay.h>					/* Include inbuilt defined Delay header file */


#define LCD_Data_Dir DDRB				/* Define LCD data port direction */
#define LCD_Command_Dir DDRC			/* Define LCD command port direction register */
#define LCD_Data_Port PORTB				/* Define LCD data port */
#define LCD_Command_Port PORTC			/* Define LCD data port */
#define RS PC0							/* Define Register Select (data reg./command reg.) signal pin */
#define RW PC1							/* Define Read/Write signal pin */
#define EN PC2							/* Define Enable signal pin */

int menu=1;

void LCD_Command(unsigned char cmnd)
{
	LCD_Data_Port= cmnd;
	LCD_Command_Port &= ~(1<<RS);		/* RS=0 command reg. */
	LCD_Command_Port &= ~(1<<RW);		/* RW=0 Write operation */
	LCD_Command_Port |= (1<<EN);		/* Enable pulse */
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(3);
}

void LCD_Char (unsigned char char_data)	/* LCD data write function */
{
	LCD_Data_Port= char_data;
	LCD_Command_Port |= (1<<RS);		/* RS=1 Data reg. */
	LCD_Command_Port &= ~(1<<RW);		/* RW=0 write operation */
	LCD_Command_Port |= (1<<EN);		/* Enable Pulse */
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(1);
}

void LCD_Init (void)					/* LCD Initialize function */
{
	LCD_Command_Dir = 0xFF;				/* Make LCD command port direction as o/p */
	LCD_Data_Dir = 0xFF;				/* Make LCD data port direction as o/p */
	_delay_ms(20);						/* LCD Power ON delay always >15ms */
	
	LCD_Command (0x38);					/* Initialization of 16X2 LCD in 8bit mode */
	LCD_Command (0x0C);					/* Display ON Cursor OFF */
	LCD_Command (0x06);					/* Auto Increment cursor */
	LCD_Command (0x01);					/* clear display */
	LCD_Command (0x80);					/* cursor at home position */
}

void LCD_String (char *str)				/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)				/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);
	}
}

void LCD_Clear()
{
	LCD_Command (0x01);					/* clear display */
	LCD_Command (0x80);					/* cursor at home position */
}

void updateMenu() {
	switch (menu) {
		case 0:
			menu = 4;
			LCD_Clear();
			LCD_String(" Song3");
			LCD_Command(0xc0);			/*Move cursor to the beginning of second line*/
			LCD_String(">Song4");
			break;
		case 1:
			LCD_Clear();
			LCD_String(">Song1");
			LCD_Command(0xc0);
			LCD_String(" Song2");
			break;
		case 2:
			LCD_Clear();
			LCD_String(" Song1");
			LCD_Command(0xc0);
			LCD_String(">Song2");
			break;
		case 3:
			LCD_Clear();
			LCD_String(">Song3");
			LCD_Command(0xc0);
			LCD_String(" Song4");
			break;
		case 4:
			LCD_Clear();
			LCD_String(" Song3");
			LCD_Command(0xc0);
			LCD_String(">Song4");
			break;
		case 5:
			menu = 1;
			LCD_Clear();
			LCD_String(">Song1");
			LCD_Command(0xc0);
			LCD_String(" Song2");
			break;
	}
}


void executeAction() {
	switch (menu) {
		case 1:
			LCD_Clear();
			LCD_String(">Playing Song1");
			_delay_ms(150);
			break;
		case 2:
			LCD_Clear();
			LCD_String(">Playing Song2");
			_delay_ms(150);
			break;
		case 3:
			LCD_Clear();
			LCD_String(">Playing Song3");
			_delay_ms(150);
			break;
		case 4:
			LCD_Clear();
			LCD_String(">Playing Song4");
			_delay_ms(150);
			break;
	}
}


int main(void)
{
	
	LCD_Init();							/* Initialize LCD */
	DDRD = 0x00;						/* Make all PD pins as input*/
	PORTD = PORTD | (1<<0);				/* Enable pull-up on PD0 by writing 1 to it */
	PORTD = PORTD | (1<<1);				/* Enable pull-up on PD1 by writing 1 to it */
	PORTD = PORTD | (1<<2);				/* Enable pull-up on PD2 by writing 1 to it */

	LCD_String("Voice Recorder");		/* write string on 1st line of LCD*/

	_delay_ms(100);
	updateMenu();
	
	while (1)
	{
		if ((PIND & 0x02)==0x00){		/*TRUE if the down button(PD1) is pressed*/
			++menu;
			updateMenu();
			while ((PIND & 0x02)==0x00);
		}
		if ((PIND & 0x01)==0x00){		/*TRUE if the up button(PD0) is pressed*/
			--menu;
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
