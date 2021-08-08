char headerData[44] = {/*RIFF Section*/0x52,0x49,0x46,0x46,0x00,0x00,0x00,0x00,0x57,0x41,0x56,0x45,/*Format Section*/0x66,0x6D,0x74,0x20,0x10,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x40,0x1F,0x00,0x00,0x40,0x1F,0x00,0x00,0x01,0x00,0x08,0x00,/*Data Header*/0x64,0x61,0x74,0x61,0x00,0x00,0x00,0x00};
uint32_t sampleCount = 0; //variable to count the number of samples taken in a single recording
//volatile uint8_t recording = 2;
//volatile uint8_t playing = 2;
volatile bool recording = false;
volatile bool playing = false;
volatile uint8_t paused = 2;

//For lcd
int pointerTrack = 1; /* 1-record/play 2-recording 3-rec.paused 4-playlist 5-variation 6-playing 7-play.paused */
volatile bool upReg = false;
volatile bool downReg = false;
volatile bool selectReg = false;
volatile bool menuReg = false;

ISR(INT0_vect) {
//  recording = (recording + 1)%4;
//  _delay_ms(200);
//  paused = (paused + 1)%4;
  
  selectReg = true; 
  recording =true; /*true when pointerTrack=1*/
  playing =true; /*true when pointerTrack=5*/
}

//ISR(INT1_vect) {
//  playing = (playing + 1)%4;
//  _delay_ms(200);
//}

void setup_recording_btn(void) {
  cli();

    //EICRA |= (1 << ISC00); //interrupt call on logic change
    //EIMSK |= (1 << INT0);

  //old (worked for this)(rising/falling edge)
  EICRA |= (1 << ISC01) | (1 << ISC00);           
  EIMSK |= (1 << INT0);

  sei();

  //DDRD |= (1 << PD5);

  //Serial.println("Inside the setup_recording_btn function");
}

void setup_play_btn(void) {//not needed?
  cli();

  EICRA |= (1 << ISC10); //interrupt call on logic change
  EIMSK |= (1 << INT1);

  sei();

  //Serial.println("Inside the setup_play_btn function");
}

void start_recording() {
  cli();

  //Serial.println("Started Recording");

  if (SD.exists("TEST3.wav")) {
    SD.remove("TEST3.wav");
  }

  file = SD.open("TEST3.wav", FILE_WRITE);

  //Writing the header data of the .wav format to the file
  for(uint8_t i=0; i<44; i++){
    file.write(headerData[i]);
  }

  paused = 3;

  start_adc();

  sei();

  //time_holder = micros();

  while (recording) {
    while(paused == 1);

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
  file = SD.open("TEST3.wav",O_RDWR);
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

  file = SD.open("TEST3.wav");
  Serial.println("File Opened");
  file.seek(45); //skipping through the wav file header
  start_playback(0);

  //Serial.println(playing);

  paused = 3;

  sei();

  //time_holder = micros();

  while (playing) {
    if (paused == 1){
      dac.sleep();
    }

    while(paused == 1);

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
