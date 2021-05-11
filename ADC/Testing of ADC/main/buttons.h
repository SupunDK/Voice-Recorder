ISR(INT0_vect) {
  if (!(ADCSRA & (1 << ADEN))) {
    //setup_usat_com();
    start_adc();

    if(SD.exists("test3.txt")){
      SD.remove("test3.txt");
    }
    
    file = SD.open("test3.txt", FILE_WRITE);
  }
  else {
    stop_adc();
//  stop_usat_com();

    file.close();
  }
}

void setup_recording_btn(void) {
  cli();

  EICRA |= (1 << ISC01) | (1 << ISC00);
  EIMSK |= (1 << INT0);

  sei();
}
