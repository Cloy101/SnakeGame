#include "Setup.h"

Setup::Setup(){}

Setup::Setup(int x, int y)// :MapOfSnake{ x, y }, Snake{ x / 2, y / 2 }
{
	this->gameOver = false;
	this->speed = 50;
	MapOfSnake mapTemp{ x, y };
	Snake snakeTemp{ x / 2, y / 2 };
	Food foodTemp;
	//Player playerTemp;
	//Logic logicTemp;

	this->map = mapTemp;
	this->snake = snakeTemp;
	this->food = foodTemp;
	//this->player = playerTemp;
	//this->logic = logicTemp;

	this->triggerUp = 72;
	this->triggerDown = 80;
	this->triggerRight = 77;
	this->triggerLeft = 75;


	placeSnake(this->snake.getSnakeX(), this->snake.getSnakeY());
	putFood();
	//player.nextMove = VK_RIGHT;
	//draw();
	system("cls");

	//logic.control(map,snake,food,player);
}

bool Setup::getGameOver() { return gameOver; }

int Setup::getSpeed() {	return this->speed; }

int Setup::getTriggerUp() {	return this->triggerUp; }

int Setup::getTriggerDown() { return this->triggerDown; }

int Setup::getTriggerRight() { return this->triggerRight; }

int Setup::getTriggerLeft() { return this->triggerLeft; }

MapOfSnake& Setup::getMap() { return this->map; }

Snake& Setup::getSnake() { return this->snake;}

Food& Setup::getFood() {	return this->food; }

Player& Setup::getPlayer() {	return this->player; }

void Setup::setGameOver() {	gameOver = true; }

void Setup::setSpeed(int speed) { this->speed = speed; }


void Setup::placeSnake(int x, int y)
{
	for (int i{}; i < this->snake.getSnakeSize(); ++i)
	{
		this->map.setPoint(x, y, triggerRight);
		x--;

	}
}

void Setup::draw()
{
	for (auto& temp : this->map.getMap())
	{
		for (auto& temp2 : temp)
		{
			if (temp2 == 3) { std::cout << 'o'; }
			//if (temp2 == 2) { std::cout << '*'; }
			if (temp2 == 1) { std::cout << '#'; }
			if (temp2 == 0) { std::cout << ' '; }
			if (temp2 == 72) { std::cout << '*'; }
			if (temp2 == 80) { std::cout << '*'; }
			if (temp2 == 77) { std::cout << '*'; }
			if (temp2 == 75) { std::cout << '*'; }



		}
		std::cout << std::endl;
	}
}

void Setup::putFood()
{
	int randomX{};
	int randomY{};
	do
	{
		randomX = 1 + rand() % (this->map.getX() - 1);
		randomY = 1 + rand() % (this->map.getY() - 1);
	} while (this->map.getPoint(randomX, randomY) != 0);

	this->map.setPoint(randomX, randomY, 3);
	this->food.setFoodX(randomX);
	this->food.setFoodY(randomY);
}

void Setup::deleteFood() { this->map.deletePoint(this->food.getFoodX(), this->food.getFoodY()); }

