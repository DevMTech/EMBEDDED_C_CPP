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
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Example02_equ_prio_reentrant.axf

# Tool invocations
Example02_equ_prio_reentrant.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\Debajyoti Maitra\Documents\LPCXpresso_8.2.2_650\workspace\CMSISv1p30_LPC17xx\Debug" -L"C:\Users\Debajyoti Maitra\Documents\LPCXpresso_8.2.2_650\workspace\FreeRTOS_Library\Debug" -Xlinker --gc-sections -Xlinker -Map=Example02_equ_prio_reentrant.map -mcpu=cortex-m3 -mthumb -T "Example02_equ_prio_reentrant_Debug.ld" -o "Example02_equ_prio_reentrant.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Example02_equ_prio_reentrant.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size Example02_equ_prio_reentrant.axf; # arm-none-eabi-objcopy -O ihex Example02_equ_prio_reentrant.axf Example02_equ_prio_reentrant.hex ;
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
