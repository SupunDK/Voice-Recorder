# 1 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"




# 6 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2
# 7 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2

# 9 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2


# 10 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
//Libraries for testing
# 12 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2
# 13 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2

File file;

# 17 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2
# 18 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2
# 19 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2

const int chipSelect = 10;

void setup() {
  //Setting up the SD card
  Serial.begin(9600);
  Serial.println("The program started");

  if (!SD.begin(chipSelect)) {
    return;
  }

  setup_recording_btn();
  setup_play_btn();
}

void loop() {

}
