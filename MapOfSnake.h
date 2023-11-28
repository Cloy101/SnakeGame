#pragma once
#include "snakeHeader.h"
#include "makeEmpty2dVector.h"
//#include "Setup.h"

//typedef std::vector<int> vInt;
//typedef std::vector<std::vector<int>> vVec;

class MapOfSnake
{
	friend class Food;
	friend class Player;
	friend class Snake;
	friend class Setup;
	friend class Logic;
	//friend void draw(auto &);

public:
	MapOfSnake();
	MapOfSnake(int,int);
	virtual void print();

	int getX();
	int getY();
	int getPoint(int x, int y);
	vVec getMap();



protected:
	void setMap(const vVec& newMap);
	void setPoint(int x, int y, int value);

	void deletePoint(int x, int y);
	


	vVec fillMap(int x, int y);


private:
	int x;
	int y;
	vVec map;
};

