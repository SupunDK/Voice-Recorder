const int analogReadPin = 0;
int sample;
String b_sample;
int start;

String DtoB(int d_val);

void setup(){
  Serial.begin(9600);
}

void loop(){
  start = millis();
  sample = map(analogRead(analogReadPin), 0, 1023, 0, 255);
  
  b_sample = DtoB(sample);

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
