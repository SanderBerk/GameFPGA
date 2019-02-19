/*
 * Sprite.h
 *
 *  Created on: Feb 19, 2019
 *      Author: Rinke
 */

#ifndef SPRITE_H_
#define SPRITE_H_

class Sprite
{
public:
	Sprite();
	Sprite(int,int,int);
	virtual ~Sprite();
	int getSpriteNr();
	int getSize_X();
	int getSize_Y();

private:
	int	spriteNr;
	int spriteSizeX;
	int spriteSizeY;

};





#endif /* SPRITE_H_ */
