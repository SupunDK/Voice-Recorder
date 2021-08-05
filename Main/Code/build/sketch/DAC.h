//uint8_t mode = 0;
//volatile uint8_t initial;
volatile uint16_t data = 0;
uint8_t stepVal;
volatile bool DAC_flag = false; 
volatile bool pause = false;
Adafruit_MCP4725 dac;

ISR(TIMER1_COMPA_vect) {
  DAC_flag = true; 
}

void start_playback(uint8_t mode) {
  //Serial.println("In the pwm generate function");
  dac.configureSpeed(400000);

  TCCR1A = 0;             // setting CTC mode
  TCCR1B = 0b00001010;    // setting CTC mode and prescaler of 8
  TCCR1C = 0;

  TIMSK1 = 0b00000010;    // Enable Timer1 compare interrupt

  // Reset Timer1 register and set compare value in OCR1A
  TCNT1 = 0;
  OCR1A = 250;
    
  DDRD |= (1 << PD5); //test by led blinking
  PORTD |= (1 << PD5);

  //Serial.println("At the end of the pwm generate function");

  sei();
}

void sendData(){
  data = (uint16_t)file.read();

  dac.setVoltage2(data);

  time = micros() - time_holder;
  time_holder = micros();
}

void end_playback(){
  cli();

  file.close();
  TCCR1A = 0;             // setting CTC mode
  TCCR1B = 0b00000000;    // Disable CTC mode and prescaler of 8
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
