#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

const uint16_t t1_load = 0;    // Timer1 initial value to load
uint16_t t1_comp;              // Compare value in OCR1A
uint8_t mode = 0;             // Set mode of operation (Set 0 - normal, 1 - fast & highPitch, 2 - slow & lowPitch)
uint8_t sample = 125;         // A sample value read from SD card (0-255)
uint8_t stepVal = 25;         // Step for creating triangle wave
volatile bool flag = false;   // Flag for ISR

void init_dac(uint8_t);

void setup() {

  dac.begin(0x60);            // Send the address byte to MCP4725
  dac.config_speed(400000);   // Change the i2c clock to 400KHz - fast mode (l stands for long)
  init_dac(mode);             // Initialize interrupts

  //Serial.begin(9600);
  //Serial.println("DAC initialized");
  //delay(15);
}

void loop() {

  //test code to generate values for sample - triangle wave
  if (flag) {
    sample += stepVal;

    if (sample == 255) {
      stepVal = -5;
    }
    if (sample == 0) {
      stepVal = 5;
    }
    //Serial.println(sample); //debugging
    dac.setVoltage2(sample);
    flag = false;
  }
}

// Initializing interrupts for DAC
void init_dac(uint8_t mode) {

  if (mode == 0) {
    // value for 8kHz
    t1_comp = 250;
  }
  else if (mode == 1) {
    // value for 11.97kHz
    t1_comp = 167;
  }
  else if (mode == 2) {
    // Value for 6.41kHz
    t1_comp = 312;
  }

  TCCR1A = 0;             // setting CTC mode
  TCCR1B = 0b00001010;    // setting CTC mode and prescaler of 8
  TCCR1C = 0;
  
  TIMSK1 = 0b00000010;    // Enable Timer1 compare interrupt

  // Reset Timer1 register and set compare value in OCR1A
  TCNT1 = t1_load;
  OCR1A = t1_comp;

  //Enable global interrupts
  sei();
}

ISR(TIMER1_COMPA_vect) {
  flag = true;
}

/*
  // Implementation of setVotage for Fast Mode
  
  bool Adafruit_MCP4725::setVoltage2(uint8_t sample) {

  uint16_t value = 100 + ((sample/255.0) * 3900);  //use the range with lower deformation
  uint8_t packet[2];
  
  packet[0] = value >> 8;      // Upper data bits (0.0.0.0.D11.D10.D9.D8)
  packet[1] = value & 255;     // Lower data bits (D7.D6.D5.D4.D3.D2.D1.D0)

  if (!i2c_dev->write(packet, 2)) { 
    return false;
  }
  return true;
  // returns True if write was successful, otherwise false
}
 
 // Function to define I2C Bit rate
 void Adafruit_MCP4725::config_speed(long freq) {
   TWBR = ((F_CPU / freq) - 16) / 2;
}
 
 
 
 */

 
