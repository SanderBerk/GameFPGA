//Credits naar Marlon
#include "stm32f0xx_hal.h"
#include <stdio.h>
#include <string>
#include "Sprite.h"
#include "tasks.h" //Zie dit bestand voor extern "C" voorbeeld.
#include "cmsis_os.h"
#include "Game.h"
#include "ssd1306.h"
#include "fonts.h"
#include "Highscore.h"
#include <stdlib.h>
#include "Object.h"


//declare global variables
Game MainGame;
int statebutton1 = 0;
int statebutton2 = 0;
int statebutton3 = 0;
//declare functions
void Addsprites();
void cpptest();
void init();
void cppmaintask_1(void *pvParameters);
void cppmaintask_2(void *pvParameters);
void Settings();
void Mainscreen();
void Highscores();
void Playing();

void cpptest()
{
	ssd1306_UpdateScreen();
    ssd1306_Fill(Black);
    ssd1306_SetCursor(20,0);
    ssd1306_WriteString("test", Font_7x10, White);

	ssd1306_SetCursor(0,0);
	if(statebutton1 == 1) ssd1306_WriteString("1", Font_7x10, White);
	if(statebutton1 == 0) ssd1306_WriteString("0", Font_7x10, White);

	ssd1306_SetCursor(0,10);
	if(statebutton2 == 1) ssd1306_WriteString("1", Font_7x10, White);
	if(statebutton2 == 0) ssd1306_WriteString("0", Font_7x10, White);

	ssd1306_SetCursor(0,20);
	if(statebutton3 == 1) ssd1306_WriteString("1", Font_7x10, White);
	if(statebutton3 == 0) ssd1306_WriteString("0", Font_7x10, White);
}

void init()
{
	cpptest();
	MainGame.setResolution(640,420);
	Addsprites();

}

void cppmaintask_1(void *pvParameters)
{

	ssd1306_Init();
	init();
	MainGame.GameState = MainGame.INIT;
	for(;;)
	{
		switch (MainGame.GameState) {
			case MainGame.INIT:
				init();
				MainGame.GameState = MainGame.MAINSCREEN;
				break;
			case MainGame.MAINSCREEN:
				Mainscreen();
				break;
			case MainGame.SETTINGS:
				Settings();
				break;
			case MainGame.HIGHSCORES:
				Highscores();
				break;
			case MainGame.PLAYING:
				Playing();
				break;
			default:
				break;
		}
	}
}

void cppmaintask_2(void *pvParameters)
{
	for(;;)
	{
		statebutton1 = HAL_GPIO_ReadPin( GPIOB, GPIO_PIN_3);
		statebutton2 = HAL_GPIO_ReadPin( GPIOB, GPIO_PIN_4);
		statebutton3 = HAL_GPIO_ReadPin( GPIOB, GPIO_PIN_5);
	}
}

void Addsprites()
{
	Sprite sprite = new Sprite();
}

void Settings()
{

}
void Mainscreen()
{
	int mainscreen = 1;
	while(mainscreen == 1)
	{
		cpptest();
	}
}
void Highscores()
{

}
void Playing()
{

}

