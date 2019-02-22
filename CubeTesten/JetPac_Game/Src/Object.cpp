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

Object::Object(int x, int y, Sprite j)
{
	this->LposX = x;
	this->LposY = y;
	this->sprite = j;
	this->Radius = (j.spriteSizeX + j.spriteSizeY) / 4;
	this->Middle_X = x + (j.spriteSizeX /2);
	this->Middle_Y = y + (j.spriteSizeY / 2);
}


Object::~Object()
{
}

void Object::changeLposX(int x)
{
	this->LposX = x;
}

void Object::changeLposY(int y)
{
	this->LposY = y;
}

Sprite Object::WhatSpriteareyou()
{
	return this->sprite;
}
