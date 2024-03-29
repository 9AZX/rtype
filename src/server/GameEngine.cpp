/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEngine
*/

#include "GameEngine.hpp"
#include <iostream>

using namespace Entity;

GameEngine::GameEngine()
{
}

void GameEngine::checkCollisions(std::vector<std::unique_ptr<GameEntity>> &entities) noexcept
{
	for (size_t i = 0; i < entities.size(); i++)
	{
		for (size_t j = 0; j < entities.size(); j++)
		{
			if (i == j)
				break;
			if (this->checkPosition(*entities[i], *entities[j]) &&
				this->checkEntityType(*entities[i], *entities[j]))
			{
				std::cout << "Collision" << std::endl;
				entities[i]->setRemoveEntity();
				entities[j]->setRemoveEntity();
			}
		}
	}
}

bool GameEngine::checkPosition(GameEntity &a, GameEntity &b) const noexcept
{
	int ax = a.getPosX();
	int ay = a.getPosY();
	int bPosX = b.getPosX();
	int bPosY = b.getPosY();

	if (bPosX >= ax && bPosX <= ax + SPRITE_DIM_X &&
		bPosY >= ay && bPosY <= ay + SPRITE_DIM_Y)
		return true;
	else
		return false;
}

bool GameEngine::checkEntityType(GameEntity &a, GameEntity &b) const noexcept
{
	if (a.getType() != b.getType())
		return true;
	return false;
}

void GameEngine::mobIA(GameEntity &a) noexcept
{
	if (a.getType() >= type::MOB1)
		a.ia();
}

bool GameEngine::isGameInProgress() const noexcept
{
	return this->_gameIP;
}

void GameEngine::setGameStart(bool value) noexcept
{
	this->_gameIP = value;
}