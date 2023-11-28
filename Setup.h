#pragma once
#include "snakeHeader.h"
#include "Food.h"
#include "MapOfSnake.h"
#include "Snake.h"
#include "Player.h"
//#include "Logic.h"



class Setup //:protected MapOfSnake, protected Food, protected Snake//, protected Player
{
	friend class Logic;

public:
	Setup();
	Setup(int,int);

	bool getGameOver();
	int getSpeed();

	int getTriggerUp();
	int getTriggerDown();
	int getTriggerRight();
	int getTriggerLeft();
	

	MapOfSnake& getMap();
	Snake& getSnake();
	Food& getFood();
	Player& getPlayer();

	
	void setGameOver();
	void setSpeed(int speed);

	void draw();

private:
	bool gameOver;

	void placeSnake(int x, int y);
	void putFood();
	void deleteFood();

	int triggerUp;
	int triggerDown;
	int triggerRight;
	int triggerLeft;
	int speed;

	MapOfSnake map;
	Snake snake;
	Food food;
	Player player;
	//Logic logic;
};

