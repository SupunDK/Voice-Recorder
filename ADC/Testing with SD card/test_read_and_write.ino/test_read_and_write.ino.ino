#include <SPI.h>
#include <SD.h>

#define ledpin 3

const int chipSelect = 10;
File file;

void setup() {
  pinMode(ledpin, OUTPUT);
  
  byte testingVals[8] = {85, 101, 115, 116, 105, 110, 103, 10};
  unsigned long Time[8];

  unsigned long time1;
  unsigned long time2;

  int count = 0;

  Serial.begin(9600);

  while (!Serial);

  Serial.println("Initializing the SD card");

  if (SD.begin(chipSelect) == 1) {
    Serial.println("Initialization Successful!");
  }
  else {
    Serial.println("Initialization Failed!");
    return;
  }

  if (SD.exists("test_new.txt")) {
    Serial.println(SD.remove("test_new.txt"));
  }

  file = SD.open("test_new.txt", FILE_WRITE);

  Serial.print("Value of the file object: ");
  Serial.println(file);

  if (file) {
    Serial.println("Writing to the SD card");
    digitalWrite(ledpin, HIGH);

    for (int i = 0; i < 8; i++) {
      time1 = micros();
      file.write(testingVals[i]);
      time2 = micros();

      //      if (time2 - time1 > 1000) {
      //        Time[count] = time2 - time1;
      //        count += 1;
      //        Serial.println(i);
      //      }
    }

    file.close();

    Serial.println("Writing Finished!");
  }
  else {
    Serial.println("Error opening test_new.txt");
    return;
  }

  digitalWrite(ledpin, LOW);

  file = SD.open("test_new.txt", FILE_READ);

  Serial.println("Reading the test_new.txt file");

  if (file) {

    while (file.available()) {
      Serial.write(file.read());
    }

    file.close();

    Serial.println("Reading text.txt is finished");
  }
  else {
    Serial.println("Error opening text.txt");
  }

  //  for (int i = 0; i < count; i++) {
  //    Serial.println(Time[i]);
  //  }
  //
  //  Serial.println();
  //  Serial.println(count);
}

void loop() {
  // put your main code here, to run repeatedly:

}
