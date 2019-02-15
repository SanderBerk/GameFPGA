/*
 * LED.cpp
 *
 *  Created on: 7 feb. 2019
 *      Author: Marlon
 */

#include "LED.h"

#include "stm32f0xx_hal.h"

LED::LED(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin) :
	GPIOx(GPIOx),
	GPIO_Pin(GPIO_Pin)
{}

LED::~LED()
{}

void LED::on(void)
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
}

void LED::off(void)
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
}
