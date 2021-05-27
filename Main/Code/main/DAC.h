//uint8_t mode = 0;
//volatile uint8_t initial;
volatile uint16_t data = 0;
uint8_t stepVal;
volatile bool DAC_flag = false; 
Adafruit_MCP4725 dac;

ISR(TIMER1_COMPA_vect) {
  DAC_flag = true; 
}

void pwm_generate(uint8_t mode) {
  //Serial.println("In the pwm generate function");
  dac.configureSpeed(400000);

  TCCR1A = 0;             // setting CTC mode
  TCCR1B = 0b00001010;    // setting CTC mode and prescaler of 8
  TCCR1C = 0;

  TIMSK1 = 0b00000010;    // Enable Timer1 compare interrupt

  // Reset Timer1 register and set compare value in OCR1A
  TCNT1 = 0;
  OCR1A = 125;
    
  DDRD  = 0b00100000;             // test_LED - by blinking
  PORTD = 0b00100000;

  //Serial.println("At the end of the pwm generate function");

  sei();
}

void sendData(){
  data = (uint16_t)file.read();
  //Serial.println(data);

  data = 15*data + 100;

  //Serial.println(data);

  dac.setVoltage2(data);
}

void end_playback(){
  file.close();
  TCCR1A = 0;             // setting CTC mode
  TCCR1B = 0b00000000;    // Disable CTC mode and prescaler of 8
  TCCR1C = 0;
  TIMSK1 = 0b00000000;    // Disable Timer1 compare interrupt

  PORTD = 0b00000000;
  DDRD = 0b00000000;
}
