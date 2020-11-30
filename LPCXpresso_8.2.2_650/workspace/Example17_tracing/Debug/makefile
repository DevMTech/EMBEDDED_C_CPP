################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include FreeRTOS_Source/portable/subdir.mk
-include FreeRTOS_Source/demo_code/subdir.mk
-include FreeRTOS_Source/subdir.mk
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
all: Example17_tracing.axf

# Tool invocations
Example17_tracing.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\Debajyoti Maitra\Documents\LPCXpresso_8.2.2_650\workspace\CMSISv1p30_LPC17xx\Debug" -Xlinker --gc-sections -Xlinker -Map=Example17_tracing.map -mcpu=cortex-m3 -mthumb -T "Example17_tracing_Debug.ld" -o "Example17_tracing.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Example17_tracing.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size Example17_tracing.axf; # arm-none-eabi-objcopy -O ihex Example17_tracing.axf Example17_tracing.hex ;
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
