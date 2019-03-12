#pragma once

#include <stdint.h>
#include <iostream>

class Highscore
{
public:
	Highscore();
	virtual ~Highscore();
	Highscore(int, std::string);
	std::string getHNaam();
	int getPlace();

private:
	int HighscorePlace;
	std::string Hnaam;

	friend class Game;
};

