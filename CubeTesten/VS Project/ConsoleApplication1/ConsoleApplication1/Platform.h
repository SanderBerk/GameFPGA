#pragma once
#include "Object.h"
class Platform : public Object
{
public: //Object();
	Platform(uint16_t xpos, uint16_t ypos, uint8_t spritenr, uint8_t Xlen, uint8_t Ylen):Object(xpos, ypos, spritenr, Xlen, Ylen) 
	{
		XCircle_Left = xpos + 5;
		XCircle_Right = xpos + Xlen - 5;

		YCircle_Left = ypos + 5;
		YCircle_Right = ypos + Ylen - 5;
	};
	virtual ~Platform();

	bool CheckCollision(uint16_t Xpos, uint16_t Ypos, uint8_t radius);

private:
	uint16_t XCircle_Left;
	uint16_t YCircle_Left;
	uint16_t XCircle_Right;
	uint16_t YCircle_Right;

	

	friend class Game;
	friend class Object;

};

