/*
 * si7021.c
 *
 *  Created on: 13 Sep 2018
 *      Author: Kayne
 */

#include "si7021.h"

float measHumd(uint8_t command) {
	//This function reads the data from the si7021 sensor via I2C.
	//Function gets the correct address send from the main, which determines if the function should ask for the Hum of Temp.
	HAL_I2C_Master_Transmit(&hi2c1, ADDRESS << 1, &command, 1, 100);
	osDelay(25);
	uint8_t buff[2];
	HAL_I2C_Master_Receive(&hi2c1, ADDRESS << 1, &buff, 2, 100);
	uint16_t code = buff[0] << 8 | buff[1];
	if(command == 0XF5) {
		return (((125.0 * code) / 65536) - 6);
	}
	else if(command == 0XE3) {
		return (((175.72 * code) / 65536) - 46.85);
	}
}

