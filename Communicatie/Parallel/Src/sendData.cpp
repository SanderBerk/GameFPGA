/*
 * sendData.cpp
 *
 *  Created on: 11 mrt. 2019
 *      Author: sande
 */

#include "tasks.h" //Zie dit bestand voor extern "C" voorbeeld.
#include "pdata.h"

#include "stm32f0xx_hal.h"
#include "cmsis_os.h"

void mainsendData(void *pvParameters){
	PData *parralle = new PData();
	uint8_t count = 0;
	for(;;){
		if(count >= 256)
			count = 0;
		count++;
		parralle->sendLoc();
		vTaskDelay(5000);
	}
}
