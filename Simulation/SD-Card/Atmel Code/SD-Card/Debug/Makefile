################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../diskio_avr.c \
../main.c \
../pff.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
diskio_avr.o \
main.o \
pff.o

OBJS_AS_ARGS +=  \
diskio_avr.o \
main.o \
pff.o

C_DEPS +=  \
diskio_avr.d \
main.d \
pff.d

C_DEPS_AS_ARGS +=  \
diskio_avr.d \
main.d \
pff.d

OUTPUT_FILE_PATH +=SD-Card.elf

OUTPUT_FILE_PATH_AS_ARGS +=SD-Card.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./diskio_avr.o: .././diskio_avr.c
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Elec UNI\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Elec UNI\Atmel Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -B "D:\Elec UNI\Atmel Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega328p" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Elec UNI\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Elec UNI\Atmel Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -B "D:\Elec UNI\Atmel Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega328p" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./pff.o: .././pff.c
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Elec UNI\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Elec UNI\Atmel Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -B "D:\Elec UNI\Atmel Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega328p" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 5.4.0
	$(QUOTE)D:\Elec UNI\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="SD-Card.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,-L"C:\Users\Asus\Downloads" -Wl,-L"C:\Users\Asus\Downloads\fflib\source" -Wl,-L"D:\Lab Project\Atmel Studio\SD-Card\SD-Card"  -Wl,--gc-sections -mmcu=atmega328p -B "D:\Elec UNI\Atmel Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega328p"  
	@echo Finished building target: $@
	"D:\Elec UNI\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "SD-Card.elf" "SD-Card.hex"
	"D:\Elec UNI\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "SD-Card.elf" "SD-Card.eep" || exit 0
	"D:\Elec UNI\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "SD-Card.elf" > "SD-Card.lss"
	"D:\Elec UNI\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "SD-Card.elf" "SD-Card.srec"
	"D:\Elec UNI\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "SD-Card.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "SD-Card.elf" "SD-Card.a" "SD-Card.hex" "SD-Card.lss" "SD-Card.eep" "SD-Card.map" "SD-Card.srec" "SD-Card.usersignatures"
	