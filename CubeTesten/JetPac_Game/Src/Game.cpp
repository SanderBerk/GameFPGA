#include "Game.h"
#include "ssd1306.h"

#ifdef __cplusplus
extern "C"
{
#endif


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

int Game::addObject(Object * obj)
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
		for(int i = 0;i<temp->Xlength;i++)
		{
			for(int j = 0;j<temp->Ylength;j++)
			{
					ssd1306_DrawPixel(temp->LposX+i, temp->LposY+j, White);
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
}


#ifdef __cplusplus
}
#endif
