volatile byte ADC_8_bit_out;
volatile bool ADC_flag = false;

//unsigned long time;
//unsigned long time_holder;

int get_adc(void);
void display_adc_val(int ADC_8_bit_out);

ISR(TIMER2_OVF_vect) {
  ADC_flag = true;
  TCNT2 = 0x05; //change this
}

void record_ADC() {
  ADC_8_bit_out = get_adc();

  //display_adc_val(ADC_8_bit_out);
  //Serial.println(ADC_8_bit_out);

  file.write(ADC_8_bit_out);

  //time = micros() - time_holder;
  //time_holder = micros();

  PORTD ^= 0b00100000;
}

void start_adc(void) {
  DIDR0 = 0b00001000; // Disabling digital mode in the ADC3 pin
  ADMUX = 0b01000011; // High = Vcc, Data register right aligned, ADC3 as the analog input
  ADCSRA = 0b10000011; // Enabling the ADC, ADC Clock = 16 Mhz / 8 = 2 Mhz --> Sampling frequency = 137.9 Khz

  TCCR2B = 0b00000010; // Timer Frequency = 16 MHz / 8 = 2 MHz
  TCNT2 = 0x05; //set the Timer step = 5 (Overflow interrupt frequency = 8 Khz)
  TIMSK2 |= (1 << TOIE2); //Enable the timer overflow interrupt

  DDRD |= (1 << PD5);
  PORTD |= (1 << PD5);
}

void stop_adc(void) {
  DIDR0 = 0b00000000;
  ADCSRA = 0b00000000;

  cli();

  TIMSK2 = 0b00000000;

  if(PORTD & (1 << PD5) != 0){
    PORTD ^= (1 << PD5);
  }

  DDRD ^= (1 << PD5);

  sei();
}

int get_adc(void){
  uint16_t ADC_8_bit_out;

  ADCSRA |= 1 << ADSC; //starting conversion

  while (ADCSRA & (1 << ADSC)); //waiting until the conversion is complete

  ADC_8_bit_out = ADCL; //reading the 8 bits in the ADCL register
  ADC_8_bit_out += (ADCH << 8);

  ADCSRA |= 1 << ADIF; //clearing the ADIF

  return ADC_8_bit_out * 0.25;
}

//void setup_usat_com(void) {
//  UBRR0L = 0b00011001; // Baud Rate = 38.4 kbps
//  UCSR0C = 0x06; // Data - 8 bit, Start/Stop - 1 bit, No parity bit
//  UCSR0B |= (1 << TXEN0); // Setting the microcontroller as a transmitter
//}
//
//void stop_usat_com(void) {
//  UBRR0L = 0x00;
//  UCSR0C = 0x00;
//  UCSR0B = 0x00;
//}

//void display_adc_val(int ADC_8_bit_out) {
//  uint8_t hundred_pos;
//  uint8_t ten_pos;
//  uint8_t one_pos;
//
//  one_pos = ADC_8_bit_out % 10;
//  ADC_8_bit_out = ADC_8_bit_out / 10;
//
//  ten_pos = ADC_8_bit_out % 10;
//  ADC_8_bit_out = ADC_8_bit_out / 10;
//
//  hundred_pos = ADC_8_bit_out % 10;
//
//  one_pos += 0x30;
//  ten_pos += 0x30;
//  hundred_pos += 0x30;
//
//  while (!(UCSR0A & (1 << UDRE0)));
//  UDR0 = hundred_pos;
//
//  while (!(UCSR0A & (1 << UDRE0)));
//  UDR0 = ten_pos;
//
//  while (!(UCSR0A & (1 << UDRE0)));
//  UDR0 = one_pos;
//
//  while (!(UCSR0A & (1 << UDRE0)));
//  UDR0 = '\r';
//
//  while (!(UCSR0A & (1 << UDRE0)));
//  UDR0 = '\n';
//}
