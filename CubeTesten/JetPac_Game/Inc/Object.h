/*
 * Object.h
 *
 *  Created on: Feb 22, 2019
 *      Author: Rinke
 */

#include "Sprite.h"
#include <stdint.h>

#ifndef OBJECT_H_
#define OBJECT_H_

class Object
{
public:
	Object();
	Object(uint16_t xpos, uint16_t ypos,uint8_t spritenr,uint8_t Xlen,uint8_t Ylen);
	~Object();
	void changeLposX(uint16_t);
	void changeLposY(uint16_t);
	uint16_t getLposX();
	uint16_t getLposY();
	uint8_t getSpritenr();

private:
	uint8_t spritenr = 0;
	uint8_t X = 0;//X length
	uint8_t Y = 0;//Y length
	uint16_t LposX = 0;
	uint16_t LposY = 0;
	uint8_t Radius = 0;
	uint16_t Middle_X = 0;
	uint16_t Middle_Y = 0;
};



#endif /* OBJECT_H_ */
