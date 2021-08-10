
char headerData[44] = {/*RIFF Section*/0x52,0x49,0x46,0x46,0x00,0x00,0x00,0x00,0x57,0x41,0x56,0x45,/*Format Section*/0x66,0x6D,0x74,0x20,0x10,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x40,0x1F,0x00,0x00,0x40,0x1F,0x00,0x00,0x01,0x00,0x08,0x00,/*Data Header*/0x64,0x61,0x74,0x61,0x00,0x00,0x00,0x00};
uint32_t sampleCount = 0; //variable to count the number of samples taken in a single recording
volatile bool recording = false;
volatile bool playing = false;
volatile bool paused = false;

ISR(INT0_vect) {
  paused = !(paused);
  selectReg = true; 
  recording =true; /*true when pointerTrack=1*/
  playing =true; /*true when pointerTrack=5*/
}


void setup_recording_btn(void) {
  cli();

  //falling edge
  EICRA |= (1 << ISC01); //| (1 << ISC00);           
  EIMSK |= (1 << INT0);

  sei();

  //DDRD |= (1 << PD5);

  //Serial.println("Inside the setup_recording_btn function");
}


void start_recording() {
  cli();

  //Serial.println("Started Recording");

  //Create filename from EEPROM
  String fileName = "TEST";
  fileName += counter;
  //Saving atmost 3 recordings
    int rem = counter%3;
    song[rem] = fileName;
  counter++;
  EEPROM.write(0, counter);
  fileName += ".wav";

  if (SD.exists(fileName)) {
    SD.remove(fileName);
  }

  file = SD.open(fileName, FILE_WRITE);

  //Writing the header data of the .wav format to the file
  for(uint8_t i=0; i<44; i++){
    file.write(headerData[i]);
  }

  paused = false;
  bool pre_paused = false;

  start_adc();

  sei();

  //time_holder = micros();

  while (recording){

  while(paused){
      if (!pre_paused){
      lcd.clear();
      lcd.print("   Recording");
      lcd.setCursor(0,1);
      lcd.print("   Paused...");
      }
      pre_paused = true;
      }
      
    if (!recording){
      break;
      }
      
    if (pre_paused){//if (pre_paused != false)
      lcd.clear();
      lcd.print("Recording...");
      pre_paused = false;
      } 

    if (ADC_flag) {
      record_ADC();
      ADC_flag = false;
      sampleCount++;
    }
  }

  //Serial.println(time);

  if (playing) {
    playing = false;
  }

  cli();

  file.close();
  stop_adc();

  sei();

  //Writing the size of the file into the header
  file = SD.open(fileName,O_RDWR);
  file.seek(40);

  for(uint8_t i=0; i<4; i++){
    file.write( ( sampleCount>>(8*i) ) & 0xFF);
  }

  file.seek(4);

  for(uint8_t i=0; i<4; i++){
    file.write( ( (sampleCount+44) >>(8*i) ) & 0xFF);
  }


  file.close();		
  sampleCount=0;
}

void start_playing() {
  cli();

  Serial.println("Started Playing");

  String playFile = song[songPointer - 1];
  playFile += ".wav";

  file = SD.open(playFile);
  Serial.println("File Opened");
  file.seek(45); //skipping through the wav file header
  start_playback(variationPointer - 1);

  //Serial.println(playing);

  paused = false;
  bool pre_paused = false;

  sei();

  //time_holder = micros();

  while (playing) {

    while(paused){
      if (!pre_paused){
        dac.sleep();
        lcd.clear();//without this it is working for playing but not for recording(may be playback length)
        lcd.print("   Playback");
        lcd.setCursor(0,1);
        lcd.print("   Paused...");
        }
      pre_paused = true;
      }
      
    if (!playing){
      break;
      }

    if (pre_paused){
      lcd.clear();
      lcd.print("Playing!!...");
      pre_paused = false;
      }

    if(DAC_flag){
      if(file.available()){
        sendData();
      }
      else{
        DAC_flag = false;
        playing = false;//check
        break;
      }

      PORTD ^= (1 << 5);
      DAC_flag = false;
    }
  }

  //Serial.println(time);

  if (recording) {
    recording = false;
  }

  end_playback();

/*   PORTD = 0b00000000;
  DDRD = 0b00000000; */
}
