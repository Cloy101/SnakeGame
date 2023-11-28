#include "Logic.h"

Logic::Logic()
{
	Setup setupTemp(20, 20);
	this->setup = setupTemp;
	this->ch = 77;
	this->previousCh = 77;
	//putTrigger(setup.getMap(), setup.getSnake());

	control(setup.getMap(), setup.getSnake(), setup.getFood(), setup.getPlayer());
}

void Logic::control(MapOfSnake& map, Snake& snake, Food & food, Player& player)
{
	while (!setup.getGameOver())
	{
		while (!_kbhit())
		{
			moveHead(map, snake, getTriggerHead(map, snake));
						
			putTrigger(map, snake);
			
			if (checkFood(map, snake))
			{
				changeHeadAfterEat(map, snake, ch);
				setup.putFood();

			}
			
			moveTail(map, snake, getTriggerTail(map, snake));
			setup.draw();
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
			Sleep(setup.getSpeed());
			system("cls");
		}
		
		int x = _getch();
		if (x ==72 && previousCh != 80 || x==80 && previousCh != 72 || x==77 && previousCh != 75 || x == 75 && previousCh != 77)
		{
			this->ch = x;
		}
		else { this->ch = previousCh; }


		//putTrigger(map, snake);
		//moveHead(map, snake, getTriggerHead(map, snake));


		removeHead(map, snake, ch);
		removeTail(map, snake, ch);


	}
}

int Logic::getTriggerHead(MapOfSnake& map, Snake& snake) { return map.getPoint(snake.getSnakeX(), snake.getSnakeY()); }

int Logic::getTriggerTail(MapOfSnake& map, Snake& snake) { return map.getPoint(snake.getSnakeTailX(), snake.getSnakeTailY()); }


void Logic::putTrigger(MapOfSnake& map, Snake& snake)
{
	switch (ch)
	{
	case 72: // UP Arrow
		
		if ( map.getPoint( snake.getSnakeX(), snake.getSnakeY()-1 ) != 1) { triggerUp(map, snake); }
		else 
		{ 
			triggerUp(map, snake);
			touchWall(map, snake);
		}
		break;

	case 80: // DOWN Arrow
		if ( map.getPoint( snake.getSnakeX(), snake.getSnakeY()+1 ) != 1) { triggerDown(map, snake); }
		else
		{
			triggerDown(map, snake);
			touchWall(map, snake);
		}
		break;

	case 77: // RIGHT arrow
		if ( map.getPoint( snake.getSnakeX()+1, snake.getSnakeY() ) != 1) { triggerRight(map, snake); }
		else
		{
			triggerRight(map, snake);
			touchWall(map, snake);
		}
		break;

	case 75: // LEFT arrow
		if ( map.getPoint( snake.getSnakeX()-1, snake.getSnakeY() ) != 1) { triggerLeft(map, snake); }
		else
		{
			triggerLeft(map, snake);
			touchWall(map, snake);
		}
		break;

	default:
		//map.setPoint(snake.getSnakeX(), snake.getSnakeY(), 2);
		break;
	}
}

void Logic::triggerUp(MapOfSnake &map, Snake& snake)
{
	map.setPoint(snake.getSnakeX(), snake.getSnakeY(), 72);
	this->previousCh = 72;
}

void Logic::triggerDown(MapOfSnake& map, Snake& snake)
{

	map.setPoint(snake.getSnakeX(), snake.getSnakeY(), 80);
	this->previousCh = 80;

}

void Logic::triggerRight(MapOfSnake& map, Snake& snake)
{

	map.setPoint(snake.getSnakeX(), snake.getSnakeY(), 77);
	this->previousCh = 77;

}

void Logic::triggerLeft(MapOfSnake& map, Snake& snake)
{

	map.setPoint(snake.getSnakeX(), snake.getSnakeY(), 75);
	this->previousCh = 75;

}

void Logic::moveHead(MapOfSnake& map, Snake & snake, int trigger)
{
	switch (trigger)
	{
	case 72:
		snake.moveUpHead();
		break;
	case 80:
		snake.moveDownHead();
		break;
	case 77:
		snake.moveRightHead();
		break;
	case 75:
		snake.moveLeftHead();
		break;
	
	default:
		break;
	}
}


void Logic::removeHead(MapOfSnake& map, Snake& snake, int trigger)
{
	switch (trigger)
	{

	case 72:
		snake.setSnakeY(snake.getSnakeY());
		break;
	case 80:
		snake.setSnakeY(snake.getSnakeY());
		break;
	case 77:
		snake.setSnakeX(snake.getSnakeX());
		break;
	case 75:
		snake.setSnakeX(snake.getSnakeX());
		break;

	default:
		break;
	}
}


