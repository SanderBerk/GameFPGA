// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdint.h>
#include "Game.h"
#include "Object.h"
#include "Sprite.h"

#include "pch.h"
#include <iostream>

#include <stdio.h>
#include <string>
#include "Sprite.h"
#include "Game.h"
#include "Highscore.h"
#include <stdlib.h>
#include "Object.h"
#include <stdint.h>
#include <vector>

//declare global variables
Game MainGame = Game(640, 420);


int main()
{
	//Game game = Game(640,480);
	
	Object obj1 = Object(0, 0, 10, 20, 20);
	Object obj2 = Object(0, 0, 11, 20, 20);
	Object obj3 = Object(0, 0, 12, 20, 20);
	Object obj4 = Object(0, 0, 13, 20, 20);
	int obj11 = MainGame.addObject(&obj1);
	int obj22 = MainGame.addObject(&obj2);
	int obj33 = MainGame.addObject(&obj3);
	int obj44 = MainGame.addObject(&obj4);

	MainGame.showall();
	std::cout << MainGame.ChangePosObjbyUniNr(obj11, 100, 100) << std::endl;
	MainGame.removeObjectUni(obj11);
	MainGame.removeObjectUni(obj44);
	MainGame.showall();

	MainGame.clearObjects();

	MainGame.showall();

    //std::cout << "Hello World!\n"; 
	return 1;
}


