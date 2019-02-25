#include "Game.h"

#ifdef __cplusplus
extern "C"
{
#endif


Game::Game(uint16_t x, uint16_t y)
{
	this->resolution_X = x;
	this->resolution_Y = y;

}


Game::~Game()
{
}


Sprite Game::getSprite(uint8_t i)
{
	return Sprites_Array[i];
}

Highscore Game::getHighScore(int i)
{
	return this->Highscores[i];
}

void Game::SetHighScore(Highscore h)
{

	this->Highscores[5] = h;
}

void Game::setObj(Object obj)
{
	ObjActive[amountCurrentObjects] = true;
	CurrentObjects[amountCurrentObjects++] = obj;

}


void Game::RemObj(uint8_t spritenr)
{
	for(int i =0;i<amountCurrentObjects;i++)
	{
		if(CurrentObjects[i].getSpritenr() == spritenr)
		{
			ObjActive[i] = false;
		}
	}
}


#ifdef __cplusplus
}
#endif
