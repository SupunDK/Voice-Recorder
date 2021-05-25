#include <Wire.h>
#include <Adafruit_MCP4725.h>         // Has been modified to include myVoltage

Adafruit_MCP4725 dac;

void setup(void) 
{
  Serial.begin(9600);
  dac.begin(0x60);                        // Send the address byte
  TWBR = ((F_CPU /400000l) - 16) / 2;     // Change the i2c clock to 400KHz - fast mode (l stands for long)
  Serial.println("Triangle wave of 400Hz");
}

// 400Hz triangle wave implementation 
void loop(void) {
    uint8_t counter;
    for (counter = 0; counter < 250; counter += 25)
    {
      dac.myVoltage(counter);
    }
    for (counter = 250; counter > 0; counter -= 25)
    {
      dac.myVoltage(counter);
    }
}

/*
  // my implementation of setVotage for fast mode
  
  bool Adafruit_MCP4725::myVoltage(uint8_t sample) {

  uint16_t value = 100 + ((sample/255.0) * 3900);  //use the range with lower deformation
  uint8_t packet[2];
  
  packet[0] = value >> 8;        // Upper data bits (0.0.0.0.D11.D10.D9.D8)
  packet[1] = value & 255;       // Lower data bits (D7.D6.D5.D4.D3.D2.D1.D0)

  if (!i2c_dev->write(packet, 2)) { 
    return false;
  }
  return true;
  // returns True if write was successful, otherwise false
}
 */
