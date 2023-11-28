#include "Player.h"

Player::Player()
{
	this->nextMove = VK_RIGHT;
	this->previousMove = VK_RIGHT;
}

int Player::input(int ch)
{
	switch (ch)
	{
		case 72:
			//this->previousMove = VK_UP;
			this->nextMove = VK_UP;
			return VK_UP;
			//break;
			
		case 80:
			//this->previousMove = VK_DOWN;
			this->nextMove = VK_DOWN;
			return VK_DOWN;

		case 75:
			//this->previousMove = VK_RIGHT;
			this->nextMove = VK_RIGHT;
			// Get Snake::snakeX()
			// Get Snake::snakeY()
			// Set Snake::setSnakeTailX(Snake::GetSnakeX())
			// Set Snake::setSnakeTailY(Snake::GetSnakeY())
			return VK_RIGHT;

		case 77:
			//this->previousMove = VK_LEFT;
			this->nextMove = VK_LEFT;
			return VK_LEFT;

		default:
			break;
	}
	//else { return false; }
}

int Player::getNextMove() { return this->nextMove; }

int Player::getPreviousMove() { return this->previousMove; }

//char Player::setPreviousMove(char nextMove) {this->previousMove = nextMove; }