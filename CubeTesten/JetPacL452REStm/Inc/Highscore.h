/*
 * Highscore.h
 *
 *  Created on: Feb 19, 2019
 *      Author: Rinke
 */

#include <string>

#ifndef HIGHSCORE_H_
#define HIGHSCORE_H_

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








#endif /* HIGHSCORE_H_ */
