
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
  if (songPointer <= 0){
    songPointer = 3;
    }
  if (songPointer > 3){
    songPointer = 1;
    }
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
  if (variationPointer <=0){
    variationPointer = 3;
    }
  if (variationPointer > 3){
    variationPointer = 1;
    }
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
