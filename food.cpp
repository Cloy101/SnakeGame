#include "Food.h"


Food::Food()
{ 
	//food = 3; 
	foodX = 0;
	foodY = 0;
}

int Food::getFoodX() { return foodX; }
int Food::getFoodY() { return foodY; }

void Food::setFoodX(int x) { this->foodX = x; }

void Food::setFoodY(int y) { this->foodY = y; }