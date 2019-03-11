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
	Object(int xpos, int ypos, int nr, int Xlen, int Ylen);
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
	int UniqueIDWhenactive : 6;
	Object * Next = nullptr;
	Object * Prev = nullptr;
	int spritenr : 7;
	int Xlength : 5;//X length
	int Ylength : 5;//Y length
	int LposX : 10;
	int LposY : 9;
	int Radius : 5;

	friend class Game;
};



#endif /* OBJECT_H_ */
