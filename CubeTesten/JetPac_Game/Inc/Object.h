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
	Object(uint16_t xpos, uint16_t ypos, uint8_t spritenr, uint8_t Xlen, uint8_t Ylen);
	~Object();
	void changeLposX(uint16_t);
	void changeLposY(uint16_t);
	uint16_t getLposX();
	uint16_t getLposY();
	uint8_t getSpritenr();
	uint16_t getMiddleX();
	uint16_t getMiddleY();
	void setNext(Object *);
	Object * getNext();
	void setPrev(Object *);
	Object * getPrev();

private:
	uint16_t UniqueIDWhenactive = 0;
	Object * Next = nullptr;
	Object * Prev = nullptr;
	uint16_t spritenr = 0;
	uint16_t Xlength = 0;//X length
	uint16_t Ylength = 0;//Y length
	uint16_t LposX = 0;
	uint16_t LposY = 0;
	uint16_t Radius = 0;

	friend class Game;
};



#endif /* OBJECT_H_ */
