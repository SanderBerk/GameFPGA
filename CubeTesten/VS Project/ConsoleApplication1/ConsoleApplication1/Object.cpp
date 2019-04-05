#include "Object.h"


Object::Object(uint16_t xpos, uint16_t ypos, uint8_t nr, uint8_t Xlen, uint8_t Ylen)
{
	this->LposX = xpos;
	this->LposY = ypos;
	this->Radius = (Xlen + Ylen) / 4;
	this->Xlength = Xlen;//X length
	this->Ylength = Ylen;//Y length
	this->spritenr = nr;
	this->UniqueIDWhenactive = 0;
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

uint16_t Object::getSpritenr()
{
	return this->spritenr;
}

uint16_t Object::getMiddleX()
{
	return (LposX + Xlength) / 4;
}

uint16_t Object::getMiddleY()
{
	return (LposY + Ylength) / 4;;
}

void Object::setNext(Object * n)
{
	this->Next = n;
}

Object * Object::getNext()
{
	return this->Next;
}

void Object::setPrev(Object * p)
{
	this->Prev = p;
}

Object * Object::getPrev()
{
	return this->Prev;
}
