/*
 * Sprite.cpp
 *
 *  Created on: Feb 19, 2019
 *      Author: Rinke
 */

#include "Sprite.h"

#ifdef __cplusplus
extern "C"
{
#endif

Sprite::Sprite()
{
}

Sprite::Sprite(int x, int y, int id)
{
	this->spriteSizeX = x;
	this->spriteSizeY = y;
	this->spriteNr = id;
}


Sprite::~Sprite()
{
}

int Sprite::getSpriteNr()
{
	return this->spriteNr;
}

int Sprite::getSize_X()
{
	return this->spriteSizeX;
}

int Sprite::getSize_Y()
{
	return this->spriteSizeY;
}

#ifdef __cplusplus
}
#endif
