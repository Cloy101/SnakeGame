#include "Snake.h"

Snake::Snake(){}

Snake::Snake(int x, int y)
{
	this->snakeSize = 3;
	this->snakeX = x;
	this->snakeY = y;
	this->snakeTailX = x + 1 - snakeSize;
	this->snakeTailY = y;
	this->snakeSizeCurrent = snakeSize;
	//this->tailX[100] = 0;
	//this->tailY[100] = 0;

}


int Snake::getSnakeX() { return this->snakeX; }
int Snake::getSnakeY() { return this->snakeY; }

int Snake::getSnakeSize() {	return snakeSize; }

int Snake::getSnakeTailX() { return snakeTailX; }
int Snake::getSnakeTailY() { return snakeTailY; }
int Snake::getSnakeSizeCurrent() { return snakeSizeCurrent; }

int Snake::moveRightHead()
{
	snakeX++;
	return snakeX;
}

int Snake::moveLeftHead()
{
	snakeX--;
	return snakeX;
}

int Snake::moveUpHead()
{
	snakeY--;
	return snakeY;
}

int Snake::moveDownHead()
{
	snakeY++;
	return snakeY;
}

int Snake::moveRightTail()
{
	snakeTailX++;
	return snakeTailX;
}

int Snake::moveLeftTail()
{
	snakeTailX--;
	return snakeTailX;
}

int Snake::moveUpTail()
{
	snakeTailY--;
	return snakeTailY;
}

int Snake::moveDownTail()
{
	snakeTailY++;
	return snakeTailY;
}

void Snake::setSnakeX(int x) { this->snakeX = x; }
void Snake::setSnakeY(int y) { this->snakeY = y; }

void Snake::setSnakeTailX(int x) { this->snakeTailX = x; }

void Snake::setSnakeTailY(int y) { this->snakeTailY = y; }

void Snake::setSnakeSize(int x) { this->snakeSize = x; }

//void Snake::moveTail()
//{
//	tailX[0] = snakeTailX;
//	tailY[0] = snakeTailY;
//
//	int x = tailX[0];
//	int y = tailY[0];
//	int prevX, prevY;
//
//
//	for (int i = 1; i < snakeSize; i++) {
//
//		prevX = tailX[i];
//		prevY = tailY[i];
//
//		tailX[i] = x;
//		tailY[i] = y;
//
//		x = prevX;
//		y = prevY;
//	}
//}
