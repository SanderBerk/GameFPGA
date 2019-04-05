
#pragma once
#include <stdint.h>
#include "Sprite.h"


class Object
{
public:
	Object(uint16_t xpos, uint16_t ypos, uint8_t spritenr, uint8_t Xlen, uint8_t Ylen);
	virtual ~Object();
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

public:
	uint8_t UniqueIDWhenactive = 0;
	Object * Next = nullptr;
	Object * Prev = nullptr;
	uint8_t spritenr = 0;
	uint16_t Xlength = 0;//X length
	uint16_t Ylength = 0;//Y length
	uint16_t LposX = 0;
	uint16_t LposY = 0;
	uint16_t Radius = 0;
	uint8_t speed = 0;
	uint8_t gravity = 0;

	friend class Game;
	friend class Platform;
};

