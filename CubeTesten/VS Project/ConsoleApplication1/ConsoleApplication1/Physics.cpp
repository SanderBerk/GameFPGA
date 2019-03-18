#include "Physics.h"



Physics::Physics()
{
}


Physics::~Physics()
{
}

int Physics::getObjectX(uint8_t x)
{
	this->x = x;
	return getObjX(x);
}

int Physics::getObjectY(uint8_t y)
{
	this->y = y;
	return getObjY(y);
}

int Physics::getSpriteNrByString(uint8_t ID)
{
	this->ID = ID;
	return getSpriteNrByString(ID);
}

void Physics::addBall(double x, double y, double r = 5.0, uint8_t ID)
{
	this->x = x;
	this->y = y;
	this->ID = ID;

	ball b;
	b.px = x; b.py = y;
	b.vx = 0; b.vy = 0;
	b.ax = 0; b.ax = 0;
	b.radius = r;
	b.mass = r * 10.0f;

	b.id = vecBall.size();
	vecBall.emplace_back(b); //controle vecsize
}

bool Physics::onUserCreate()
{
	circle.push_back({ 0.0, 0.0 });
	for (int i = 0; i < points; i++)
	{
		circle.push_back({ cos(i / (double)(points - 1) * 2.0 * 3.14159), sin(i / (double)(points - 1) * 2.0 * 3.14159) }); //formule om circle te tekenen
	}

	//addBall (screenwaarde x, screenhoogte y, ballRadius) -- bal toevoegen
	vecLines.push_back({ 100.0, 60.0, 180.0, 60.0, platformRadius }); //platform toevoegen

	return true;
}

bool Physics::onUserUpdate(double fps)
{
	auto collision = [](double x1, double y1, double r1, double x2, double y2, double r2) //lambda functie
	{
		return abs((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) <= (r1 - r2)*(r1 - r2)); //detecting collision
	};

	for (auto &b : vecBall) //update position ball
	{
		b.ax = -b.vx * 1.5;
		b.ay = -b.vy * 1.5 + 100.0;

		b.vx += b.ax * fps;
		b.vy += b.ay * fps;
		b.px += b.vx * fps;
		b.py += b.vy * fps;

		if (abs(b.vx*b.vx + b.vy*b.vy) < 0.01) //afremmen
		{
			b.vx = 0;
			b.vy = 0;
		}
	}

	for (auto &b : vecBall) //static collision
	{
		for (auto &edge : vecLines) //against platforms
		{
			double lineX1 = edge.ex - edge.sx;
			double lineY1 = edge.ey - edge.sy;

			double lineX2 = b.px - edge.sx;
			double lineY2 = b.py - edge.sy;

			double edgeLength = lineX1 * lineX1 + lineY1 * lineY1;
			double edgeHeight = lineX1 * lineX2 + lineY1 * lineY2;

			double t = max(0, min(edgeLength, edgeHeight)) / edgeLength;

			double closestX = edge.sx + t * lineX1;
			double closestY = edge.sy + t * lineY1;

			double distance = sqrtf((b.px - closestX)*(b.px - closestX) + (b.py - closestY)*(b.py - closestY));

			if (distance <= (b.radius + edge.radius))
			{
				ball* fakeball = new ball();
				fakeball->radius = edge.radius;
				fakeball->mass = b.mass * 0.8;
				fakeball->px = closestX;
				fakeball->py = closestY;
				fakeball->vx = -b.vx;
				fakeball->vy = -b.vy;

				vecFakeBalls.push_back(fakeball);
				vecCollision.push_back({ &b, fakeball });

				float overlap = (distance - b.radius - fakeball->radius);

				b.px -= 50.0 * overlap * (b.px - fakeball->px) / distance;
				b.py -= 50.0 * overlap * (b.py - fakeball->py) / distance;
			}
		}

		for (auto &target : vecBall) //against other balls
		{
			if (b.id != target.id)
			{
				if (collision(b.px, b.py, b.radius, target.px, target.py, target.radius))
				{
					vecCollision.push_back({ &b, &target });
					double distance = sqrt((b.px - target.px)*(b.px - target.px) + (b.py - target.py)*(b.py - target.py));

					double overlap = (distance - b.radius - target.radius);

					b.px -= overlap * (b.px - target.px) / distance;
					b.py -= overlap * (b.py - target.py) / distance;

					target.px += overlap * (b.px - target.px) / distance;
					target.py += overlap * (b.py - target.py) / distance;
				}
			}
		}
	}

	for (auto c : vecCollision) //dynamic
	{
		ball *b1 = c.first;
		ball *b2 = c.second;

		double distance = sqrt((b1->px - b2->px)*(b1->px - b2->px) + (b1->py - b2->py)*(b1->py - b2->py));

		double nx = (b2->px - b1->px) / distance;
		double ny = (b2->py - b1->py) / distance;

		double x = (b1->vx - b2->vx);
		double y = (b1->vy - b2->vy);
		double p = 2.0 * (nx * x + ny * y) / (b1->mass + b2->mass);
		b1->vx = b1->vx - p * b2->mass * nx;
		b1->vy = b1->vy - p * b2->mass * ny;
		b2->vx = b2->vx + p * b1->mass * nx;
		b2->vy = b2->vy + p * b1->mass * ny;
	}

	vecCollision.clear();

	for (auto &b : vecFakeBalls) delete b;
	vecFakeBalls.clear();

	return true;
}

