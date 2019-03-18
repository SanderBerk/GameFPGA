/*
 * ExtraFunctions.cpp
 *
 *  Created on: 26 Feb 2019
 *      Author: Rinke
 */

#include "ExtraFunctions.h"

extern Game MainGame;
extern bool statebutton1;
extern bool statebutton2;
extern bool statebutton3;
extern int debug;

void Init()
{

}

void ManualCheck()
{
	statebutton1 = HAL_GPIO_ReadPin( GPIOC, button_1_Pin);
	statebutton2 = HAL_GPIO_ReadPin( GPIOC, button_2_Pin);
	statebutton3 = HAL_GPIO_ReadPin( GPIOC, button_3_Pin);
}

void cpptest()
{
	ssd1306_UpdateScreen();
    //ssd1306_Fill(Black);
    //ssd1306_SetCursor(20,0);
   // ssd1306_WriteString("test", Font_7x10, White);

	ssd1306_SetCursor(0,0);
	if(statebutton1 == true) ssd1306_WriteString("1", Font_7x10, White);
	if(statebutton1 == false) ssd1306_WriteString("0", Font_7x10, White);

	ssd1306_SetCursor(0,10);
	if(statebutton2 == true) ssd1306_WriteString("1", Font_7x10, White);
	if(statebutton2 == false) ssd1306_WriteString("0", Font_7x10, White);

	ssd1306_SetCursor(0,20);
	if(statebutton3 == true) ssd1306_WriteString("1", Font_7x10, White);
	if(statebutton3 == false) ssd1306_WriteString("0", Font_7x10, White);
	ManualCheck();
}


