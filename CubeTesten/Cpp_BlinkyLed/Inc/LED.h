/*
 * LED.h
 *
 *  Created on: 7 feb. 2019
 *      Author: Marlon
 */

#ifndef LED_H_
#define LED_H_

#include "stm32f0xx_hal.h"

class LED {
public:
	explicit LED(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
	virtual ~LED();
public:
	void on();
	void off();
private:
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
};

#endif /* LED_H_ */
