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
#include "ExtraFunctions.h"

//declare global variables
Game MainGame = Game(640,420);
bool statebutton1 = 0;
bool statebutton2 = 0;
bool statebutton3 = 0;
int debug =0;




//declare functions

void cppmaintask_1(void *pvParameters);
void cppmaintask_2(void *pvParameters);
void Settings();
void Mainscreen();
void Highscores();
void Playing();
void draw();
void SendviaSPI(Object obj);
void drawssd1306();






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

		if(debug ==1)
		{
			ssd1306_SetCursor(50,0);
			if(statebutton1 == true) ssd1306_WriteString("1", Font_7x10, White);
			if(statebutton1 == false) ssd1306_WriteString("0", Font_7x10, White);

			ssd1306_SetCursor(50,10);
			if(statebutton2 == true) ssd1306_WriteString("1", Font_7x10, White);
			if(statebutton2 == false) ssd1306_WriteString("0", Font_7x10, White);

			ssd1306_SetCursor(50,20);
			if(statebutton3 == true) ssd1306_WriteString("1", Font_7x10, White);
			if(statebutton3 == false) ssd1306_WriteString("0", Font_7x10, White);
		}

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

void drawssd1306()
{

}

void Mainscreen()
{
	int mainscreen = 1;
	MainGame.setObj(Object(260,80,getSpriteNrByString('j'),20,20));
	MainGame.setObj(Object(280,80,getSpriteNrByString('e'),20,20));
	MainGame.setObj(Object(300,80,getSpriteNrByString('t'),20,20));
	MainGame.setObj(Object(320,80,getSpriteNrByString('p'),20,20));
	MainGame.setObj(Object(340,80,getSpriteNrByString('a'),20,20));
	MainGame.setObj(Object(360,80,getSpriteNrByString('c'),20,20));
	MainGame.setObj(Object(380,80,getSpriteNrByString('k'),20,20));

	MainGame.setObj(Object(280,180,getSpriteNrByString('p'),20,20));
	MainGame.setObj(Object(300,180,getSpriteNrByString('l'),20,20));
	MainGame.setObj(Object(320,180,getSpriteNrByString('a'),20,20));
	MainGame.setObj(Object(340,180,getSpriteNrByString('y'),20,20));

	MainGame.setObj(Object(220,280,getSpriteNrByString('h'),20,20));
	MainGame.setObj(Object(240,280,getSpriteNrByString('i'),20,20));
	MainGame.setObj(Object(260,280,getSpriteNrByString('g'),20,20));
	MainGame.setObj(Object(280,280,getSpriteNrByString('h'),20,20));
	MainGame.setObj(Object(300,280,getSpriteNrByString('s'),20,20));
	MainGame.setObj(Object(320,280,getSpriteNrByString('c'),20,20));
	MainGame.setObj(Object(340,280,getSpriteNrByString('o'),20,20));
	MainGame.setObj(Object(360,280,getSpriteNrByString('r'),20,20));
	MainGame.setObj(Object(380,280,getSpriteNrByString('e'),20,20));

	MainGame.setObj(Object(240,380,getSpriteNrByString('s'),20,20));
	MainGame.setObj(Object(260,380,getSpriteNrByString('e'),20,20));
	MainGame.setObj(Object(280,380,getSpriteNrByString('t'),20,20));
	MainGame.setObj(Object(300,380,getSpriteNrByString('t'),20,20));
	MainGame.setObj(Object(320,380,getSpriteNrByString('i'),20,20));
	MainGame.setObj(Object(340,380,getSpriteNrByString('n'),20,20));
	MainGame.setObj(Object(360,380,getSpriteNrByString('g'),20,20));
	MainGame.setObj(Object(380,380,getSpriteNrByString('s'),20,20));

	MainGame.setObj(Object(420,80,6,20,20));//pijltje

	int selected = 1;

	while(mainscreen == 1)
	{
		//draw();
		ssd1306_UpdateScreen();
		ssd1306_Fill(Black);
		//cpptest();
	    ssd1306_SetCursor(0,0);
	    ssd1306_WriteString("Play", Font_7x10, White);
	    ssd1306_SetCursor(0,10);
	    ssd1306_WriteString("Highscores", Font_7x10, White);
	    ssd1306_SetCursor(0,20);
	    ssd1306_WriteString("Settings", Font_7x10, White);
			switch (selected) {
						case 1:
						    ssd1306_SetCursor(80,0);
						    ssd1306_WriteString("<-", Font_7x10, White);
							if(statebutton1 == false)
							{
								while(statebutton1 == false){ManualCheck();}
								selected = 2;
							}
							if(statebutton2 == false)
							{
								while(statebutton2 == false){ManualCheck();}
								mainscreen = 0;
								MainGame.GameState = MainGame.PLAYING;
							}
							break;
						case 2:
						    ssd1306_SetCursor(80,10);
						    ssd1306_WriteString("<-", Font_7x10, White);
							if(statebutton1 == false)
							{
								while(statebutton1 == false){ManualCheck();}
							    selected = 3;
							}
							break;
						case 3:
						    ssd1306_SetCursor(80,20);
						    ssd1306_WriteString("<-", Font_7x10, White);
							if(statebutton1 == false)
							{
								while(statebutton1 == false){ManualCheck();}
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

	}
}
void Playing()
{
	int playing = 1;
	while(playing == 1)
	{
		ssd1306_UpdateScreen();
		ssd1306_Fill(Black);
	    ssd1306_SetCursor(0,0);
	    ssd1306_WriteString("Playing", Font_7x10, White);
	}
}

void Settings()
{
	int settings = 1;
	while(settings == 1)
	{

	}
}

void SendviaSPI(Object obj)
{

}



