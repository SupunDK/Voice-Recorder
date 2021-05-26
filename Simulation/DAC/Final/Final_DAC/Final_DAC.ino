#include <SPI.h>
#include <SD.h>

int SDReadBtn =3;
const int CSpin = 10;

//////////////////
int DAC_Out = 5;
/////////////////

void setup() {
 Serial.begin(9600);

 pinMode(SDReadBtn, INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(SDReadBtn), ReadSD,FALLING); 
 Serial.println("Initializing SD...");
 pinMode(DAC_Out,OUTPUT);
 if(!SD.begin(CSpin))
 {
  Serial.println("Card not found.!");
  while(true);
 }
 Serial.println("Card initialized.");
}

void loop() {

}

void ReadSD()
{
  File RecFile = SD.open("Wav.txt");
  if (RecFile) {
    Serial.println("Reading Wav.txt");

////////////////////////////////////////////////
    while (RecFile.available())
    {
      String Bits[8] = {"","","","","","","",""};
      for(int i=0;i<8;i++){
         Bits[i]= char(RecFile.read());  
      }
    float Val = 0;
    for(int j=0;j<8;j++)
    {
      if(Bits[j]=="1")
      {
        Val+=pow(2,7-j);
       }
    }
    Serial.println(int(Val));
    analogWrite(DAC_Out,Val);
    delayMicroseconds(125);  //playback at 8kHz
    }
/////////////////////////////////////////////////
    RecFile.close();
  
  }
  else {

    Serial.println("error opening file");
  } 
}
