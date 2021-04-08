#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

int upButton = 3;
int downButton = 1;
int selectButton = 2;
int menu = 1;

void setup() {
  lcd.begin();
  lcd.backlight();
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  lcd.setCursor(1,0);
  lcd.print("Voice Recorder");
  delay(3000);
  updateMenu();
}

void loop() {
  if (!digitalRead(downButton)){
    menu++;
    updateMenu();
    delay(100);
    while (!digitalRead(downButton));
  }
  if (!digitalRead(upButton)){
    menu--;
    updateMenu();
    delay(100);
    while(!digitalRead(upButton));
  }
  if (!digitalRead(selectButton)){
    executeAction();
    updateMenu();
    delay(100);
    while (!digitalRead(selectButton));
  }
}

void updateMenu() {
  switch (menu) {
    case 0:
      menu = 4;
      break;
    case 1:
      lcd.clear();
      lcd.print(">Song1");
      lcd.setCursor(0, 1);
      lcd.print(" Song2");
      break;
    case 2:
      lcd.clear();
      lcd.print(" Song1");
      lcd.setCursor(0, 1);
      lcd.print(">Song2");
      break;
    case 3:
      lcd.clear();
      lcd.print(">Song3");
      lcd.setCursor(0, 1);
      lcd.print(" Song4");
      break;
    case 4:
      lcd.clear();
      lcd.print(" Song3");
      lcd.setCursor(0, 1);
      lcd.print(">Song4");
      break;
    case 5:
      menu = 1;
      break;
  }
}

void executeAction() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
    case 4:
      action4();
      break;
  }
}

void action1() {
  lcd.clear();
  lcd.print(">Playing Song1");
  delay(1500);
}
void action2() {
  lcd.clear();
  lcd.print(">Playing Song2");
  delay(1500);
}
void action3() {
  lcd.clear();
  lcd.print(">Playing Song3");
  delay(1500);
}
void action4() {
  lcd.clear();
  lcd.print(">Playing Song4");
  delay(1500);
}
