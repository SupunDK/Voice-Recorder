const int analogReadPin = 0;
int val;

void setup(){
    Serial.begin(9600);
}

void loop(){
    Serial.println("\nTime: ");
    Serial.println(millis());

    val = map(analogRead(analogReadPin), 0, 1023, 0, 255);

}
