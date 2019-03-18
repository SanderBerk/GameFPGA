#pragma once
#include "Game.h"
#include <vector>
#include <Windows.h>
using namespace std;

struct ball
{
	float px, py; //position points
	float vx, vy; //velocity points
	float ax, ay; //accelaration points
	float radius;
	float friction;
	float mass;

	int id;
};

struct platform
{
	float sx, sy; //start points
	float ex, ey; //ending points
	float radius; //radius

	int id;
};

class Physics : public Game
{
public:
	Physics();
	virtual ~Physics();
	int getObjectX(uint8_t x);
	int getObjectY(uint8_t y);
	int getSpriteNrByString(uint8_t ID);

public:
	void addBall(double, double, double, uint8_t);
	bool onUserCreate();
	bool onUserUpdate(double);

private:
	uint8_t x;
	uint8_t y;
	uint8_t ID;

private:
	vector<pair<float, float>> circle;
	vector<ball> vecBall;
	vector<platform> vecLines;
	vector<pair<ball*, ball*>> vecCollision;
	vector<ball*> vecFakeBalls;
	int points = 20;
	double ballRadius = 8.0;
	double platformRadius = 4.0;
};

