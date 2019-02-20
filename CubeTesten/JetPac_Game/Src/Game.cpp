#include "Game.h"

#ifdef __cplusplus
extern "C"
{
#endif


Game::Game()
{
}


Game::~Game()
{
}

void Game::setResolution(int x, int y)
{
	this->resolution_X = x;
	this->resolution_Y = y;
}

void Game::ChangeState(States)
{
}


Sprite Game::getSprite(int i)
{
	return Sprites_Array[i];
}

void Game::addSprite(Sprite a)
{
	Sprites_Array[SpriteArraySize++] = a;
}

Highscore Game::getHighScore(int i)
{
	return this->Highscores[i];
}

void Game::SetHighScore(Highscore h)
{

	this->Highscores[5] = h;
}


#ifdef __cplusplus
}
#endif
