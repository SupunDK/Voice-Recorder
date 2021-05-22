#ifndef __AVR_ATmega328__
#define __AVR_ATmega328__
#endif

uint8_t sample = 0;
uint8_t mode = 0;
volatile uint8_t initial;
volatile uint8_t count = 0;
volatile uint8_t data;

ISR(TIMER1_OVF_vect)
{
  TCNT1 = initial;

  count += 1;

  if (count == 1) {
    if (file.available()) {
      OCR1AH = 0x00;

      data = (int)file.read();

      OCR1AL = initial +  data / 255.0 * (255 - initial);
    }
    else {
      file.close();
      TIMSK1 = 0b00000000;
      DDRB ^= (1 << PORTB1);
      PORTD  = 0b00000000;
      DDRD   = 0b00000000;

      count = 0;
    }
  }
  else {
    OCR1AH = 0x00;
    OCR1AL = initial + data / 255.0 * (255 - initial);

    if (count == 8) {
      count = 0;
    }
  }

  PORTD ^= 0b00100000;
}

void pwm_generate(uint8_t mode) {
  DDRB |= (1 << PORTB1);             // set PB1 as output

  TCCR1A = 0b10000001;              // set Fast PWM(8-bit) mode, and non-inverting
  TCCR1B = 0b00001010;              // Timer Frequency = 16 MHz / 64 = 250 kHz
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

  TIMSK1 = 0x01;                  // enable overflow interrupt
  OCR1AH = 0x00;

  DDRD  = 0b00100000;             // test_LED - by blinking
  PORTD = 0b00100000;

  sei();
  TCNT1H = 0;
  TCNT1L = initial;
}
