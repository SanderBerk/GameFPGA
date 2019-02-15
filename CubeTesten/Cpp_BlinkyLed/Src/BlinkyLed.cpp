/*
 * BlinkyLed.cpp
 *
 *  Created on: 7 feb. 2019
 *      Author: Marlon
 */

#include "tasks.h" //Zie dit bestand voor extern "C" voorbeeld.
#include "LED.h"

#include "stm32f0xx_hal.h"
#include "cmsis_os.h"


/*
 * Blinky LED zijn main functie met C++ code.
 */
void blinkyMain(void *pvParameters)
{
	LED *led1 = new LED(GPIOA,GPIO_PIN_5);

	for(;;)
	{
		led1->on();
		vTaskDelay(1000);
		led1->off();
		vTaskDelay(1000);
	}
}

