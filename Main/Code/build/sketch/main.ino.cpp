#include <Arduino.h>
#line 1 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL // Setting the CPU speed to 16 MHz
#include <util/delay.h>

//Libraries for testing
#include <SPI.h>
#include <SD.h>
#include <Adafruit_MCP4725.h>

File file;

//#include "output.h"
#include "adc.h"
#include "DAC.h"
#include "buttons.h"

const int chipSelect = 10;

#line 20 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
void setup();
#line 48 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
void loop();
#line 20 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
void setup() {
  //Setting the system clock = External Oscillator Frequency
  cli();
  CLKPR = 0x80;
  CLKPR = 0x00;
  sei();

  //Just for arduino
  DDRB |= (1 << PB0);
  PORTB |= (1 << PB0);

  //Setting up the SD card
  Serial.begin(9600);
  Serial.println("The program started");

  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed");
    return;
  }
  dac.begin(0x60);
  dac.sleep();
  
  setup_recording_btn();
  setup_play_btn();

  //playing = true;
}

void loop() {
  if (recording == 1) {
    Serial.println("Record pressed");
    Serial.println(recording);
    //start_recording();
  }

  if (playing == 1) {
    Serial.println("Play pressed");
    Serial.println(playing);
    start_playing();
  }
  // Serial.print(recording);
  // Serial.print(" ");
  // Serial.println(playing);
}

