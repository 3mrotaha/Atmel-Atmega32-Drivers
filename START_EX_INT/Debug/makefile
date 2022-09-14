################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
START_EX_INT.lss \

FLASH_IMAGE += \
START_EX_INT.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: START_EX_INT.elf secondary-outputs

# Tool invocations
START_EX_INT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,START_EX_INT.map -mmcu=atmega32 -o "START_EX_INT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

START_EX_INT.lss: START_EX_INT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S START_EX_INT.elf  >"START_EX_INT.lss"
	@echo 'Finished building: $@'
	@echo ' '

START_EX_INT.hex: START_EX_INT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex START_EX_INT.elf  "START_EX_INT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: START_EX_INT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 START_EX_INT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) START_EX_INT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
