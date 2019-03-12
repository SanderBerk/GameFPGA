#pragma once
#include <stdint.h>

class Sprite
{
public:
	Sprite();
	Sprite(uint8_t, uint8_t, uint8_t);
	virtual ~Sprite();
	uint8_t getSpriteNr();
	uint8_t getSize_X();
	uint8_t getSize_Y();

private:
	uint8_t	spriteNr;
	uint8_t spriteSizeX;
	uint8_t spriteSizeY;

	friend class Game;
	friend class Object;
};

