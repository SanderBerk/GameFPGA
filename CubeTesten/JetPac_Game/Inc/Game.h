#include "Highscore.h"
#include "Sprite.h"
#include "Object.h"

#ifndef Game_H_
#define Game_H_



class Game
{
public:
	Game(uint16_t, uint16_t);
	virtual ~Game();
	Sprite getSprite(uint8_t);
	Highscore getHighScore(int);
	void SetHighScore(Highscore);
	enum States { INIT, MAINSCREEN, HIGHSCORES, SETTINGS, PLAYING };
	States GameState;

	void removeObjectUni(uint8_t UniqueNr);
	uint8_t addObject(Object * obj);
	int ChangePosObjbyUniNr(uint8_t uninr, uint16_t x, uint16_t y);
	bool changeSpriteNr(int,int); // Dangerous!!!!
	//void showall();
	void clearObjects();
	void draw();
	void drawssd1306();
	void clearssd1306();
	int checkColl(uint8_t uninr, uint8_t line1, uint8_t line2, uint8_t line3, uint8_t line4);
	int getObjX(uint8_t uninr);
	int getObjY(uint8_t uninr);

	char Game::getCharbySpritenr(int j);

private:
	Object * First = nullptr;
	Object * Last = nullptr;
	uint8_t amountCurrentSprites = 0;


	uint16_t resolution_X;
	uint16_t resolution_Y;
	uint8_t HighScoreArraySize = 0;

	Highscore Highscores[10];
	const Sprite Sprites_Array[7] = { Sprite(0,0,0), Sprite(17,18,1),Sprite(29,30,2),Sprite(18,19,3),Sprite(18,19,4),Sprite(40,10,5),Sprite(0,0,6) };
};


#endif
