#include <SPI.h>
#include <SD.h>
#define SD_ChipSelectPin 10 

File sFile;
char filename[] = "untitled.wav";

const byte soundPin = 3; // OC2B
int dataCount = 0;
unsigned int numBytes;

void setup() {
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  Serial.begin(9600);
  Serial.println("Starting simple WAV demo\n");
  
  pinMode(soundPin, OUTPUT);

  
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");  
    return;
  }
  sFile = SD.open(filename);
  if( !sFile ){ 
    Serial.println("File not opened"); 
  }
  else {
      // first show the data at the start of the WAV file
    Serial.println("RIFF section");
    for (byte i = 0; i < 12; i++){
      Serial.print(sFile.read(), HEX);
      Serial.print(' ');
    }
    Serial.println();
    Serial.println();
    
    Serial.println("Format section");
    for (byte i = 12; i < 36; i++){
      Serial.print(sFile.read(), HEX);
      Serial.print(' ');
    }
    Serial.println();
    Serial.println();
    
    Serial.println("Data Header");
    for (byte i = 36; i < 44; i++){
      Serial.print(sFile.read(), HEX);
      Serial.print(' ');
    }
    Serial.println();
    Serial.println();
    
    Serial.println("First 32 data bytes");
    for (int i = 0; i < 32; i++){
      Serial.print("0x");
      Serial.print(sFile.read(), HEX);
      Serial.print(',');
    }
    Serial.println();
    Serial.println();
    
      // Now prepare to play the sound

      // move the pointer back to the start of the data size
    sFile.seek(40);
      // this assumes the data size fits in 2 bytes. There are 4 bytes to read if necessary
    byte firstB = sFile.read();
    byte nextB = sFile.read();
    numBytes = firstB + (nextB << 8);
    Serial.print("Num Bytes ");
    Serial.print(numBytes);
    Serial.println();
    
      // move the pointer back to the start of the data
    sFile.seek(44); 
    
      // set up Timer2 to run at 11025 Hz (or near it)
    TCCR2A = 0b00100011; // fast PWM mode with OC2B changed
    TCCR2B = 0b00000010; // last 3 bits 010 select clock/8 or 16MHz/8 = 2MHz
    OCR2A = 179; // should give 11025 Hz, might need tweaking
    OCR2B = 80;
      // set the interrupt last thing so other stuff is not affected
    TIMSK2 = 0b00000001; // Overflow interrupt enabled
  }

}

void loop() {
}

ISR (TIMER2_OVF_vect) {
  OCR2B = sFile.read(); // this represents the amplitude of each sample
  dataCount ++;
  if (dataCount >= numBytes) { // go back to the start of the file
    dataCount = 0;
    sFile.seek(44);
  }
}
