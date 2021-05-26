#include <SPI.h>
#include <SD.h>

String SampleBitArray[4] ={"10101101","00011001","10110111","11100110"};

int RecButtonPin = 2;
bool RecButton = false;

int SDReadBtn =3;

const int CSpin = 10;

void setup() {
 Serial.begin(9600);
 pinMode(RecButtonPin, INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(RecButtonPin), changeStatus, FALLING);
 pinMode(SDReadBtn, INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(SDReadBtn), ReadSD,FALLING); 
 Serial.println("Initializing SD...");

 if(!SD.begin(CSpin))
 {
  Serial.println("Card not found.!");
  while(true);
 }
 Serial.println("Card initialized.");
}

void loop() {
  if (RecButton)
  {
    String BitStream = "";
    File dataFile = SD.open("Text.txt",FILE_WRITE);
    if (dataFile)
    {  
      while(RecButton)
      {
        for (int i=0;i<4;i++)//This for loop should be change to bit stream
        {
        dataFile.println(SampleBitArray[i]);
        Serial.println(SampleBitArray[i]);
        
        }              
      }
     dataFile.close();  
    }
    else
    {
    Serial.println("error opening file");  
    }
  }
}

void changeStatus()
{
  RecButton = !RecButton;
  if (RecButton){
    Serial.println("Start Recording");
  }
  else{
    Serial.println("Recording Stopped");
  }
}

void ReadSD()
{
  File RecFile = SD.open("Text.txt");
  if (RecFile) {
    Serial.println("Text.txt");


    while (RecFile.available()) {
      Serial.write(RecFile.read());
    }

    RecFile.close();
  } else {

    Serial.println("error opening Text.txt");
  } 
}
