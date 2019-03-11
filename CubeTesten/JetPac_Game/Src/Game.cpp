#include "Game.h"
#include "ssd1306.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif


char getCharbySpritenr(int j);

Game::Game(uint16_t x, uint16_t y)
{
	this->resolution_X = x;
	this->resolution_Y = y;

}


Game::~Game()
{
}


Sprite Game::getSprite(uint8_t i)
{
	return Sprites_Array[i];
}

Highscore Game::getHighScore(int i)
{
	return this->Highscores[i];
}

void Game::SetHighScore(Highscore h)
{

	this->Highscores[5] = h;
}

uint8_t Game::addObject(Object * obj)
{
	if (First == nullptr && Last == nullptr)
	{
		Object * temp = obj;
		First = temp;
		Last = temp;
		Last->UniqueIDWhenactive = amountCurrentSprites++;
		Last->Next = nullptr;
		Last->Prev = nullptr;
		return Last->UniqueIDWhenactive;
	}
	else
	{
		Object * temp = obj;
		Last->Next = temp;
		temp->Prev = Last;
		Last = temp;
		Last->UniqueIDWhenactive = amountCurrentSprites++;
		return Last->UniqueIDWhenactive;
	}
	return -1;

}

void Game::removeObjectUni(uint8_t UniqueNr)
{
	Object * temp = First;
	while (temp != nullptr)
	{
		if (temp->UniqueIDWhenactive == UniqueNr)
		{
			if (temp->Next != nullptr)
			{
				temp->Next->setPrev(temp->Prev);
			}
			else
			{
				Last = Last->Prev;
				Last->Next = nullptr;
			}
			if (temp->Prev != nullptr)
			{
				temp->Prev->setNext(temp->Next);
			}
			else
			{
				First = First->Next;
				First->Prev = nullptr;
			}

		}
		temp = temp->Next;
	}
}

bool Game::changeSpriteNr(int Uninr,int sprtnr)
{
	Object * temp = First;
	while (temp != nullptr)
	{
		if (temp->UniqueIDWhenactive == Uninr)
		{
			temp->spritenr = sprtnr;
			return true;
		}
		temp = temp->Next;
	}
	return false;
}

int Game::ChangePosObjbyUniNr(uint8_t Uninr, uint16_t x, uint16_t y)
{
	Object * temp = First;
	while (temp != nullptr)
	{
		if (temp->UniqueIDWhenactive == Uninr)
		{
			temp->changeLposX(x);
			temp->changeLposY(y);
			return 1;
		}
		temp = temp->Next;
	}
	return -1;
}

int Game::getObjX(uint8_t uninr)
{
	Object * temp = First;
	while (temp != nullptr)
	{
		if (temp->UniqueIDWhenactive == uninr)
		{
			return temp->LposX;
		}
		temp = temp->Next;
	}
	return -1;
}
int Game::getObjY(uint8_t uninr)
{
	Object * temp = First;
	while (temp != nullptr)
	{
		if (temp->UniqueIDWhenactive == uninr)
		{
			return temp->LposY;
		}
		temp = temp->Next;
	}
	return -1;
}


int Game::checkColl(uint8_t uninr, uint8_t line1, uint8_t line2, uint8_t line3, uint8_t line4)
{
	Object * temp = First;
	Object * pacman;
	Object * line11;
	Object * line21;
	Object * line31;
	Object * line41;
	while (temp != nullptr)
	{
		if (temp->UniqueIDWhenactive == uninr)pacman = temp;
		if (temp->UniqueIDWhenactive == line1)line11 = temp;
		if (temp->UniqueIDWhenactive == line2)line21 = temp;
		if (temp->UniqueIDWhenactive == line3)line31 = temp;
		if (temp->UniqueIDWhenactive == line4)line41 = temp;
		temp = temp->Next;
	}

	if(pacman != nullptr && line11 != nullptr && line21 != nullptr && line31 != nullptr && line41 != nullptr)
	{
		if((pacman->LposY - pacman->Radius) - (line11->LposY + line11->Radius) > -4 && (pacman->LposY - pacman->Radius) - (line11->LposY + line11->Radius) < 0)
		{
			return 1;
		}
	}
	else
	{
		return -1;
	}


}

/*
void Game::showall()
{
	Object * temp = First;
	while (temp != nullptr)
	{
		std::cout << "X pos: " << temp->LposX << " Y pos: " << temp->LposY << " UniNr: " << temp->UniqueIDWhenactive << " SprNr: " << temp->spritenr << std::endl;
		temp = temp->Next;
	}
}
*/


void Game::draw()
{

}

void Game::drawssd1306()
{
	Object * temp = this->First;
	while (temp != nullptr)
	{

		if(temp->spritenr > 6)
		{
			uint8_t t = temp->spritenr;
			char tempa = getCharbySpritenr(t);
			ssd1306_SetCursor(temp->LposX+temp->Xlength,temp->LposY);
			ssd1306_WriteChar(tempa, Font_7x10, White);
		}
		else
		{
			for(int i = 0;i<temp->Xlength;i++)
			{
				for(int j = 0;j<temp->Ylength;j++)
				{
						ssd1306_DrawPixel(temp->LposX+i, temp->LposY+j, White);
				}

			}
		}
		temp = temp->Next;
	}

}

void Game::clearssd1306()
{
	ssd1306_UpdateScreen();
	Object * temp = this->First;
	while (temp != nullptr)
	{
		for(int i = 0;i<temp->Xlength;i++)
		{
			for(int j = 0;j<temp->Ylength;j++)
			{
					ssd1306_DrawPixel(temp->LposX+i, temp->LposY+j, Black);
			}

		}
		temp = temp->Next;
	}

}

void Game::clearObjects()
{
	First = nullptr;
	Last = nullptr;
	amountCurrentSprites = 0;
}


char Game::getCharbySpritenr(int j)
{
	if(j == 7) return '1';
	if(j == 8) return '2';
	if(j == 9) return '3';
	if(j == 10) return '4';
	if(j == 11) return '5';
	if(j == 12) return '6';
	if(j == 13) return '7';
	if(j == 14) return '8';
	if(j == 15) return '9';
	if(j == 16) return '0';
	if(j == 17) return 'a';
	if(j == 18) return 'b';
	if(j == 19) return 'c';
	if(j == 20) return 'd';
	if(j == 21) return 'e';
	if(j == 22) return 'f';
	if(j == 23) return 'g';
	if(j == 24) return 'h';
	if(j == 25) return 'i';
	if(j == 26) return 'j';
	if(j == 27) return 'k';
	if(j == 28) return 'l';
	if(j == 29) return 'm';
	if(j == 30) return 'n';
	if(j == 31) return 'o';
	if(j == 32) return 'p';
	if(j == 33) return 'q';
	if(j == 34) return 'r';
	if(j == 35) return 's';
	if(j == 36) return 't';
	if(j == 37) return 'u';
	if(j == 38) return 'v';
	if(j == 39) return 'w';
	if(j == 40) return 'x';
	if(j == 41) return 'y';
	if(j == 42) return 'z';
	if(j == 43) return '<';
	if(j == 44) return '>';
	else
		return -1;
}


#ifdef __cplusplus
}
#endif