void Logic::moveTail(MapOfSnake& map, Snake& snake, int trigger)
{
	switch (trigger)
	{
	case 72:

		if (map.getPoint( snake.getSnakeTailX(), snake.getSnakeTailY()-1 ) != 1)
		{
			map.deletePoint(snake.getSnakeTailX(), snake.getSnakeTailY());
			snake.moveUpTail();
		}
		else
		{
			map.deletePoint(snake.getSnakeTailX(), snake.getSnakeTailY());
			touchWallTail(map, snake, trigger);
			//snake.moveUpTail();
		}
		break;

	case 80:

		if (map.getPoint( snake.getSnakeTailX(), snake.getSnakeTailY()+1 ) != 1)
		{
			map.deletePoint(snake.getSnakeTailX(), snake.getSnakeTailY());
			snake.moveDownTail();
		}
		else
		{
			map.deletePoint(snake.getSnakeTailX(), snake.getSnakeTailY());
			touchWallTail(map, snake, trigger);
			//snake.moveDownTail();
		}
		break;

	case 77:
		
		if (map.getPoint( snake.getSnakeTailX()+1, snake.getSnakeTailY() ) != 1)
		{
			map.deletePoint(snake.getSnakeTailX(), snake.getSnakeTailY());
			snake.moveRightTail();
		}
		else
		{
			map.deletePoint(snake.getSnakeTailX(), snake.getSnakeTailY());
			touchWallTail(map, snake, trigger);
			//snake.moveRightTail();
		}
		break;

	case 75:

		if (map.getPoint( snake.getSnakeTailX()-1, snake.getSnakeTailY() ) != 1)
		{
			map.deletePoint(snake.getSnakeTailX(), snake.getSnakeTailY());
			snake.moveLeftTail();
		}
		else
		{
			map.deletePoint(snake.getSnakeTailX(), snake.getSnakeTailY());
			touchWallTail(map, snake, trigger);
			//snake.moveLeftTail();
		}
		break;

	default:
		break;
	}
}

void Logic::removeTail(MapOfSnake& map, Snake& snake, int trigger)
{
	switch (trigger)
	{
	case 72:

		snake.setSnakeTailY(snake.getSnakeTailY());
		break;

	case 80:

		snake.setSnakeTailY(snake.getSnakeTailY());
		break;

	case 77:

		snake.setSnakeTailX(snake.getSnakeTailX());
		break;

	case 75:

		snake.setSnakeTailX(snake.getSnakeTailX());
		break;

	default:
		break;
	}
}



void Logic::touchWall(MapOfSnake& map, Snake& snake)
{
	switch (ch)
	{
	case 72: // UP Arrow
			snake.setSnakeY(map.getY() - 2);
			break;

	case 80: // DOWN Arrow
			snake.setSnakeY(1);
			break;
	case 77: // RIGHT arrow
		snake.setSnakeX(1);
		break;

	case 75: // LEFT arrow
		snake.setSnakeX(map.getX() - 2);
		break;

	default:
		break;
	}

}

void Logic::touchWallTail(MapOfSnake& map, Snake& snake, int trigger)
{
	switch (trigger)
	{
	case 72: // UP Arrow
		snake.setSnakeTailY(map.getY() - 2);
		break;

	case 80: // DOWN Arrow
		snake.setSnakeTailY(1);
		break;
	case 77: // RIGHT arrow
		snake.setSnakeTailX(1);
		break;

	case 75: // LEFT arrow
		snake.setSnakeTailX(map.getX() - 2);
		break;

	default:
		//map.setPoint(snake.getSnakeX(), snake.getSnakeY(), 2);
		break;
	}

}

void Logic::changeHeadAfterEat(MapOfSnake& map,Snake& snake, int trigger)
{
	switch (trigger)
	{
	case 72: // UP Arrow
		putTrigger(map, snake);
		//snake.moveUpHead();
		snake.moveUpHead();
		putTrigger(map, snake);
		//snake.moveDownTail();

		break;

	case 80: // DOWN Arrow
		
		snake.moveDownHead();
		putTrigger(map, snake);
		//snake.moveDownHead();
		//snake.moveUpTail();

		break;
	case 77: // RIGHT arrow
		
		snake.moveRightHead();
		putTrigger(map, snake);
		//snake.moveLeftTail();

		break;

	case 75: // LEFT arrow
		
		snake.moveLeftHead();
		putTrigger(map, snake);
		//snake.moveLeftHead();
		//snake.moveRightTail();

		break;

	default:
		break;
	}
}

bool Logic::checkFood(MapOfSnake& map, Snake& snake)
{
	switch (this->ch)
	{
	case 72: // UP Arrow
		if (map.getPoint(snake.getSnakeX(), snake.getSnakeY() - 1) == 3) 
		{ 
			return true;
			break;
		}
		return false;
		break;

	case 80: // DOWN Arrow
		if (map.getPoint(snake.getSnakeX(), snake.getSnakeY() + 1) == 3)
		{
			return true;
			break;
		}
		return false;
		break;

	case 77: // RIGHT arrow
		if (map.getPoint(snake.getSnakeX()+1, snake.getSnakeY()) == 3)
		{
			return true;
			break;
		}
		return false;
		break;

	case 75: // LEFT arrow
		if (map.getPoint(snake.getSnakeX()-1, snake.getSnakeY()) == 3)
		{
			return true;
			break;
		}
		return false;
		break;

	default:
		return false;
		break;
	}
}

bool Logic::biteSnake(MapOfSnake& map, Snake& snake)
{
	if (map.getPoint(snake.getSnakeX(), snake.getSnakeY()) != 0 || map.getPoint(snake.getSnakeX(), snake.getSnakeY()) != 1 || map.getPoint(snake.getSnakeX(), snake.getSnakeY()) != 3)
	{
		return true;
	}
	else { return false; }


	//switch (ch)
	//{
	//case 72: // UP Arrow
	//	
	//	if((map.getPoint(snake.getSnakeX(), snake.getSnakeY() - 1)) != 0 ||    );
	//	return true;

	//case 80: // DOWN Arrow
	//	snake.setSnakeY(1);
	//	return true;
	//case 77: // RIGHT arrow
	//	snake.setSnakeX(1);
	//	return true;

	//case 75: // LEFT arrow
	//	snake.setSnakeX(map.getX() - 2);
	//	return true;

	//default:
	//	break;
	//}

}
