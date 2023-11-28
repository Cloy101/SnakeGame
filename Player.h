#pragma once
#include "snakeHeader.h"
#include "MapOfSnake.h"

class Player
{
	friend class Setup;
	friend class Logic;

public:
	Player();

	int input(int ch);
	
	//enum class Move { UP, DOWN, RIGHT, LEFT };


	int getNextMove();
	int getPreviousMove();


private:
	int nextMove;
	int previousMove;
};
      
