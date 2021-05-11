#include <SPI.h>
#include <SD.h>
#include <TMRpcm.h>

const int cs = 10;

File file;

TMRpcm audio_file;

void setup() {
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);

  audio_file.speakerPin = 9;

  Serial.begin(9600);

  if (!SD.begin(cs)) {
    Serial.println("SD initialization failed!");
    return;
  }

  Serial.println("SD initialization successful!");

  if(SD.exists("untitled.wav")){
    Serial.println("The file exist");
  }
  else{
    Serial.println("The file doesn't exist");
  }

  Serial.println("Start Playing");

  audio_file.setVolume(10);
  audio_file.play("untitled.wav");
}

void loop() {
  // put your main code here, to run repeatedly:

}
