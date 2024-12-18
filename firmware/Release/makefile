################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/RNG/subdir.mk
-include Middlewares/Profiles/subdir.mk
-include Middlewares/PKA/subdir.mk
-include Middlewares/NVM/subdir.mk
-include Middlewares/Hal/subdir.mk
-include Middlewares/Cryptolib/subdir.mk
-include Middlewares/BLE_Stack/subdir.mk
-include Middlewares/BLECNTR/subdir.mk
-include Middlewares/AES/subdir.mk
-include Drivers/Peripherals_Drivers/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Drivers/BSP/subdir.mk
-include Application/User/subdir.mk
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
POST_BUILD_OBJCOPY += \
BLE_Anemometer.hex \

POST_BUILD_PRINT_SIZE += \
elf-size \


# All Target
all: BLE_Anemometer.elf secondary-outputs

# Tool invocations
BLE_Anemometer.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -nostartfiles -nodefaultlibs -Wl,--gc-sections -Wl,-Map="BLE_Anemometer.map" -T"../BlueNRG_LPS.ld" -L/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/Bluetooth_LE/Library -L/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/cryptolib -Wl,--cref --specs=nano.specs -o "BLE_Anemometer.elf"  -Wl,--start-group @"objects.list" $(USER_OBJS) $(LIBS) -lm -lc  -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

BLE_Anemometer.hex: BLE_Anemometer.elf
	@echo 'Invoking: Generate binary'
	arm-none-eabi-objcopy -O ihex "BLE_Anemometer.elf"  "BLE_Anemometer.hex"
	@echo 'Finished building: $@'
	@echo ' '

elf-size: BLE_Anemometer.elf
	@echo 'Invoking: Print Size'
	arm-none-eabi-size -B "BLE_Anemometer.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(POST_BUILD_OBJCOPY)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(POST_BUILD_PRINT_SIZE)$(C_DEPS) BLE_Anemometer.elf BLE_Anemometer.bin *.map
	-@echo ' '

post-build:
	arm-none-eabi-objcopy -O binary BLE_Anemometer.elf BLE_Anemometer.bin
	-@echo ' '

secondary-outputs: $(POST_BUILD_OBJCOPY) $(POST_BUILD_PRINT_SIZE)

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
