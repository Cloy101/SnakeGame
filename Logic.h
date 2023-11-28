#pragma once
#include "snakeHeader.h"
#include "Setup.h"
#include "Snake.h"
#include "MapOfSnake.h"
#include "Player.h"
#include "Food.h"


class Logic
{
	friend class Setup;

public:

	Logic();

	void control(MapOfSnake& map, Snake& snake, Food& food, Player& player);

	int getTriggerHead(MapOfSnake& map, Snake& snake);
	int getTriggerTail(MapOfSnake& map, Snake& snake);


	void putTrigger(MapOfSnake& map, Snake& snake);

	void moveHead(MapOfSnake& map, Snake& snake,int trigger);

	void removeHead(MapOfSnake& map, Snake& snake, int trigger);


	void moveTail(MapOfSnake& map, Snake& snake, int trigger);
	void removeTail(MapOfSnake& map, Snake& snake, int trigger);

	void touchWall(MapOfSnake& map, Snake& snake);
	void touchWallTail(MapOfSnake& map, Snake& snake, int trigger);

	bool biteSnake(MapOfSnake& map, Snake& snake);


	void triggerUp(MapOfSnake& map, Snake& snake);
	void triggerDown(MapOfSnake& map, Snake& snake);
	void triggerRight(MapOfSnake& map, Snake& snake);
	void triggerLeft(MapOfSnake& map, Snake& snake);

	void changeHeadAfterEat(MapOfSnake& map, Snake& snake, int trigger);
	bool checkFood(MapOfSnake& map, Snake& snake);

private:

	Setup setup;
	int ch;
	int previousCh;

};

