/*
 * timer01.c
 *
 * Created: 5/12/2021 5:36:22 PM
 * Author : Chirantha
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL		// define 16Mhz clock, if not already defined
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

uint8_t initial;
uint8_t sample = 150;
uint8_t mode = 0;

void pwm_generate(uint8_t);

//Saw-tooth wave
/*
int main(void) {
	pwm_generate(mode);
	while (1)
	{
		_delay_us(186);
		sample += 1;
		if (sample > 255){
			sample = 0;
		}
	}
}
*/
// Triangle waveform
int main(void) {
	pwm_generate(mode);
	uint8_t step = 25;
	while (1)
	{
		_delay_us(125);
		sample += step;
		if (sample == 250){
			step = -25;
		}
		else if (sample == 50){
			step = 25;
		}
	}
}

void pwm_generate(uint8_t mode) {
	DDRB  |= (1 << PORTB1);           // set PB1 as output

	TCCR1A = 0b10000001;              // set Fast PWM(8-bit) mode, and non-inverting
	TCCR1B = 0b00001011;              // Timer Frequency = 16 MHz / 64 = 250 kHz
	TCCR1C = 0x00;

	if (mode == 0) {
		initial = 225;                // sampling rate of 8064.52 Hz (8kHz), 16000000/(32*(256-194)) = 8064.52 Hz
	}
	else if (mode == 1) {
		initial = 235;                // sampling rate of 11904.8 Hz  (12kHz)
	}
	else {
		initial = 217;                // sampling rate of 6410 Hz  (6.4KHz)
	}

	TIMSK1 = 0x01;                    // enable overflow interrupt
	OCR1AH = 0x00;					  // High register is not used in 8-bit mode

	DDRD  = 0b00100000;               // test_LED - by blinking
	PORTD = 0b00100000;

	sei();
	TCNT1H = 0;						  // High register is not used in 8-bit mode
	TCNT1L = initial;				  // set the initial value to obtain the required PWM frequency 

}

ISR(TIMER1_OVF_vect)
{
	TCNT1L = initial;
	OCR1AH = 0x00;
	OCR1AL = initial + sample / 255.0 * (255 - initial);

	PORTD ^= 0b00100000;			  // Testing led
}