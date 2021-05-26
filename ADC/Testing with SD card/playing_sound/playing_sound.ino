#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>

#include <SPI.h>
#include <SD.h>

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

  if(SD.exists("voice2.wav")){
    Serial.println("The file exist");
  }
  else{
    Serial.println("The file doesn't exist");

    return;
  }

  Serial.println("Start Playing");

  audio_file.setVolume(10);
  audio_file.play("voice2.wav");
}

void loop() {
  // put your main code here, to run repeatedly:
}
