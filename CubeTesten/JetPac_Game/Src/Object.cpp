/*
 * Object.cpp
 *
 *  Created on: Feb 22, 2019
 *      Author: Rinke
 */


#include "Object.h"

Object::Object()
{
}

Object::Object(uint16_t xpos, uint16_t ypos,uint8_t spritenr,uint8_t Xlen,uint8_t Ylen)
{
	this->LposX = xpos;
	this->LposY = ypos;
	this->Radius = Xlen + Ylen / 4;
	this->Middle_X = (xpos + Xlen) /2;
	this->Middle_Y = (ypos + Ylen) / 2;
}


Object::~Object()
{
}

void Object::changeLposX(uint16_t x)
{
	this->LposX = x;
}

void Object::changeLposY(uint16_t y)
{
	this->LposY = y;
}

uint16_t Object::getLposY()
{
	return this->LposY;
}

uint16_t Object::getLposX()
{
	return this->LposX;
}

uint8_t Object::getSpritenr()
{
	return this->spritenr;
}
