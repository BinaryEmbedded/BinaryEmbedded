################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DrvCcu6.c \
../Src/DrvPinCfg.c \
../Src/DrvSysInit.c \
../Src/MidCcu6.c \
../Src/MidGpio.c \
../Src/Scheduler.c 

OBJS += \
./Src/DrvCcu6.o \
./Src/DrvPinCfg.o \
./Src/DrvSysInit.o \
./Src/MidCcu6.o \
./Src/MidGpio.o \
./Src/Scheduler.o 

COMPILED_SRCS += \
./Src/DrvCcu6.src \
./Src/DrvPinCfg.src \
./Src/DrvSysInit.src \
./Src/MidCcu6.src \
./Src/MidGpio.src \
./Src/Scheduler.src 

C_DEPS += \
./Src/DrvCcu6.d \
./Src/DrvPinCfg.d \
./Src/DrvSysInit.d \
./Src/MidCcu6.d \
./Src/MidGpio.d \
./Src/Scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.src: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc27xd "-fC:/Users/home/Desktop/AurixWorkspace/BinayEmbedded/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Src/%.o: ./Src/%.src
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


