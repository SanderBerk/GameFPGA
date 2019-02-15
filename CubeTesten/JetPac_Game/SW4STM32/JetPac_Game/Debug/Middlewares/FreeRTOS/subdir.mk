################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c \
C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/croutine.c \
C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/event_groups.c \
C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c \
C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/list.c \
C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c \
C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/queue.c \
C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/tasks.c \
C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/timers.c 

OBJS += \
./Middlewares/FreeRTOS/cmsis_os.o \
./Middlewares/FreeRTOS/croutine.o \
./Middlewares/FreeRTOS/event_groups.o \
./Middlewares/FreeRTOS/heap_4.o \
./Middlewares/FreeRTOS/list.o \
./Middlewares/FreeRTOS/port.o \
./Middlewares/FreeRTOS/queue.o \
./Middlewares/FreeRTOS/tasks.o \
./Middlewares/FreeRTOS/timers.o 

C_DEPS += \
./Middlewares/FreeRTOS/cmsis_os.d \
./Middlewares/FreeRTOS/croutine.d \
./Middlewares/FreeRTOS/event_groups.d \
./Middlewares/FreeRTOS/heap_4.d \
./Middlewares/FreeRTOS/list.d \
./Middlewares/FreeRTOS/port.d \
./Middlewares/FreeRTOS/queue.d \
./Middlewares/FreeRTOS/tasks.d \
./Middlewares/FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/FreeRTOS/cmsis_os.o: C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FreeRTOS/croutine.o: C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/croutine.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FreeRTOS/event_groups.o: C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/event_groups.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FreeRTOS/heap_4.o: C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FreeRTOS/list.o: C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/list.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FreeRTOS/port.o: C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FreeRTOS/queue.o: C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/queue.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FreeRTOS/tasks.o: C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/tasks.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FreeRTOS/timers.o: C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/timers.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x8 -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


