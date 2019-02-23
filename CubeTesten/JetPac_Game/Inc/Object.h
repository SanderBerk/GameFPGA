/*
 * Object.h
 *
 *  Created on: Feb 22, 2019
 *      Author: Rinke
 */

#include "Sprite.h"

#ifndef OBJECT_H_
#define OBJECT_H_

class Object
{
public:
	Object();
	Object(int,int,Sprite);
	~Object();
	void changeLposX(int);
	void changeLposY(int);
	int getLposX();
	int getLposY();
	Sprite WhatSpriteareyou();
	int objnr = 0;

private:

	Sprite sprite;
	int LposX = 0;
	int LposY = 0;
	int Radius = 0;
	int Middle_X = 0;
	int Middle_Y = 0;

};



#endif /* OBJECT_H_ */
