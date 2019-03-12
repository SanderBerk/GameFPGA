#include "pch.h"
#include "Sprite.h"

Sprite::Sprite()
{
}

Sprite::Sprite(uint8_t x, uint8_t y, uint8_t id)
{
	this->spriteSizeX = x;
	this->spriteSizeY = y;
	this->spriteNr = id;
}


Sprite::~Sprite()
{
}

uint8_t Sprite::getSpriteNr()
{
	return this->spriteNr;
}

uint8_t Sprite::getSize_X()
{
	return this->spriteSizeX;
}

uint8_t Sprite::getSize_Y()
{
	return this->spriteSizeY;
}