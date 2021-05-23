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
  if (record) {
    
# 37 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 3
   __asm__ __volatile__ ("cli" ::: "memory")
# 37 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
        ;

    start_adc();

    if (SD.exists("test3.txt")) {
      SD.remove("test3.txt");
    }

    file = SD.open("test3.txt", (O_READ | O_WRITE | O_CREAT | O_APPEND));

    
# 47 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 3
   __asm__ __volatile__ ("sei" ::: "memory")
# 47 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
        ;

    while (record);

    
# 51 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 3
   __asm__ __volatile__ ("cli" ::: "memory")
# 51 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
        ;

    stop_adc();
    file.close();

    
# 56 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 3
   __asm__ __volatile__ ("sei" ::: "memory")
# 56 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
        ;
  }

  if (playing) {
    
# 60 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 3
   __asm__ __volatile__ ("cli" ::: "memory")
# 60 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
        ;

    file = SD.open("TEST3.txt");
    pwm_generate(0);

    
# 65 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 3
   __asm__ __volatile__ ("sei" ::: "memory")
# 65 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
        ;

    while (playing);

    
# 69 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 3
   __asm__ __volatile__ ("cli" ::: "memory")
# 69 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
        ;

    file.close();
    
# 72 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 3
   (*(volatile uint8_t *)(0x6F)) 
# 72 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
          = 0b00000000;
    
# 73 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 3
   (*(volatile uint8_t *)((0x04) + 0x20)) 
# 73 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
        ^= (1 << 
# 73 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 3
                 1
# 73 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
                       );
    
# 74 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 3
   (*(volatile uint8_t *)((0x0B) + 0x20)) 
# 74 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
         = 0b00000000;
    
# 75 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 3
   (*(volatile uint8_t *)((0x0A) + 0x20)) 
# 75 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
        = 0b00000000;

    
# 77 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino" 3
   __asm__ __volatile__ ("sei" ::: "memory")
# 77 "c:\\Users\\HP\\OneDrive - University of Moratuwa\\Campus Academics\\Campus\\Campus Notes\\Sem 2\\Lab Project\\Project\\Electronic-Project\\ADC\\Testing of ADC\\main\\main.ino"
        ;
  }
}
