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
all: Example07_unequ_prio_idle.axf

# Tool invocations
Example07_unequ_prio_idle.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/mnt2/babu/lpcxp_workspace_frtos_ws_20_06_2015_2/CMSISv1p30_LPC17xx/Debug" -L"/mnt2/babu/lpcxp_workspace_frtos_ws_20_06_2015_2/FreeRTOS_Library/Debug" -Xlinker --gc-sections -Xlinker -Map=Example07_unequ_prio_idle.map -mcpu=cortex-m3 -mthumb -T "Example07_unequ_prio_idle_Debug.ld" -o "Example07_unequ_prio_idle.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) Example07_unequ_prio_idle.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size Example07_unequ_prio_idle.axf; # arm-none-eabi-objcopy -O ihex Example07_unequ_prio_idle.axf Example07_unequ_prio_idle.hex ;
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
