ISR(INT0_vect) {
  if (!(ADCSRA & (1 << ADEN))) {
    //setup_usat_com();
    start_adc();

    if (SD.exists("test3.txt")) {
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

ISR(INT1_vect) {
  if (TIMSK1 == 0x01) {
    file.close();
    TIMSK1 = 0b00000000;

    PORTD = 0b00000000;
    DDRD = 0b00000000;
  }
  else {
    file = SD.open("TEST3.txt");
    pwm_generate(0);
  }
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
