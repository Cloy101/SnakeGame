#pragma once
#include "snakeHeader.h"
#include "MapOfSnake.h"
#include "Player.h"
#include "Food.h"
//#include "Setup.h"


class Snake //:public Setup
{
	friend class Setup;
	friend class Logic;

public:
	Snake();
	Snake(int,int);

	int getSnakeX();
	int getSnakeY();
	int getSnakeSize();
	int getSnakeTailX();
	int getSnakeTailY();
	int getSnakeSizeCurrent();

protected:

	int moveRightHead();
	int moveLeftHead();
	int moveUpHead();
	int moveDownHead();

	int moveRightTail();
	int moveLeftTail();
	int moveUpTail();
	int moveDownTail();

	void setSnakeX(int x);
	void setSnakeY(int y);
	//void moveTail();
	void setSnakeTailX(int x);
	void setSnakeTailY(int y);


	void setSnakeSize(int x);
	//void placeSnake(MapOfSnake& mapOfSnake, int x, int y);

private:
	//vInt snake;
	int snakeSize;
	int snakeX;
	int snakeY;
	int snakeTailX;
	int snakeTailY;
	int snakeSizeCurrent;
	//int tailX[100];
	//int tailY[100];
};

