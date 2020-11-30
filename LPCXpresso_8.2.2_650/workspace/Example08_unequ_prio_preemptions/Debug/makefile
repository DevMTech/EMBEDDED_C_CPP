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
all: Example08_unequ_prio_preemptions.axf

# Tool invocations
Example08_unequ_prio_preemptions.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\Debajyoti Maitra\Documents\LPCXpresso_8.2.2_650\workspace\CMSISv2p00_LPC17xx\Debug" -L"C:\Users\Debajyoti Maitra\Documents\LPCXpresso_8.2.2_650\workspace\FreeRTOS_Library\Debug" -Xlinker --gc-sections -Xlinker -Map=Example08_unequ_prio_preemptions.map -mcpu=cortex-m3 -mthumb -T "Example08_unequ_prio_preemptions_Debug.ld" -o "Example08_unequ_prio_preemptions.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Example08_unequ_prio_preemptions.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size Example08_unequ_prio_preemptions.axf; # arm-none-eabi-objcopy -O ihex Example08_unequ_prio_preemptions.axf Example08_unequ_prio_preemptions.hex ;
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
