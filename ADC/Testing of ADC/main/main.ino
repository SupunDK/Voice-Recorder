#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000 // Setting the CPU speed to 16 MHz
#include <util/delay.h>

//Libraries for testing
#include <SPI.h>
#include <SD.h>

File file;

#include "adc.h"
#include "buttons.h"

const int chipSelect = 10;

void setup() {
  //Setting up the SD card
  
  if (!SD.begin(chipSelect)) {
    return;
  }

  setup_recording_btn();
}

void loop() {

}
