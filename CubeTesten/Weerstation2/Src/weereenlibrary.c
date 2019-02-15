/*
 * weereenlibrary.c
 *
 *  Created on: 4 Oct 2018
 *      Author: Kayne
 */
#include "weereenlibrary.h"
#include <stdlib.h>
#include <string.h>

int16_t ldrCheckVal() {
	//This function will return the Value of the LDR.
	//It has been connected and programmed in such a way that the LDR
	//only gets power once it needs to be checked. This saves power.
	int16_t adcResult = 0;
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
	HAL_ADC_Start(&hadc);
	HAL_ADC_PollForConversion(&hadc, 100);
	adcResult = HAL_ADC_GetValue(&hadc);
	HAL_ADC_Stop(&hadc);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);
	return adcResult;
}

int windfCheckVal() {
	//This function returns the time for the windspeed sensor.
	//When the windsensor detects no movement within 5 seconds it will return 0.
	//It counts the passes, when the sensor detects a pass it will count.
	//Using the GetTickCount function it will count the time amount of passes and returns a time.
	GPIO_PinState state = 0;
	GPIO_PinState state_old = 0;
	int millis_begin = xTaskGetTickCount();
	int windspeed = 0;
	int time = 0;
	while(xTaskGetTickCount() - millis_begin < 5000)
	{
		state_old = state;
		state = HAL_GPIO_ReadPin( GPIOB, GPIO_PIN_4);
		if(state != state_old)
		{
			windspeed++;
		}
		if(windspeed == 8)
		{
			time = xTaskGetTickCount() - millis_begin;
			millis_begin = 0;
			windspeed = 0;
		}
	}

	return time;

}

void viewValOnOLED(float temp, float humd, float wind, int16_t light) {
	//This function will write all values to the screen.
	//This function is using the ssd1306.h files.
	//Everything is written in chars to the screen.
	char tempbuf[6];
	char humdbuf[6];
	char windbuf[6];
	char lightbuf[6];
	gcvt(temp, 4, tempbuf);
	gcvt(humd, 4, humdbuf);
	gcvt(wind, 4, windbuf);
	itoa(light, lightbuf, 10);
	ssd1306_Fill(Black);
	ssd1306_SetCursor(0, 0);    //set cursor position x=0, y=0
	ssd1306_WriteString(tempbuf, Font_7x10, White);
	ssd1306_SetCursor(64, 0);
	ssd1306_WriteString(humdbuf, Font_7x10, White);
	ssd1306_SetCursor(0, 15);
	ssd1306_WriteString(windbuf, Font_7x10, White);
	ssd1306_SetCursor(64, 15);
	ssd1306_WriteString(lightbuf, Font_7x10, White);
	ssd1306_UpdateScreen();
}

void huart1toesp(float temp, float humd, int16_t wind, int16_t light) {
	//This function sends data to the wifi controller.
	//The Temp and Hum values are multiplied by 100 to ensure no data loss.
	//On the wifi controller they are devided by 100 again.
	int16_t inputbuf[4];
	uint8_t huart1buf[8];

	inputbuf[0] = (int16_t) (temp * 100);
	inputbuf[1] = (int16_t) (humd * 100);
	inputbuf[2] = wind;
	inputbuf[3] = light;

	uint8_t j = 0;
	for (uint8_t i = 0; i < 4; i++) {
		huart1buf[j] = (uint8_t) (inputbuf[i] & 0xFF);
		j++;
		huart1buf[j] = (uint8_t) ((inputbuf[i] >> 8) & 0xFF);
		j++;
	}
	HAL_UART_Transmit(&huart1, huart1buf, 8, 100);
}
