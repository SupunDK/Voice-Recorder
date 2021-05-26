void setup_recording_btn(void);

ISR(INT0_vect){
	if(ADEN == 1){
		stop_adc();
	}
	else{
		start_adc();
	}
}

void setup_recording_btn(void){
	cli();
	
	EICRA |= (1<<ISC01) | (1<<ISC00);
	EIMSK |= (1<<INT0);
	
	sei();
}