
void openingMenu(){
  switch (openingPointer){
    case 1:
      lcd.clear();
      lcd.print(">Record");
      lcd.setCursor(0,1);
      lcd.print(" Play");
      break;
    case 2:
      lcd.clear();
      lcd.print(" Record");
      lcd.setCursor(0,1);
      lcd.print(">Play");
      break;
    }
  }

void songMenu() {
  if (songPointer <= 0){
    songPointer = 4;
    }
  if (songPointer > 4){
    songPointer = 1;
    }
  if((songPointer % 2) == 0){
    int p = songPointer;
    lcd.clear();
    lcd.print(" ");
    lcd.print(song[p-2]);
    lcd.setCursor(0,1);
    lcd.print(">");
    lcd.print(song[p-1]);
    }
  else{
    int p = songPointer;
    lcd.clear();
    lcd.print(">");
    lcd.print(song[p-1]);
    lcd.setCursor(0,1);
    lcd.print(" ");
    lcd.print(song[p]);
    }
}

void openingAction(){
  switch (openingPointer){
    case 1:/*record*/
        lcd.clear();
        lcd.print("   Recording...");
        pointerTrack = 2;
        start_recording();
      break;
    case 2:/*play*/
      pointerTrack = 4;
      songMenu();
      break;
    }
  }

void variationMenu(){
  if (variationPointer <=0){
    variationPointer = 3;
    }
  if (variationPointer > 3){
    variationPointer = 1;
    }
  if (variationPointer == 1){
    lcd.clear();
    lcd.print(">");
    lcd.print(variation[0]);
    lcd.setCursor(0,1);
    lcd.print(" ");
    lcd.print(variation[1]);
    }
  else if (variationPointer == 2){
    lcd.clear();
    lcd.print(" ");
    lcd.print(variation[0]);
    lcd.setCursor(0,1);
    lcd.print(">");
    lcd.print(variation[1]);
    }
  else if (variationPointer == 3){
    lcd.clear();
    lcd.print(">");
    lcd.print(variation[2]);
    }
  }
