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
START_SEG_LT.lss \

FLASH_IMAGE += \
START_SEG_LT.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: START_SEG_LT.elf secondary-outputs

# Tool invocations
START_SEG_LT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,START_SEG_LT.map -mmcu=atmega32 -o "START_SEG_LT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

START_SEG_LT.lss: START_SEG_LT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S START_SEG_LT.elf  >"START_SEG_LT.lss"
	@echo 'Finished building: $@'
	@echo ' '

START_SEG_LT.hex: START_SEG_LT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex START_SEG_LT.elf  "START_SEG_LT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: START_SEG_LT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 START_SEG_LT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) START_SEG_LT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
