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

  start_adc();

  if (SD.exists("test3.txt")) {
    SD.remove("test3.txt");
  }

  file = SD.open("test3.txt", FILE_WRITE);

  sei();

  while (recording) {
    if (ADC_flag) {
      record_ADC();
      ADC_flag = false;
    }

    if (playing) {
      playing = false;
    }
  }

  cli();

  stop_adc();
  file.close();

  sei();
}

void start_playing() {
  cli();

  file = SD.open("TEST3.txt");
  pwm_generate(0);

  sei();

  while (playing) {
    if (recording) {
      recording = false;
    }
  }

  cli();

  file.close();
  TIMSK1 = 0b00000000;
  DDRB ^= (1 << PORTB1);
  PORTD = 0b00000000;
  DDRD = 0b00000000;

  sei();
}
