#include "Platform.h"
#include <iostream>


Platform::~Platform()
{
}

bool Platform::CheckCollision(uint16_t Xpos, uint16_t Ypos, uint8_t radius)
{
	int arraypoints[103][2];
	
	
	for (int i = 0; i <= 40; i++)
	{
		arraypoints[i][0] = Xpos + i;
		arraypoints[i][1] = Ypos;

		arraypoints[i + 41][0] = Xpos + i;
		arraypoints[i + 41][1] = Ypos + Ylength;
	}
	for (int i = 40; i <= 50; i++)
	{
		arraypoints[i + 42][0] = Xpos;
		arraypoints[i + 42][1] = Ypos + i - 40;

		arraypoints[i + 53][0] = Xpos + Xlength;
		arraypoints[i + 53][1] = Ypos + i - 40;
	}


	for (int i = 0; i <= 103; i++)
	{
		std::cout << "X: " << arraypoints[i][0] << " " << "Y: " << arraypoints[i][1] << std::endl;
	}

	
	return false;
}
