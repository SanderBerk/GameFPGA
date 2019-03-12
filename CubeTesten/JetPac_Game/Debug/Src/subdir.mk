################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/fonts.c \
../Src/freertos.c \
../Src/main.c \
../Src/ssd1306.c \
../Src/stm32f0xx_hal_msp.c \
../Src/stm32f0xx_hal_timebase_TIM.c \
../Src/stm32f0xx_it.c \
../Src/system_stm32f0xx.c 

CPP_SRCS += \
../Src/CppMain.cpp \
../Src/ExtraFunctions.cpp \
../Src/Game.cpp \
../Src/Highscore.cpp \
../Src/Object.cpp \
../Src/Sprite.cpp 

OBJS += \
./Src/CppMain.o \
./Src/ExtraFunctions.o \
./Src/Game.o \
./Src/Highscore.o \
./Src/Object.o \
./Src/Sprite.o \
./Src/fonts.o \
./Src/freertos.o \
./Src/main.o \
./Src/ssd1306.o \
./Src/stm32f0xx_hal_msp.o \
./Src/stm32f0xx_hal_timebase_TIM.o \
./Src/stm32f0xx_it.o \
./Src/system_stm32f0xx.o 

C_DEPS += \
./Src/fonts.d \
./Src/freertos.d \
./Src/main.d \
./Src/ssd1306.d \
./Src/stm32f0xx_hal_msp.d \
./Src/stm32f0xx_hal_timebase_TIM.d \
./Src/stm32f0xx_it.d \
./Src/system_stm32f0xx.d 

CPP_DEPS += \
./Src/CppMain.d \
./Src/ExtraFunctions.d \
./Src/Game.d \
./Src/Highscore.d \
./Src/Object.d \
./Src/Sprite.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke/Documents/GitHub/GameFPGA/CubeTesten/JetPac_Game/Inc" -I"C:/Users/Rinke/Documents/GitHub/GameFPGA/CubeTesten/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke/Documents/GitHub/GameFPGA/CubeTesten/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke/Documents/GitHub/GameFPGA/CubeTesten/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/Users/Rinke/Documents/GitHub/GameFPGA/CubeTesten/JetPac_Game/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/Rinke/Documents/GitHub/GameFPGA/CubeTesten/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke/Documents/GitHub/GameFPGA/CubeTesten/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Rinke/Documents/GitHub/GameFPGA/CubeTesten/JetPac_Game/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke/Documents/GitHub/GameFPGA/CubeTesten/JetPac_Game/Inc" -I"C:/Users/Rinke/Documents/GitHub/GameFPGA/CubeTesten/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke/Documents/GitHub/GameFPGA/CubeTesten/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke/Documents/GitHub/GameFPGA/CubeTesten/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/Users/Rinke/Documents/GitHub/GameFPGA/CubeTesten/JetPac_Game/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/Rinke/Documents/GitHub/GameFPGA/CubeTesten/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke/Documents/GitHub/GameFPGA/CubeTesten/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Rinke/Documents/GitHub/GameFPGA/CubeTesten/JetPac_Game/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


