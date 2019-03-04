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
bool debug = false;
bool ssd_ = true;



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
	if(ssd_ == 1)ssd1306_Init();
	MainGame.GameState = MainGame.INIT;
	for(;;)
	{
		switch (MainGame.GameState) {
			case MainGame.INIT:
				Init();
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

		if(debug ==1 && ssd_ == 1)
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





void Mainscreen()
{
	int mainscreen = 1;
	MainGame.clearObjects();
	Object temp = Object(260,80,getSpriteNrByString('j'),20,20);
	MainGame.addObject(&temp);
	temp = Object(280,80,getSpriteNrByString('e'),20,20);
	MainGame.addObject(&temp);
	temp = Object(300,80,getSpriteNrByString('t'),20,20);
	MainGame.addObject(&temp);
	temp = Object(320,80,getSpriteNrByString('p'),20,20);
	MainGame.addObject(&temp);
	temp = Object(340,80,getSpriteNrByString('a'),20,20);
	MainGame.addObject(&temp);
	temp = Object(360,80,getSpriteNrByString('c'),20,20);
	MainGame.addObject(&temp);
	temp = Object(380,80,getSpriteNrByString('k'),20,20);
	MainGame.addObject(&temp);

	temp = Object(280,180,getSpriteNrByString('p'),20,20);
	MainGame.addObject(&temp);
	temp = Object(300,180,getSpriteNrByString('l'),20,20);
	MainGame.addObject(&temp);
	temp = Object(320,180,getSpriteNrByString('a'),20,20);
	MainGame.addObject(&temp);
	temp = Object(340,180,getSpriteNrByString('y'),20,20);
	MainGame.addObject(&temp);
	temp = Object(220,280,getSpriteNrByString('h'),20,20);
	MainGame.addObject(&temp);
	temp = Object(240,280,getSpriteNrByString('i'),20,20);
	MainGame.addObject(&temp);
	temp = Object(260,280,getSpriteNrByString('g'),20,20);
	MainGame.addObject(&temp);
	temp = Object(280,280,getSpriteNrByString('h'),20,20);
	MainGame.addObject(&temp);
	temp = Object(300,280,getSpriteNrByString('s'),20,20);
	MainGame.addObject(&temp);
	temp = Object(320,280,getSpriteNrByString('c'),20,20);
	MainGame.addObject(&temp);
	temp = Object(340,280,getSpriteNrByString('o'),20,20);
	MainGame.addObject(&temp);
	temp = Object(360,280,getSpriteNrByString('r'),20,20);
	MainGame.addObject(&temp);
	temp = Object(380,280,getSpriteNrByString('e'),20,20);
	MainGame.addObject(&temp);

	temp = Object(240,380,getSpriteNrByString('s'),20,20);
	MainGame.addObject(&temp);
	temp = Object(260,380,getSpriteNrByString('e'),20,20);
	MainGame.addObject(&temp);
	temp = Object(280,380,getSpriteNrByString('t'),20,20);
	MainGame.addObject(&temp);
	temp = Object(300,380,getSpriteNrByString('t'),20,20);
	MainGame.addObject(&temp);
	temp = Object(320,380,getSpriteNrByString('i'),20,20);
	MainGame.addObject(&temp);
	temp = Object(340,380,getSpriteNrByString('n'),20,20);
	MainGame.addObject(&temp);
	temp = Object(360,380,getSpriteNrByString('g'),20,20);
	MainGame.addObject(&temp);
	temp = Object(380,380,getSpriteNrByString('s'),20,20);
	MainGame.addObject(&temp);
	temp = Object(420,180,6,20,20);//pijltje
	int arrow = MainGame.addObject(&temp);


	//draw();

	int selected = 1;

	while(mainscreen == 1)
	{
		ManualCheck();
		//draw();
		if(ssd_ == 1)
		{
			ssd1306_UpdateScreen();
			ssd1306_Fill(Black);
			ssd1306_SetCursor(0,0);
			ssd1306_WriteString("Play", Font_7x10, White);
			ssd1306_SetCursor(0,10);
			ssd1306_WriteString("Highscores", Font_7x10, White);
			ssd1306_SetCursor(0,20);
			ssd1306_WriteString("Settings", Font_7x10, White);
		}
			switch (selected) {
						case 1:
							if(ssd_ == 1)ssd1306_SetCursor(80,0);
							if(ssd_ == 1)ssd1306_WriteString("<-", Font_7x10, White);
							MainGame.ChangePosObjbyUniNr(arrow,420,180);
							if(statebutton1 == false)
							{
								while(statebutton1 == false){ManualCheck();}
								selected = 2;
							}
							if(statebutton2 == false)
							{
								while(statebutton2 == false){ManualCheck();}
								mainscreen = 0;
								MainGame.clearObjects();
								MainGame.GameState = MainGame.PLAYING;
							}
							break;
						case 2:
							if(ssd_ == 1)ssd1306_SetCursor(80,10);
							if(ssd_ == 1)ssd1306_WriteString("<-", Font_7x10, White);
							MainGame.ChangePosObjbyUniNr(arrow,420,280);
							if(statebutton1 == false)
							{
								while(statebutton1 == false){ManualCheck();}
							    selected = 3;
							}
							if(statebutton2 == false)
							{
								while(statebutton2 == false){ManualCheck();}
								mainscreen = 0;
								MainGame.clearObjects();
								MainGame.GameState = MainGame.HIGHSCORES;
							}
							break;
						case 3:
							if(ssd_ == 1)ssd1306_SetCursor(80,20);
							if(ssd_ == 1)ssd1306_WriteString("<-", Font_7x10, White);
							MainGame.ChangePosObjbyUniNr(arrow,420,380);
							if(statebutton1 == false)
							{
								while(statebutton1 == false){ManualCheck();}
							    selected = 1;
							}
							if(statebutton2 == false)
							{
								while(statebutton2 == false){ManualCheck();}
								mainscreen = 0;
								MainGame.clearObjects();
								MainGame.GameState = MainGame.SETTINGS;
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
	MainGame.clearObjects();
	Object pacmanobj = Object(0,0,1,5,5);
	int pacman = MainGame.addObject(&pacmanobj);

	Object lineobj = Object(30,0,1,2,2);
	int line = MainGame.addObject(&lineobj);

	Object lineobj1 = Object(40,2,1,2,2);
	int line1 = MainGame.addObject(&lineobj1);

	Object lineobj2 = Object(40,4,1,2,2);
	int line2 = MainGame.addObject(&lineobj2);

	Object lineobj3 = Object(40,6,1,2,2);
	int line3 = MainGame.addObject(&lineobj3);

	while(playing == 1)
	{
		ssd1306_Fill(Black);
		int y = 40;
		int x= 0;
		int speed = 5;
		int up = 1;
		int orginal = 43;
		x = orginal;
		while(1)
		{
			ManualCheck();
		    if((x - orginal) > 18 && up == 1) speed = 4;
		    if((x - orginal) > 25 && up == 1) speed = 3;
		    if((x - orginal) > 35 && up == 1) speed = 2;
		    if((x - orginal) > 45 && up == 1) speed = 1;
		    if((x - orginal) > 50)
		    {
		    	up = 0;
		    	speed =6;
		    }
		    if((x - orginal) > 50 && up == 0) speed = -1;
		    if((x - orginal) < 45 && up == 0) speed = -2;
		    if((x - orginal) < 42 && up == 0) speed = -3;
		    if((x - orginal) < 35 && up == 0) speed = -4;
		    if((x - orginal) < 25 && up == 0) speed = -6;

		    if(speed >0)
		    {
		    	for(int i = 0;i<speed;i++)
		    	{
		    		x++;
		    	}

			    if(MainGame.checkColl(pacman,line,line1,line2,line3) == 1)
			    {
			    	orginal = MainGame.getObjX(line);
			    }
			    if(x < orginal)
			    {
			    	up = 1;
			    	speed = 6;
			    }
		    }
		    else if(speed <0)
		    {
		    	int speed2 = speed * -1;
		    	for(int i = 0;i<speed2;i++)
		    	{
		    		x--;

		    	}
			    if(MainGame.checkColl(pacman,line,line1,line2,line3) == 1)
			    {
			    	orginal = MainGame.getObjX(line);
			    }

			    if(x < orginal)
			    {
			    	up = 1;
			    	speed = 6;
			    }
		    }





		    if(statebutton1 == true)
		    {
		    	if(y < 120)y++;

		    }
		    if(statebutton2 == true)
		    {
		    	if(y > 0)y--;
		    }



		    MainGame.clearssd1306();
		    MainGame.ChangePosObjbyUniNr(line,y,0);
		    MainGame.ChangePosObjbyUniNr(pacman,x,0);
		    MainGame.drawssd1306();


		}
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



