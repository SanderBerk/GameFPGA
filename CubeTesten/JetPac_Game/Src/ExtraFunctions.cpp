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

int getSpriteNrByString(char j)
{
	if(j == '1') return 7;
	if(j == '2') return 8;
	if(j == '3') return 9;
	if(j == '4') return 10;
	if(j == '5') return 11;
	if(j == '6') return 12;
	if(j == '7') return 13;
	if(j == '8') return 14;
	if(j == '9') return 15;
	if(j == '0') return 16;
	if(j == 'a') return 17;
	if(j == 'b') return 18;
	if(j == 'c') return 19;
	if(j == 'd') return 20;
	if(j == 'e') return 21;
	if(j == 'f') return 22;
	if(j == 'g') return 23;
	if(j == 'h') return 24;
	if(j == 'i') return 25;
	if(j == 'j') return 26;
	if(j == 'k') return 27;
	if(j == 'l') return 28;
	if(j == 'm') return 29;
	if(j == 'n') return 30;
	if(j == 'o') return 31;
	if(j == 'p') return 32;
	if(j == 'q') return 33;
	if(j == 'r') return 34;
	if(j == 's') return 35;
	if(j == 't') return 36;
	if(j == 'u') return 37;
	if(j == 'v') return 38;
	if(j == 'w') return 39;
	if(j == 'x') return 40;
	if(j == 'y') return 41;
	if(j == 'z') return 42;
	else
		return -1;
}

void Init()
{

}

void ManualCheck()
{
	statebutton1 = HAL_GPIO_ReadPin( GPIOB, GPIO_PIN_3);
	statebutton2 = HAL_GPIO_ReadPin( GPIOB, GPIO_PIN_4);
	statebutton3 = HAL_GPIO_ReadPin( GPIOB, GPIO_PIN_5);
}

void cpptest()
{
	ssd1306_UpdateScreen();
    ssd1306_Fill(Black);
    ssd1306_SetCursor(20,0);
    ssd1306_WriteString("test", Font_7x10, White);

	ssd1306_SetCursor(0,0);
	if(statebutton1 == true) ssd1306_WriteString("1", Font_7x10, White);
	if(statebutton1 == false) ssd1306_WriteString("0", Font_7x10, White);

	ssd1306_SetCursor(0,10);
	if(statebutton2 == true) ssd1306_WriteString("1", Font_7x10, White);
	if(statebutton2 == false) ssd1306_WriteString("0", Font_7x10, White);

	ssd1306_SetCursor(0,20);
	if(statebutton3 == true) ssd1306_WriteString("1", Font_7x10, White);
	if(statebutton3 == false) ssd1306_WriteString("0", Font_7x10, White);
}


