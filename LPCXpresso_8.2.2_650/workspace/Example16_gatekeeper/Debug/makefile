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
all: Example16_gatekeeper.axf

# Tool invocations
Example16_gatekeeper.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\Debajyoti Maitra\Documents\LPCXpresso_8.2.2_650\workspace\CMSISv1p30_LPC17xx\Debug" -L"C:\Users\Debajyoti Maitra\Documents\LPCXpresso_8.2.2_650\workspace\FreeRTOS_Library\Debug" -Xlinker --gc-sections -Xlinker -Map=Example16_gatekeeper.map -mcpu=cortex-m3 -mthumb -T "Example16_gatekeeper_Debug.ld" -o "Example16_gatekeeper.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Example16_gatekeeper.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size Example16_gatekeeper.axf; # arm-none-eabi-objcopy -O ihex Example16_gatekeeper.axf Example16_gatekeeper.hex ;
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
