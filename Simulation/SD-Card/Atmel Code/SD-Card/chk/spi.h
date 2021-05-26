#include <avr/io.h>
#include <util/delay.h>

void init_spi(void)
{
  DDRB=0xBF;
  PORTB=0x40;
  SPCR=0x52;
  SPSR=0x00;
}


void xmit_spi(BYTE data)
{
   SPDR = data;
   while (!(SPSR & ( 1 << SPIF )));
    
}
BYTE rcv_spi (void)
{
    SPDR=0xFF;
    while (!(SPSR & ( 1 << SPIF )));
    return SPDR;
}



void dly_100us (void)
{
  _delay_ms(100);
}