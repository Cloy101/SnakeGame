#include "MapOfSnake.h"

MapOfSnake::MapOfSnake() {}

MapOfSnake::MapOfSnake(int x, int y)
{
	this->x = x;
	this->y = y;
	this->map = fillMap(x, y);
}


void MapOfSnake::setMap(const vVec& newMap){ this->map = newMap; }

void MapOfSnake::setPoint(int x, int y, int value) { this->map[y][x] = value; }

void MapOfSnake::deletePoint(int x, int y) { this->map[y][x] = 0; }


int MapOfSnake::getX(){	return this->x;}

int MapOfSnake::getY() { return this->y;}

vVec MapOfSnake::getMap() { return this->map; }

int MapOfSnake::getPoint(int x, int y) { return this->map[y][x]; }

vVec MapOfSnake::fillMap(int x, int y)
{
	vVec temp; // = makeEmpty2dVector(x, y);
	
	for (int i{}; i < y; i++)
	{
		vInt temp2;
		for (int j{}; j < x; j++)
		{
			temp2.push_back(0);
		}
		temp.push_back(temp2);
	}


	for (int i{}; i < x; ++i)
	{
		for (int j{}; j < y; ++j)
		{
			temp[j][0] = 1;
			temp[j][x - 1] = 1;
			temp[0][i] = 1;
			temp[y - 1][i] = 1;
		}
	}
	return temp;
}



void MapOfSnake::print()
{
	for (auto& temp : map)
	{
		for (auto& temp2 : temp)
		{
			if (temp2 == 3) { std::cout << 'o'; }
			if (temp2 == 2) { std::cout << '*'; }
			if (temp2 == 1) { std::cout << '#'; }
			if (temp2 == 0) { std::cout << ' '; }
		}
		std::cout << std::endl;
	}
}





