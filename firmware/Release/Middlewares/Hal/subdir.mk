################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Src/blue_unit_conversion.s \
/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Src/context_switch.s \
/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Src/osal_memcpy.s 

C_SRCS += \
/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Src/fifo.c \
/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Src/hal_miscutil.c \
/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Src/miscutil.c \
/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Src/osal.c 

OBJS += \
./Middlewares/Hal/blue_unit_conversion.o \
./Middlewares/Hal/context_switch.o \
./Middlewares/Hal/fifo.o \
./Middlewares/Hal/hal_miscutil.o \
./Middlewares/Hal/miscutil.o \
./Middlewares/Hal/osal.o \
./Middlewares/Hal/osal_memcpy.o 

S_DEPS += \
./Middlewares/Hal/blue_unit_conversion.d \
./Middlewares/Hal/context_switch.d \
./Middlewares/Hal/osal_memcpy.d 

C_DEPS += \
./Middlewares/Hal/fifo.d \
./Middlewares/Hal/hal_miscutil.d \
./Middlewares/Hal/miscutil.d \
./Middlewares/Hal/osal.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Hal/blue_unit_conversion.o: /media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Src/blue_unit_conversion.s
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Hal/context_switch.o: /media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Src/context_switch.s
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Hal/fifo.o: /media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Src/fifo.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -Og -ffunction-sections -fdata-sections -g3 -std=c99 -DUSE_FULL_LL_DRIVER -DSTEVAL_IDB012V1 -DCONFIG_DEVICE_BLUENRG_LPS -DBLE_STACK_BASIC_CONF -DCONFIG_HW_SMPS_10uH -DCONFIG_HW_HSE_TUNE=32 -DCONFIG_NUM_MAX_LINKS=1 -DCONFIG_HW_LS_XTAL -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/Peripherals_Drivers/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/CMSIS/Device/ST/BlueNRG_LP/Include -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/CMSIS/Include -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/BSP/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/BSP/Components/lsm6dsox_STdC/driver -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/BSP/Components/lps22hh_STdC/driver -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/PKAMGR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/RNGMGR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/AESMGR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/BLECNTR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/BLE_Application/layers_inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/Bluetooth_LE/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/NVMDB/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/BLE_Application/Profiles/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/cryptolib/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/cryptolib/Inc/Common -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/cryptolib/Inc/AES -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Hal/hal_miscutil.o: /media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Src/hal_miscutil.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -Og -ffunction-sections -fdata-sections -g3 -std=c99 -DUSE_FULL_LL_DRIVER -DSTEVAL_IDB012V1 -DCONFIG_DEVICE_BLUENRG_LPS -DBLE_STACK_BASIC_CONF -DCONFIG_HW_SMPS_10uH -DCONFIG_HW_HSE_TUNE=32 -DCONFIG_NUM_MAX_LINKS=1 -DCONFIG_HW_LS_XTAL -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/Peripherals_Drivers/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/CMSIS/Device/ST/BlueNRG_LP/Include -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/CMSIS/Include -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/BSP/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/BSP/Components/lsm6dsox_STdC/driver -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/BSP/Components/lps22hh_STdC/driver -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/PKAMGR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/RNGMGR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/AESMGR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/BLECNTR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/BLE_Application/layers_inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/Bluetooth_LE/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/NVMDB/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/BLE_Application/Profiles/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/cryptolib/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/cryptolib/Inc/Common -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/cryptolib/Inc/AES -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Hal/miscutil.o: /media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Src/miscutil.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -Og -ffunction-sections -fdata-sections -g3 -std=c99 -DUSE_FULL_LL_DRIVER -DSTEVAL_IDB012V1 -DCONFIG_DEVICE_BLUENRG_LPS -DBLE_STACK_BASIC_CONF -DCONFIG_HW_SMPS_10uH -DCONFIG_HW_HSE_TUNE=32 -DCONFIG_NUM_MAX_LINKS=1 -DCONFIG_HW_LS_XTAL -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/Peripherals_Drivers/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/CMSIS/Device/ST/BlueNRG_LP/Include -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/CMSIS/Include -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/BSP/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/BSP/Components/lsm6dsox_STdC/driver -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/BSP/Components/lps22hh_STdC/driver -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/PKAMGR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/RNGMGR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/AESMGR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/BLECNTR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/BLE_Application/layers_inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/Bluetooth_LE/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/NVMDB/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/BLE_Application/Profiles/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/cryptolib/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/cryptolib/Inc/Common -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/cryptolib/Inc/AES -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Hal/osal.o: /media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Src/osal.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -Og -ffunction-sections -fdata-sections -g3 -std=c99 -DUSE_FULL_LL_DRIVER -DSTEVAL_IDB012V1 -DCONFIG_DEVICE_BLUENRG_LPS -DBLE_STACK_BASIC_CONF -DCONFIG_HW_SMPS_10uH -DCONFIG_HW_HSE_TUNE=32 -DCONFIG_NUM_MAX_LINKS=1 -DCONFIG_HW_LS_XTAL -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/Peripherals_Drivers/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/CMSIS/Device/ST/BlueNRG_LP/Include -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/CMSIS/Include -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/BSP/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/BSP/Components/lsm6dsox_STdC/driver -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/BSP/Components/lps22hh_STdC/driver -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/PKAMGR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/RNGMGR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/AESMGR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/BLECNTR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/BLE_Application/layers_inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/Bluetooth_LE/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/NVMDB/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/BLE_Application/Profiles/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/cryptolib/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/cryptolib/Inc/Common -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/cryptolib/Inc/AES -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/Hal/osal_memcpy.o: /media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Src/osal_memcpy.s
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


