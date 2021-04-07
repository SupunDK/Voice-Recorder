/*
This code simulates the Analog-to-Digital conversion of a signal.
*/
const int analogReadPin = 0; 
int sample;
String b_sample;

String DtoB(int d_val); //function to convert a given decimal value into 8-bit binary value.

void setup(){
  Serial.begin(9600);
}

void loop(){
  sample = map(analogRead(analogReadPin), 0, 1023, 0, 255); //Taking a sample of the input through the in-built ADC and converting it to a quantization level between 0 and 255
  
  b_sample = DtoB(sample); //Encoding the quantized level into an 8-bit binary value

  //Demonstrating the encoded value with the original sample value
  Serial.print(sample);
  Serial.print(" => ");
  Serial.println(b_sample);
}

String DtoB(int d_val){
    String b_val = "";

    while(d_val != 0){
        b_val = String(d_val%2) + b_val;

        d_val = d_val/2;
    }

    while(b_val.length() != 8){
        b_val = "0" + b_val;
    }

    return b_val;
}
