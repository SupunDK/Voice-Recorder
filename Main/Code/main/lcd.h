#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2);
//int pointerTrack = 1; /* 1-record/play 2-recording 3-rec.paused 4-playlist 5-variation 6-playing 7-play.paused */ defined in button.h

int songPointer = 1;
int openingPointer = 1;
int variationPointer = 1;

char* song[] = {"Test0", "Test1", "Test2", "Test3"};
char* variation[] = {"Normal Voice", "Fast Mode", "Slow Mode", "Alvin Voice", "Batman Voice"};

int down = 0x80;
int up = 0x40;
int select = 0x04;
int menu = 0x10;


void openingMenu(){
  switch (openingPointer){
    case 1:
    lcd.clear();
    lcd.print(">Record");
    //lcd_cmd(0xc0);      /*Move cursor to the beginning of second line*/
    lcd.setCursor(0,1);
    lcd.print(" Play");
    break;
    case 2:
    lcd.clear();
    lcd.print(" Record");
    //lcd_cmd(0xc0);      /*Move cursor to the beginning of second line*/
    lcd.setCursor(0,1);
    lcd.print(">Play");
    break;
    }
  }

void songMenu() {
  if((songPointer % 2) == 0){
    int p = songPointer;
    lcd.clear();
    lcd.print(" ");
    lcd.print(song[p-2]);
    //lcd_cmd(0xc0);      /*Move cursor to the beginning of second line*/
    lcd.setCursor(0,1);
    lcd.print(">");
    lcd.print(song[p-1]);
    }
  else{
    int p = songPointer;
    lcd.clear();
    lcd.print(">");
    lcd.print(song[p-1]);
    //lcd_cmd(0xc0);      /*Move cursor to the beginning of second line*/
    lcd.setCursor(0,1);
    lcd.print(" ");
    lcd.print(song[p]);
    }
}

void openingAction(){
  switch (openingPointer){
    case 1:/*record*/
        lcd.clear();
        lcd.print("Recording...");
        pointerTrack = 2;
        start_recording();
      break;
    case 2:/*play*/
      pointerTrack = 4;
      songMenu();
      break;
    }
  }

void songAction() {
  lcd.clear();
  lcd.print("Playing ");
  lcd.print(song[songPointer-1]);
  _delay_ms(1000);
}

void variationMenu(){
  if((variationPointer % 2) == 0){
    int p = variationPointer;
    lcd.clear();
    lcd.print(" ");
    lcd.print(variation[p-2]);
    //lcd_cmd(0xc0);      /*Move cursor to the beginning of second line*/
    lcd.setCursor(0,1);
    lcd.print(">");
    lcd.print(variation[p-1]);
    }
  else{
    int p = variationPointer;
    lcd.clear();
    lcd.print(">");
    lcd.print(variation[p-1]);
    //lcd_cmd(0xc0);      /*Move cursor to the beginning of second line*/
    lcd.setCursor(0,1);
    lcd.print(" ");
    lcd.print(variation[p]);
    }
  }
