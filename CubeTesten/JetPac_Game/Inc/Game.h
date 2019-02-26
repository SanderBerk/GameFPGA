#include "Highscore.h"
#include "Sprite.h"
#include "Object.h"

#ifndef Game_H_
#define Game_H_



class Game
{
public:
	Game(uint16_t,uint16_t);
	virtual ~Game();
	Sprite getSprite(uint8_t);
	Highscore getHighScore(int);
	void SetHighScore(Highscore);
	enum States { INIT, MAINSCREEN, HIGHSCORES, SETTINGS ,PLAYING };
	States GameState;
	void RemObj(uint8_t spritenr);
	void setObj(Object);
	void ChangePosObjbyspritenr(uint8_t spritenr, uint16_t x, uint16_t y);

	Object CurrentObjects[30];
	uint8_t amountCurrentObjects = 0;
	bool ObjActive[20];
private:



	uint16_t resolution_X;
	uint16_t resolution_Y;
	uint8_t HighScoreArraySize = 0;

	Highscore Highscores[10];
	const Sprite Sprites_Array[6] = {Sprite(17,18,1),Sprite(29,30,2),Sprite(18,19,3),Sprite(18,19,4),Sprite(40,10,5),Sprite(0,0,6)};
};


#endif
