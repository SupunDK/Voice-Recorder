#include <Arduino.h>
#line 1 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
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

#line 22 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
void setup();
#line 35 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
void loop();
#line 22 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
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

}

