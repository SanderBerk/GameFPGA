/*
 * pdata.cpp
 *
 *  Created on: 11 mrt. 2019
 *      Author: sande
 */

#include "pdata.h"
#include "stm32f0xx_hal.h"
#include "cmsis_os.h"
#include "Object.h"


PData::PData(){
}

PData::~PData(){};

void PData::sendLoc(){
	Object * muur = new Object(604,523,3, 30, 30);
	uint16_handle_data_send((uint16_t)muur->getSpritenr() | 0xC000);
	uint16_handle_data_send(muur->getLposX() | 0x4000);
	uint16_handle_data_send(muur->getLposY() | 0x8000);
	delete muur;
}

void PData::uint16_handle_data_send(uint16_t data){
	for(uint8_t i = 0; i < 2; i++){
		char send = (char)(data >> i*8) & 0xFF;
		sendData_8(send);
	}
}

void PData::sendData_8(char data){
	uint8_t tdata = data;
	if((data >> 7) & 0x01){
		HAL_GPIO_WritePin(GPIOB, pin_7_Pin, GPIO_PIN_SET);
		tdata = tdata - 128;
	}
	if ((data >> 6) & 0x01){
		HAL_GPIO_WritePin(GPIOB, pin_6_Pin, GPIO_PIN_SET);
		tdata = tdata-64;
	}
	if ((data >> 5) & 0x01){
		HAL_GPIO_WritePin(GPIOB, pin_5_Pin, GPIO_PIN_SET);
		tdata = tdata-32;
	}
	if ((data >> 4) & 0x01){
		HAL_GPIO_WritePin(GPIOC, pin_4_Pin, GPIO_PIN_SET);
		tdata = tdata-16;
	}
	if ((data >> 3) & 0x01){
		HAL_GPIO_WritePin(GPIOC, pin_3_Pin, GPIO_PIN_SET);
		tdata = tdata-8;
	}
	if((data >> 2) & 0x01){
		HAL_GPIO_WritePin(GPIOB, pin_2_Pin, GPIO_PIN_SET);
		tdata = tdata -4;
	}

	if ((data >> 1) & 0x01){
		HAL_GPIO_WritePin(GPIOA, pin_1_Pin, GPIO_PIN_SET);
		tdata = tdata-2;
	}
	if ((data) & 0x01){
		HAL_GPIO_WritePin(GPIOA, pin_0_Pin, GPIO_PIN_SET);
		tdata = tdata-1;
	}
	HAL_GPIO_WritePin(GPIOA, clk_Pin, GPIO_PIN_SET);
	vTaskDelay(1000);
	HAL_GPIO_WritePin(GPIOA, pin_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, pin_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, pin_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, pin_3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, pin_4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, pin_5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, pin_6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, pin_7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, clk_Pin, GPIO_PIN_RESET);
}
