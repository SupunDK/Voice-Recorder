#include <Arduino.h>
#line 1 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000 // Setting the CPU speed to 16 MHz
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
#line 35 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
void loop();
#line 20 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
void setup() {
  //Setting up the SD card
  Serial.begin(9600);
  Serial.println("The program started");

  if (!SD.begin(chipSelect)) {
    return;
  }
  dac.begin(0x60);
  dac.sleep();
  
  setup_recording_btn();
  setup_play_btn();
}

void loop() {
  if (recording) {
    start_recording();
  }

  if (playing) {
    start_playing();
  }
}

