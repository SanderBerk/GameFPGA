#include "Highscore.h"
#include "Sprite.h"

#ifndef Game_H_
#define Game_H_



class Game
{
public:
	Game();
	virtual ~Game();

	void setResolution(int, int);
	Sprite getSprite(int);
	void addSprite(Sprite);
	Highscore getHighScore(int);
	void SetHighScore(Highscore);
	enum States { INIT, MAINSCREEN, HIGHSCORES, SETTINGS ,PLAYING };
	States GameState;
	void ChangeState(States);
private:
	int resolution_X;
	int resolution_Y;
	int SpriteArraySize = 0;
	int HighScoreArraySize = 0;

	Highscore Highscores[10];
	Sprite Sprites_Array[50];

};


#endif
