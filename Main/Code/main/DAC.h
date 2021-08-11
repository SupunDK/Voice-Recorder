uint8_t mode = 0;
volatile uint16_t data = 0;
uint8_t stepVal;
volatile bool DAC_flag = false; 
Adafruit_MCP4725 dac;

ISR(TIMER1_COMPA_vect) {
  DAC_flag = true; 
}

void start_playback(uint8_t mode) {
  
  dac.configureSpeed(400000); //(400kbps)

  TCCR1A = 0;             // setting CTC mode
  TCCR1B = 0b00001010;    // setting CTC mode and prescaler of 8 (set WGM12 and CS11 high)
  TCCR1C = 0;
  TIMSK1 = 0b00000010;    // Enable Timer1 compare interrupt
  
  TCNT1 = 0;              // Reset Timer1 register
  
  if (mode == 0){
    OCR1A = 250;    // Normal mode (8kHz)
  }
  else if (mode == 1){
    OCR1A = 50;    // High pitch mode (alvin 12kHz)//is 50 ok?
  }
  else if (mode == 2){
    OCR1A = 333;    // Low pitch mode (Batman 6kHz)
  }
  
  sei(); // Set the global interrupt flag in SREG
}

void sendData(){
  data = (uint16_t)file.read();  // read each 8bit sample from the .wav file
  dac.setVoltage2(data);         // send each sample to DAC 
}

void end_playback(){
  cli();  // Clear the global interrupt flag in SREG

  file.close();
  TCCR1A = 0;             // Disable CTC mode
  TCCR1B = 0b00000000;    // Disable CTC mode and the prescaler of 8
  TCCR1C = 0;
  TIMSK1 = 0b00000000;    // Disable Timer1 compare interrupt

  sei();

  //dac.setVoltage2(0);
  dac.sleep();

  if(PORTD & (1 << PD5) != 0){
    PORTD ^= (1 << PD5);
  }
  DDRD ^= (1 << PD5);
}
