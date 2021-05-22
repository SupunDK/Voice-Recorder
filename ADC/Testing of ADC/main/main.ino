#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000 // Setting the CPU speed to 16 MHz
#include <util/delay.h>

//Libraries for testing
#include <SPI.h>
#include <SD.h>

File file;

#include "output.h"
#include "adc.h"
#include "buttons.h"

const int chipSelect = 10;

void setup() {
  //Setting up the SD card
  Serial.begin(9600);
  Serial.println("The program started");

  if (!SD.begin(chipSelect)) {
    return;
  }

  setup_recording_btn();
  setup_play_btn();
}

void loop() {
  if (record) {
    cli();

    start_adc();

    if (SD.exists("test3.txt")) {
      SD.remove("test3.txt");
    }

    file = SD.open("test3.txt", FILE_WRITE);

    sei();

    while (record);

    cli();

    stop_adc();
    file.close();

    sei();
  }

  if (playing) {
    cli();

    file = SD.open("TEST3.txt");
    pwm_generate(0);

    sei();

    while (playing);

    cli();

    file.close();
    TIMSK1 = 0b00000000;
    DDRB ^= (1 << PORTB1);
    PORTD = 0b00000000;
    DDRD = 0b00000000;

    sei();
  }
}
