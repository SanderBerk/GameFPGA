#include "Highscore.h"

#ifndef Game_H_
#define Game_H_

enum AvailableStates { INIT, MAINSCREEN, HIGHSCORES, SETTINGS, PLAYING };

class Game
{
public:
	Game();
	virtual ~Game();

	void setResolution(int, int);
	void ChangeState(AvailableStates);
	Sprite getSprite(int);
	void addSprite(Sprite);
	Highscore getHighScore(int);
	void SetHighScore(Highscore);

private:
	int resolution_X;
	int resolution_Y;
	int SpriteArraySize = 0;
	int HighScoreArraySize = 0;
	enum States { INIT, MAINSCREEN, HIGHSCORES, SETTINGS ,PLAYING };
	Highscore Highscores[10];
	Sprite Sprites_Array[50];

};


#endif
