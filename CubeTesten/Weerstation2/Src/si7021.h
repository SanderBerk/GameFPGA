/*
 * si7021.h
 *
 *  Created on: 13 Sep 2018
 *      Author: Kayne
 */
#include "stm32f0xx_hal.h"

#include "cmsis_os.h"

#ifndef SI7021_H_
#define SI7021_H_

#define ADDRESS      0x40
#define TEMP_MEASURE_NOHOLD  0xE3
#define HUMD_MEASURE_NOHOLD  0xF5

extern I2C_HandleTypeDef hi2c1;

float measTemp(uint8_t command);
float measHumd(uint8_t command);
#endif /* SI7021_H_ */
