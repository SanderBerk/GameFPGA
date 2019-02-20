//Credits naar Marlon
#include <stdio.h>
#include <string>
#include "Sprite.h"
#include "tasks.h" //Zie dit bestand voor extern "C" voorbeeld.
#include "cmsis_os.h"
#include "Game.h"
#include "ssd1306.h"
#include "fonts.h"
#include "Highscore.h"


//declare global variables
Game MainGame;
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
    ssd1306_SetCursor(0,0);
    ssd1306_WriteString("test", Font_7x10, White);
    vTaskDelay(1000);
}

void init()
{
	ssd1306_Init();
	init();
	cpptest();
	MainGame.setResolution(640,420);
	Addsprites();

}

void cppmaintask_1(void *pvParameters)
{

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

	}
}

void Addsprites()
{

}

void Settings()
{

}
void Mainscreen()
{

}
void Highscores()
{

}
void Playing()
{

}

