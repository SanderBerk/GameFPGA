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
	int getSprite_X(int);
	int getSpriteY(int);
	char * getHighScore(int);
	void SetHighScore(int,char,char,char);

private:
	int resolution_X;
	int resolution_Y;

	enum States { INIT, MAINSCREEN, HIGHSCORES, SETTINGS ,PLAYING };
	int Highscores[10]; // HighScore id - Score
	char HighScores_NAME[10][3]; //Char1 - Char2 - Char3
	int Sprites_Array[50][2]; //X - Y

};


#endif
