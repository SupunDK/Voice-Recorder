# 1 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
# 2 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2
# 3 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2

# 5 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2


# 6 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
//Libraries for testing
# 8 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2
# 9 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2
# 10 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2

File file;

# 14 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2
# 15 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2
# 16 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2
# 17 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2

const int chipSelect = 10;


# 20 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
extern "C" void __vector_5 /* Pin Change Interrupt Request 1 */ (void) __attribute__ ((signal,used, externally_visible)) ; void __vector_5 /* Pin Change Interrupt Request 1 */ (void)
# 20 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
               {
  if ((
# 21 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
      (*(volatile uint8_t *)((0x09) + 0x20)) 
# 21 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
           & up)==0x00){
    upReg = true;
    }
  if ((
# 24 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
      (*(volatile uint8_t *)((0x09) + 0x20)) 
# 24 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
           & down)==0x00){
    downReg = true;
    }
  if ((
# 27 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
      (*(volatile uint8_t *)((0x09) + 0x20)) 
# 27 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
           & menu)==0x00){
    menuReg = true;
    recording =false; /*false when pointerTrack=2/3*/
    playing =false; /*false when pointerTrack=6/7*/
    //selectReg=false;
    }
  }

void setup() {
  //Setting the system clock = External Oscillator Frequency
  
# 37 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 __asm__ __volatile__ ("cli" ::: "memory")
# 37 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
      ;
  
# 38 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 (*(volatile uint8_t *)(0x61)) 
# 38 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
       = 0x80;
  
# 39 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 (*(volatile uint8_t *)(0x61)) 
# 39 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
       = 0x00;
  
# 40 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 __asm__ __volatile__ ("sei" ::: "memory")
# 40 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
      ;

  //Just for arduino
  
# 43 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 (*(volatile uint8_t *)((0x04) + 0x20)) 
# 43 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
      |= (1 << 
# 43 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
               0
# 43 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
                  );
  
# 44 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 (*(volatile uint8_t *)((0x05) + 0x20)) 
# 44 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
       |= (1 << 
# 44 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
                0
# 44 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
                   );

  //Setting up the SD card
  Serial.begin(9600);
  Serial.println("The program started");

  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed");
    return;
  }
  dac.begin(0x60);
  dac.sleep();

  //setup_recording_btn();
  //setup_play_btn();

  //Setting up the lcd
  lcd.init();
  lcd.backlight();
  lcd.print("Voice Recorder");
  Serial.println("Printed the message on the LCD screen");

  
# 66 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 (*(volatile uint8_t *)((0x0A) + 0x20)) 
# 66 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
      &= ~(1<<4);/*Menu button*/
  
# 67 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 (*(volatile uint8_t *)((0x0A) + 0x20)) 
# 67 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
      &= ~(1<<6);/*up button*/
  
# 68 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 (*(volatile uint8_t *)((0x0A) + 0x20)) 
# 68 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
      &= ~(1<<7);/*down button*/

  
# 70 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 (*(volatile uint8_t *)((0x0B) + 0x20)) 
# 70 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
       |= (1<<4) | (1<<6) | (1<<7);
  _delay_ms(1000);
  openingMenu();

  
# 74 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 (*(volatile uint8_t *)(0x68)) 
# 74 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
       |= (1<<
# 74 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
              2
# 74 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
                   );
  
# 75 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 (*(volatile uint8_t *)(0x6D)) 
# 75 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
        |= (1<<
# 75 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
               4
# 75 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
                      ) | (1<<
# 75 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
                              6
# 75 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
                                     ) | (1<<
# 75 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
                                             7
# 75 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
                                                    );

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
        lcd.clear();
        lcd.print("   Recording");
        lcd.setCursor(0,1);
        lcd.print("   Paused...");
        pointerTrack = 3;
        break;
      case 3:
        lcd.clear();
        lcd.print("   Recording");
        pointerTrack = 2;
        break;
      case 4:
        pointerTrack = 5;
        variationMenu();
        break;
      case 5:
        pointerTrack = 6;
        lcd.clear();
        lcd.print("Playing...");
        playing = true;
        start_playing();
        break;
      case 6:
        lcd.clear();
        lcd.print("   Playback");
        lcd.setCursor(0,1);
        lcd.print("   Paused...");
        pointerTrack = 7;
        break;
      case 7:
        lcd.clear();
        lcd.print("   Playing...");
        pointerTrack = 6;
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
    lcd.clear();
    lcd.print("hi");
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
