volatile bool record = false;
volatile bool playing = false;

ISR(INT0_vect) {
  record = !record;
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
