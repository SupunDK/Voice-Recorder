# 1 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
# 2 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2
# 3 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2

# 5 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2


# 6 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
//Libraries for testing
# 8 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2
# 9 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2
# 10 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2

File file;

//#include "output.h"
# 15 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2
# 16 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2
# 17 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 2

const int chipSelect = 10;

void setup() {
  //Setting the system clock = External Oscillator Frequency
  
# 22 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 __asm__ __volatile__ ("cli" ::: "memory")
# 22 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
      ;
  
# 23 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 (*(volatile uint8_t *)(0x61)) 
# 23 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
       = 0x80;
  
# 24 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 (*(volatile uint8_t *)(0x61)) 
# 24 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
       = 0x00;
  
# 25 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 __asm__ __volatile__ ("sei" ::: "memory")
# 25 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
      ;

  //Just for arduino
  
# 28 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 (*(volatile uint8_t *)((0x04) + 0x20)) 
# 28 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
      |= (1 << 
# 28 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
               0
# 28 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
                  );
  
# 29 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
 (*(volatile uint8_t *)((0x05) + 0x20)) 
# 29 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
       |= (1 << 
# 29 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino" 3
                0
# 29 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\main\\Code\\main\\main.ino"
                   );

  //Setting up the SD card
  Serial.begin(9600);
  Serial.println("The program started");

  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed");
    return;
  }
  dac.begin(0x60);
  dac.sleep();

  setup_recording_btn();
  setup_play_btn();

  //playing = true;
}

void loop() {
  if (recording == 1) {
    Serial.println("Record pressed");
    Serial.println(recording);
    //start_recording();
  }

  if (playing == 1) {
    Serial.println("Play pressed");
    Serial.println(playing);
    start_playing();
  }
  // Serial.print(recording);
  // Serial.print(" ");
  // Serial.println(playing);
}
