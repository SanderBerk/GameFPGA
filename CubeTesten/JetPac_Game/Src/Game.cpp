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

void Game::setResolution(int, int)
{
}

void Game::ChangeState(AvailableStates)
{
}


int Game::getSprite_X(int)
{
	return 0;
}

int Game::getSpriteY(int)
{
	return 0;
}

char * Game::getHighScore(int)
{
	return nullptr;
}

void Game::SetHighScore(int, char, char, char)
{
}


#ifdef __cplusplus
}
#endif
