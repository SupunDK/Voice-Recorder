#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL // Setting the CPU speed to 16 MHz
#include <util/delay.h>

int counter; //for EEPROM

int songPointer = 1;
int openingPointer = 1;
int variationPointer = 1;
int currentSongPointer = songPointer - 1;//new for song select

String song[] = {"Test0", "Test1", "Test2"};//seems like have to comment this after first run
char* variation[] = {"Normal Voice", "Alvin Voice", "Batman Voice"};
//int modes[] = {0, 1, 2};//new for variation select(mode = modes[currentVarPointer])

int down = 0x80;//Buttons
int up = 0x40;
int select = 0x04;
int menu = 0x10;

//Libraries for testing
#include <SPI.h>
#include <SD.h>
#include <Adafruit_MCP4725.h>
#include <EEPROM.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

File file;
LiquidCrystal_I2C lcd(0x27,16,2);

#include "adc.h"
#include "DAC.h"
#include "buttons.h"
#include "lcd.h"

const int chipSelect = 10;

ISR(PCINT2_vect){
  if ((PIND & up)==0x00){
    upReg = true;
    }
  if ((PIND & down)==0x00){
    downReg = true;
    } 
  if ((PIND & menu)==0x00){
    paused = false;// to stop while paused
    menuReg = true;
    selectReg = false; //after select btn menu btn can be pressed and both selectreg and menureg be true
    recording =false; /*false when pointerTrack=2/3*/
    playing =false; /*false when pointerTrack=6/7*/
    //selectReg=false;
    } 
  }

void setup() {
  //EEPROM  
  EEPROM.write(0,0);//upload, comment it after the first(or some amount of) recording made, re-upload
  counter = EEPROM.read(0);
  
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

  //Setting up the lcd
  lcd.init();
  lcd.backlight();
  lcd.print("Voice Recorder");

  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed");
    lcd.clear();
    lcd.print("SD Card Failed");
    return;
  }
  dac.begin(0x60);
  dac.sleep();
  
  setup_recording_btn();
  setup_play_btn();

  DDRD &= ~(1<<4);/*Menu button*/
  DDRD &= ~(1<<6);/*up button*/
  DDRD &= ~(1<<7);/*down button*/

  PORTD |= (1<<4) | (1<<6) | (1<<7);
  _delay_ms(1000);
  openingMenu();

  PCICR |= (1<<PCIE2);
  PCMSK2 |= (1<<PCINT20) | (1<<PCINT22) | (1<<PCINT23);

  //playing = true;
}

void loop() {
//  if (recording == 1) {
//    Serial.println("Record pressed");
//    Serial.println(recording);
//    start_recording();
//  }
//
//  if (playing == 1) {
//    Serial.println("Play pressed");
//    Serial.println(playing);
//    start_playing();
//  }
  // Serial.print(recording);
  // Serial.print(" ");
  // Serial.println(playing);
  
  if (selectReg){
    selectReg = false;
    switch (pointerTrack){
      case 1:
        openingAction();
        break;
      case 2:
//        lcd.clear();
//        lcd.print("   Recording");
//        lcd.setCursor(0,1);
//        lcd.print("   Paused...");
//        pointerTrack = 3;
        break;
      case 3:
//        lcd.clear();
//        lcd.print("   Recording");
//        pointerTrack = 2;
        break;
      case 4:
        pointerTrack = 5;
        variationMenu();
        break;
      case 5:
        pointerTrack = 6;
        lcd.clear();//to be commented
        lcd.print("Playing...");
        //playing = true;
        start_playing();
        if (!menuReg){
          pointerTrack = 1;
          openingMenu();
        }
        break;
      case 6:
//        lcd.clear();//to be commented
//        lcd.print("   Playback");
//        lcd.setCursor(0,1);
//        lcd.print("   Paused...");
//        pointerTrack = 7;
        break;
      case 7:
//        lcd.clear();//to be commented
//        lcd.print("   Playing...");
//        pointerTrack = 6;
        break;
      }
    }
    
  if (menuReg){
    menuReg = false;
    switch (pointerTrack){
      case 2:
        lcd.clear();
        lcd.print("   Recording");
        lcd.setCursor(0,1);
        lcd.print("   Stopped");
        pointerTrack = 1;
        _delay_ms(2000);
        openingMenu();
        break;
      case 3:
        lcd.clear();
        lcd.print("   Recording");
        lcd.setCursor(0,1);
        lcd.print("   Stopped");
        pointerTrack = 1;
        _delay_ms(2000);
        openingMenu();
        break;
      case 4:
        pointerTrack = 1;
        openingMenu();
        break;
      case 5:
        pointerTrack = 1;
        openingMenu();
        break;
      case 6:
        lcd.clear();
        lcd.print("   Playback");
        lcd.setCursor(0,1);
        lcd.print("   Stopped");
        pointerTrack = 1;
        _delay_ms(2000);
        openingMenu();
        break;
      case 7:
        lcd.clear();
        lcd.print("   Playback");
        lcd.setCursor(0,1);
        lcd.print("   Stopped");
        pointerTrack = 1;
        _delay_ms(2000);
        openingMenu();
        break;
      }
    }
    
  if (upReg){
    upReg = false;
//    lcd.clear();
//    //lcd.print("hi");
    switch (pointerTrack){
      case 1:
        --openingPointer;
        openingMenu();
        break;
      case 4:
        --songPointer;
        songMenu();
        break;
      case 5:
        --variationPointer;
        variationMenu();
        break;
      }
    }
    
  if (downReg){
    downReg = false;
    switch (pointerTrack){
      case 1:
        ++openingPointer;
        openingMenu();
        break;
      case 4:
        ++songPointer;
        songMenu();
        break;
      case 5:
        ++variationPointer;
        variationMenu();
        break;
      }
    }
}
