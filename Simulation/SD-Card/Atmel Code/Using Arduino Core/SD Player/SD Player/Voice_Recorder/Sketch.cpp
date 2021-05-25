
#include <SPI.h>
#include <SD.h>

bool PlayFlag = 0; //to save status of recorder,playing or recording
bool RecFlag  = 0;
uint8_t PLAYBtn  = 5; //Pins for Recording and Playing the voice Samples
uint8_t RECBtn = 6;
uint8_t STOPBtn = 2;



const byte Speaker = 3; // OC2B
int dataCount = 0;
unsigned int numBytes;

File PlayFile;
File RecFile;
File temp;
char playfilename[] = "voice1.wav";
char recfilename[] = "Record2.wav";
char tempFile[] = "temp.txt";
char sampleData[40] = {/*RIFF Section*/0x52,0x49,0x46,0x46,0xA4,0x7F,0x00,0x00,0x57,0x41,0x56,0x45,/*Format Section*/0x66,0x6D,0x74,0x20,0x10,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x11,0x2B,0x00,0x00,0x11,0x2B,0x00,0x00,0x01,0x00,0x08,0x00,/*Data Header*/0x64,0x61,0x74,0x61};

void UART_Init(unsigned int ubrr);
void UART_putc(unsigned char data);
void UART_puts(char* s);
void Port_Init();
void playAudio(String file);
void RecordAudio(String file);
void saveFile(String filename);
ISR(TIMER2_OVF_vect );


void setup() {
  UART_Init(9600);//Initializing Serial
  UART_puts("Starting simple WAV demo\n");
  Port_Init();//Initializing Ports
  
  if (!SD.begin(10)) {
    UART_puts("SD fail\n");  
    return;
  }


}
void loop(){
	if(digitalRead(PLAYBtn)==LOW){//Check whether Playing button is pressed.
		playAudio(playfilename);
		_delay_ms(500);	
	}
	if(digitalRead(RECBtn)==LOW){//Check whether Recording button is pressed.
		RecordAudio(recfilename);
		_delay_ms(500);
	}
	
	
}





void Port_Init(){	
	DDRD = 0b10011011;//Setting Speaker as Output and PlayBtn as Input
	PORTD |= (1<<PLAYBtn)|(1<<RECBtn)|(1<<STOPBtn);//Adding Input pull up to that buttons
	
 	EIMSK = (1<< INT0);//(1<<INT1);//Adding External interrupts
 	EICRA =  (1<<ISC00) |(1<<ISC01);//(1<<ISC10)|(1<<ISC11);  //Interrupt occur at rising edge
	 
	// set up Timer2 to run at 11025 Hz (or near it)
    TCCR2A = 0b00100011; // fast PWM mode with OC2B changed
    TCCR2B = 0b00000010; // last 3 bits 010 select clock/8 or 16MHz/8 = 2MHz
    OCR2A = 179; // should give 11025 Hz, might need tweaking
    OCR2B = 80;
      // set the interrupt last thing so other stuff is not affected
}

ISR(INT0_vect){
	if(PlayFlag==1)
	{
		playAudio(playfilename);
	}
	if(RecFlag==1)
	{
		RecordAudio(recfilename);
	}
	
}


ISR (TIMER2_OVF_vect) {
	if(PlayFlag==1)
	{	
	OCR2B = PlayFile.read(); // this represents the amplitude of each sample
	dataCount ++;
		if (dataCount >= numBytes) { // go back to the start of the file
			dataCount = 0;
			PlayFile.seek(44);
		}
	}
	
	if(RecFlag==1)
	{
		//Serial.write(0x24);
		temp.write(0x24);
		dataCount++;	

	}
}



void playAudio(String file){
	if (PlayFlag==0){
		PlayFlag=1;
		PlayFile = SD.open(file,FILE_READ);
		if( !PlayFile ){
			UART_puts("File not opened\n");
		}
		else {
			byte numByteArray[4];
			PlayFile.seek(40);
			for(uint8_t b=0; b<4;b++)
			{
			numByteArray[b] = PlayFile.read();
			}
			numBytes = numByteArray[0] + (numByteArray[1] << 8) + (numByteArray[2] << 16) + (numByteArray[3] << 24);
			Serial.print("Num Bytes:");
			Serial.print(numBytes);
			Serial.println();
			
			// move the pointer back to the start of the data
			PlayFile.seek(44);
			TIMSK2 = 0b00000001;//Start playing Wav file
		}		
		
	}
	else{
		TIMSK2 = 0b00000000;//stop playing Wav file
		PlayFile.close();
		PlayFlag=0;
	}	
}

void RecordAudio(String file)
{
	if (RecFlag==0){
		RecFlag=1;
		temp = SD.open(tempFile,FILE_WRITE);
		if( !temp ){
			UART_puts("File not opened\n");
		}
		else 
		{
		UART_puts("Rec Started\n");
		TIMSK2 = 0b00000001;//Start Recording Wav file
		}
	}
	else{
		UART_puts("Wait for saving the file!\n");
		TIMSK2 = 0b00000000;//stop Recording Wav file
		//Serial.println(dataCount);
		temp.close();
		saveFile(file);
		dataCount=0;		
		RecFlag=0;
	}
}

void saveFile(String filename){
	unsigned int i;
	temp = SD.open(tempFile,FILE_READ);
	RecFile = SD.open(filename,FILE_WRITE);
	if (!temp || !RecFile)
	{
		UART_puts("Error Saving File!\n");
	}
	else
	{
		UART_puts("Saving Started...\n");
		for(i=0;i<40;i++)
		{
			RecFile.write(sampleData[i]);
			//Serial.write(sampleData[i]);
		}
		for(i=0;i<4;i++)
		{
			//Serial.println();
			//Serial.println(dataCount>>(8*i)&0xFF,HEX);			
			RecFile.write(dataCount>>(8*i)&0xFF);
		}
		char a;
		for(i=0;i<dataCount;i++)
		{
			a = temp.read();
			RecFile.write(a);
		}
		temp.close();
		RecFile.close();
		SD.remove(tempFile);
		UART_puts("Done Saving...\n");
	}

}