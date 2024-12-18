################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/ble_anemometer.c \
../Application/User/ble_main.c \
../Application/User/calibration.c \
../Application/User/rf_device_it.c 

OBJS += \
./Application/User/ble_anemometer.o \
./Application/User/ble_main.o \
./Application/User/calibration.o \
./Application/User/rf_device_it.o 

C_DEPS += \
./Application/User/ble_anemometer.d \
./Application/User/ble_main.d \
./Application/User/calibration.d \
./Application/User/rf_device_it.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/%.o: ../Application/User/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DUSE_FULL_LL_DRIVER -DSTEVAL_IDB012V1 -DCONFIG_DEVICE_BLUENRG_LPS -DBLE_STACK_BASIC_CONF -DCONFIG_HW_SMPS_10uH -DCONFIG_HW_HSE_TUNE=32 -DCONFIG_NUM_MAX_LINKS=1 -DCONFIG_HW_LS_XTAL -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/Peripherals_Drivers/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/CMSIS/Device/ST/BlueNRG_LP/Include -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/CMSIS/Include -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/BSP/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/BSP/Components/lsm6dsox_STdC/driver -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Drivers/BSP/Components/lps22hh_STdC/driver -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/hal/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/PKAMGR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/RNGMGR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/AESMGR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/BLECNTR/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/BLE_Application/layers_inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/Bluetooth_LE/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/NVMDB/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/BLE_Application/Profiles/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/cryptolib/Inc -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/cryptolib/Inc/Common -I/media/radoslav/a2750a59-cb99-4f0a-baf8-e7de8053c714/blue-nrg/BlueNRG-LP_LPS_DK_1.5.0/Middlewares/ST/cryptolib/Inc/AES -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


