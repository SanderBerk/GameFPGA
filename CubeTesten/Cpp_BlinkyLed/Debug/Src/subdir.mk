################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/freertos.c \
../Src/main.c \
../Src/stm32f0xx_hal_msp.c \
../Src/stm32f0xx_hal_timebase_tim.c \
../Src/stm32f0xx_it.c \
../Src/system_stm32f0xx.c 

CPP_SRCS += \
../Src/BlinkyLed.cpp \
../Src/LED.cpp 

OBJS += \
./Src/BlinkyLed.o \
./Src/LED.o \
./Src/freertos.o \
./Src/main.o \
./Src/stm32f0xx_hal_msp.o \
./Src/stm32f0xx_hal_timebase_tim.o \
./Src/stm32f0xx_it.o \
./Src/system_stm32f0xx.o 

C_DEPS += \
./Src/freertos.d \
./Src/main.d \
./Src/stm32f0xx_hal_msp.d \
./Src/stm32f0xx_hal_timebase_tim.d \
./Src/stm32f0xx_it.d \
./Src/system_stm32f0xx.d 

CPP_DEPS += \
./Src/BlinkyLed.d \
./Src/LED.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/Cpp_BlinkyLed/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/Cpp_BlinkyLed/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/Cpp_BlinkyLed/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/Cpp_BlinkyLed/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/Cpp_BlinkyLed/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/Cpp_BlinkyLed/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/Cpp_BlinkyLed/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/Cpp_BlinkyLed/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/Cpp_BlinkyLed/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/Cpp_BlinkyLed/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/Cpp_BlinkyLed/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/Cpp_BlinkyLed/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


