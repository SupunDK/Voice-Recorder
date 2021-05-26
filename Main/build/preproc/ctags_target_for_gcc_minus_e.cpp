# 1 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
# 2 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2
# 3 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2

# 5 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2


# 6 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
//Libraries for testing
# 8 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2
# 9 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2
# 10 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2

File file;

//#include "output.h"
# 15 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2
# 16 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2
# 17 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 2

const int chipSelect = 10;

void setup() {
  //Setting up the SD card
  Serial.begin(9600);
  Serial.println("The program started");

  if (!SD.begin(chipSelect)) {
    return;
  }
  dac.begin(0x60);

  setup_recording_btn();
  setup_play_btn();
}

void loop() {
  if (recording) {
    start_recording();
  }

  if (playing) {
    start_playing();
  }
}
