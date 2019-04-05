// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdint.h>
#include "Game.h"
#include "Object.h"
#include "Platform.h"

#include "Sprite.h"

#include "pch.h"
#include <iostream>

#include <string>
#include "Sprite.h"
#include "Game.h"
#include "Highscore.h"

#include <vector>
#include <Windows.h>
#include <windef.h>


//declare global variables
Game MainGame = Game(640, 420);


int main()
{
	//Game game = Game(640,480);
	
	Object obj1 = Object(0, 0, 10, 20, 20);
	Platform obj2 = Platform(0, 0, 11, 40, 10);
	int obj11 = MainGame.addObject(&obj1);
	int obj22 = MainGame.addObject(&obj2);

	MainGame.showall();
	std::cout << MainGame.ChangePosObjbyUniNr(obj11, 20, 20) << std::endl;
	std::cout << MainGame.ChangePosObjbyUniNr(obj22, 40, 40) << std::endl;
	MainGame.showall();

	std::cout << obj1.Radius << std::endl;
	std::cout << obj2.Radius << std::endl;

	std::cout << "Middle Obj1 X" << obj1.getLposX() + obj1.Radius << std::endl;
	std::cout << "Middle Obj1 Y" << obj1.getLposY() + obj1.Radius << std::endl;


	std::cout << "Middle Obj2 X" << obj2.getLposX() + obj2.Radius << std::endl;
	std::cout << "Middle Obj2 Y" << obj2.getLposY() + obj2.Radius << std::endl;

	std::cout << obj2.CheckCollision(obj1.getLposX(), obj1.getLposY(), obj1.Radius) << std::endl;
	//for (int i = 0; i < 100; i++)
	//{
		//int XDistance = ((obj1.LposX + obj1.Radius) - (obj2.LposX + obj2.Radius));
		//if (XDistance < 0) XDistance *= -1;
		//std::cout << "XDistance between objects: " << XDistance << std::endl;

		//int YDistance = ((obj1.LposY + obj1.Radius) - (obj2.LposY + obj2.Radius));
		//if (YDistance < 0) YDistance *= -1;
		//std::cout << "YDistance between objects: " << YDistance << std::endl;

		//double Line = (XDistance * XDistance) + (YDistance * YDistance);
		//Line = sqrt(Line);

		//std::cout << "Line between objects: " << Line << std::endl;
	//
		//std::cout << MainGame.ChangePosObjbyUniNr(obj11, 20 + i, 20 + i) << std::endl;
		//std::cout << MainGame.ChangePosObjbyUniNr(obj22, 40 - i, 40 - i) << std::endl;
		//if (Line == 0) i = 101;
	//}


	

	MainGame.clearObjects();

	MainGame.showall();

    //std::cout << "Hello World!\n"; 
	return 1;
}


