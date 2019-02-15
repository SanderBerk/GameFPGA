################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Src/freertos.c \
C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Src/main.c \
C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Src/stm32f0xx_hal_msp.c \
C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Src/stm32f0xx_hal_timebase_TIM.c \
C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Src/stm32f0xx_it.c 

OBJS += \
./Application/User/freertos.o \
./Application/User/main.o \
./Application/User/stm32f0xx_hal_msp.o \
./Application/User/stm32f0xx_hal_timebase_TIM.o \
./Application/User/stm32f0xx_it.o 

C_DEPS += \
./Application/User/freertos.d \
./Application/User/main.d \
./Application/User/stm32f0xx_hal_msp.d \
./Application/User/stm32f0xx_hal_timebase_TIM.d \
./Application/User/stm32f0xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/freertos.o: C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Src/freertos.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/main.o: C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f0xx_hal_msp.o: C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Src/stm32f0xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f0xx_hal_timebase_TIM.o: C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Src/stm32f0xx_hal_timebase_TIM.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f0xx_it.o: C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Src/stm32f0xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


