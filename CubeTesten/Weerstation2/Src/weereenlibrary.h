/*
 * weereenlibrary.h
 *
 *  Created on: 4 Oct 2018
 *      Author: Kayne
 */
#include "main.h"
#include "stm32f0xx_hal.h"
#include "cmsis_os.h"
#include "si7021.h"
#include "ssd1306.h"

typedef short int int16_t;

extern UART_HandleTypeDef huart1;
extern ADC_HandleTypeDef hadc;

int16_t ldrCheckVal(); //Reads ldr val and returns
void viewValOnOLED(float temp, float humd, float wind, int16_t light);
void huart1toesp(float temp, float humd, int16_t wind, int16_t light);
int windfCheckVal();

