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
Object CurrentObjects[15];
int amountCurrentObjects = 0;
Object Colliding1;
Object Colliding2;
int objnr = 0;

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
	//cpptest();
	//MainGame.setResolution(640,420);
	MainGame.setResolution(120,20);
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
	Sprite sprite = Sprite(1,1,1);
	Sprite sprite2 = Sprite(1,1,2);
	MainGame.addSprite(sprite);
	MainGame.addSprite(sprite2);
}

void Settings()
{

}

void draw(Object obj)
{
    ssd1306_SetCursor(obj.getLposX(),obj.getLposY());
    ssd1306_WriteString(".", Font_7x10, White);
}

int check(Object obj)
{
	for(int i = 0;i<=amountCurrentObjects;i++)
	{
		if(obj.getLposX() == CurrentObjects[i].getLposX())
		{
			if(obj.getLposY() == CurrentObjects[i].getLposY())
			{
				if(obj.objnr != CurrentObjects[i].objnr) return 1;
			}
		}
	}
	return -1;
}

void Mainscreen()
{
	int mainscreen = 1;
	Object object1 = Object(0,0,MainGame.getSprite(1));
	Object object2 = Object(46,10,MainGame.getSprite(2));
	CurrentObjects[0] = object1;
	CurrentObjects[1] = object2;
	CurrentObjects[0].objnr = 0;
	CurrentObjects[1].objnr = 1;;
	amountCurrentObjects = 1;
	int i = 0;
	int way = 0;
	int j = 0;
	int way1 = 0;
	while(mainscreen == 1)
	{

		ssd1306_UpdateScreen();
		draw(CurrentObjects[0]);
		draw(CurrentObjects[1]);
		CurrentObjects[0].changeLposX(i);
		CurrentObjects[0].changeLposY(j);

		if(check(CurrentObjects[0]) == 1)
		{
			if(way1 == 1) way1 = 0;
			else if(way1 == 0) way1 = 1;
			if(way == 1) way = 0;
			else if(way == 0) way = 1;
		}

		if(j > 20) way1 = 0;
		else if(j < 0) way1 = 1;
		if(way1 == 0) j--;
		else if(way1 == 1) j++;


		if(i > 115) way = 0;
		else if(i < 0) way = 1;
		if(way == 0) i--;
		else if(way == 1) i++;





	}
	cpptest();


}
void Highscores()
{

}
void Playing()
{

}

