################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/SW4STM32/startup_stm32f030x8.s 

OBJS += \
./Application/SW4STM32/startup_stm32f030x8.o 


# Each subdirectory must supply rules for building sources it contributes
Application/SW4STM32/startup_stm32f030x8.o: C:/Users/Rinke.RINKE-LENOVO/Desktop/JetPac_Game/SW4STM32/startup_stm32f030x8.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


