#include <SPI.h>
#include <SD.h>

char SampleBitArray[5] ={150,34,100,200,50};

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
    File dataFile = SD.open("Wav.txt",FILE_WRITE);
    if (dataFile)
    {  
      while(RecButton)
      {
        for (int i=0;i<5;i++)//This for loop should be change to bit stream
        {
        dataFile.print(SampleBitArray[i]);
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
  File RecFile = SD.open("Wav.txt");
  if (RecFile) {
    Serial.println("Wav.txt");


    while (RecFile.available()) {
      int Val = int(RecFile.read());
      Serial.println(Val);
    }

    RecFile.close();
  } else {

    Serial.println("error opening Text.txt");
  } 
}
