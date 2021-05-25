#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

void setup(void) 
{
  dac.begin(0x60);
  TWBR = ((F_CPU /400000l) - 16) / 2; // Change the i2c clock to 400KHz - fast mode (l stands for long)

}

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
