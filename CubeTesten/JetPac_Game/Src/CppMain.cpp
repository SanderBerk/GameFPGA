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
#include <stdint.h>


//declare global variables
Game MainGame = Game(640,420);
bool statebutton1 = 0;
bool statebutton2 = 0;
bool statebutton3 = 0;





//declare functions
void cpptest();
void init();
void cppmaintask_1(void *pvParameters);
void cppmaintask_2(void *pvParameters);
void Settings();
void Mainscreen();
void Highscores();
void Playing();
int getSpriteNrByString(char j);
void draw();
void SendviaSPI(Object obj);

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

void init()
{

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

void draw()
{
	for(int i = 0;i<MainGame.amountCurrentObjects;i++)
	{
		if(MainGame.ObjActive[i] == true)
		{
			SendviaSPI(MainGame.CurrentObjects[i]);
		}
	}
}

void Mainscreen()
{
	int mainscreen = 1;
	MainGame.setObj(Object(260,50,getSpriteNrByString('j'),20,20));
	MainGame.setObj(Object(280,50,getSpriteNrByString('e'),20,20));
	MainGame.setObj(Object(300,50,getSpriteNrByString('t'),20,20));
	MainGame.setObj(Object(320,50,getSpriteNrByString('p'),20,20));
	MainGame.setObj(Object(340,50,getSpriteNrByString('a'),20,20));
	MainGame.setObj(Object(360,50,getSpriteNrByString('c'),20,20));
	MainGame.setObj(Object(380,50,getSpriteNrByString('k'),20,20));
	int selected = 1;
	while(mainscreen == 1)
	{
		draw();
		ssd1306_UpdateScreen();
		ssd1306_Fill(Black);
		switch (selected) {
			case 1:
				if(statebutton1 == false)
				{
				    ssd1306_SetCursor(20,0);
				    ssd1306_WriteString("test1", Font_7x10, White);
				    selected = 2;
				}
				break;
			case 2:
				if(statebutton2 == false)
				{
				    ssd1306_SetCursor(20,0);
				    ssd1306_WriteString("test2", Font_7x10, White);
				    selected = 3;
				}
				break;
			case 3:
				if(statebutton3 == false)
				{
				    ssd1306_SetCursor(20,0);
				    ssd1306_WriteString("test3", Font_7x10, White);
				    selected = 1;
				}
				break;
			default:
				break;
		}

	}
}
void Highscores()
{
	int highscores = 1;
	while(highscores == 1)
	{
		cpptest();
	}
}
void Playing()
{
	int playing = 1;
	while(playing == 1)
	{
		cpptest();
	}
}

void Settings()
{
	int settings = 1;
	while(settings == 1)
	{
		cpptest();
	}
}

void SendviaSPI(Object obj)
{

}

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

