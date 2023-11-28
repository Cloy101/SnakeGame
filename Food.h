#pragma once
#include "snakeHeader.h"
#include "MapOfSnake.h"

class Food 
{
friend class Setup;

public:
	Food();
	int getFoodX();
	int getFoodY();

 
	
protected:
	void setFoodX(int x);
	void setFoodY(int y);

private:

	int foodX;
	int foodY;
	//int food;

};

