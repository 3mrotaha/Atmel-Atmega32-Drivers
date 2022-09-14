################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KPAD/KPAD_config.c \
../HAL/KPAD/KPAD_prog.c 

OBJS += \
./HAL/KPAD/KPAD_config.o \
./HAL/KPAD/KPAD_prog.o 

C_DEPS += \
./HAL/KPAD/KPAD_config.d \
./HAL/KPAD/KPAD_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KPAD/%.o: ../HAL/KPAD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


