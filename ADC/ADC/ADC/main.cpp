/*
 * ADC.cpp
 *
 * Created: 2021-04-22 10:16:49 AM
 * Author : Supzuroke
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000 // Setting the CPU speed to 16 MHz
#include <util/delay.h>

#include "adc.h"
#include "buttons.h"

int main(void)
{
	setup_recording_btn();
	
	while(1)
	{
		
	}
}

