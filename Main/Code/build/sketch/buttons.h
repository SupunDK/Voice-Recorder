char headerData[44] = {/*RIFF Section*/0x52,0x49,0x46,0x46,0x00,0x00,0x00,0x00,0x57,0x41,0x56,0x45,/*Format Section*/0x66,0x6D,0x74,0x20,0x10,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x40,0x1F,0x00,0x00,0x40,0x1F,0x00,0x00,0x01,0x00,0x08,0x00,/*Data Header*/0x64,0x61,0x74,0x61,0x00,0x00,0x00,0x00};
uint32_t sampleCount = 0; //variable to count the number of samples taken in a single recording
volatile bool recording = false;
volatile bool playing = false;

ISR(INT0_vect) {
  recording = !recording;
}

ISR(INT1_vect) {
  playing = !playing;
}

void setup_recording_btn(void) {
  cli();

  EICRA |= (1 << ISC01) | (1 << ISC00);
  EIMSK |= (1 << INT0);

  sei();

  DDRD = 0b00100000;
  PORTD = 0b00000000;
}

void setup_play_btn(void) {
  cli();

  EICRA |= (1 << ISC11) | (1 << ISC10);
  EIMSK |= (1 << INT1);

  sei();
}

void start_recording() {
  cli();

  if (SD.exists("TEST3.wav")) {
    SD.remove("TEST3.wav");
  }

  file = SD.open("TEST3.wav", FILE_WRITE);

  //Writing the header data of the .wav format to the file
  for(uint8_t i=0; i<44; i++){
    file.write(headerData[i]);
  }

  start_adc();

  sei();

  while (recording) {
    if (ADC_flag) {
      record_ADC();
      ADC_flag = false;
      sampleCount++;
    }

    if (playing) {
      playing = false;
    }
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

  file = SD.open("TEST3.wav");
  file.seek(45); //skipping through the wav file header
  start_playback(0);

  sei();

  while (playing) {
    if(DAC_flag){
      if(file.available()){
        sendData();
      }
      else{
        end_playback();
      }

      PORTD ^= (1 << 5);
      DAC_flag = false;
    }

    if (recording) {
      recording = false;
    }
  }

  cli();

  end_playback();

/*   PORTD = 0b00000000;
  DDRD = 0b00000000; */

  sei();
}