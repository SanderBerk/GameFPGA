/*
 * Sprite.h
 *
 *  Created on: Feb 19, 2019
 *      Author: Rinke
 */

#include <stdint.h>

#ifndef SPRITE_H_
#define SPRITE_H_

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
	int	spriteNr : 6;
	int spriteSizeX : 5;
	int spriteSizeY : 5;

	friend class Game;
	friend class Object;
};





#endif /* SPRITE_H_ */
