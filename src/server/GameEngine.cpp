/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEngine
*/

#include "GameEngine.hpp"

using namespace Entity;

GameEngine::GameEngine()
{
}

void GameEngine::checkCollisions(std::vector<GameEntity> &entities) noexcept
{
	for (size_t i = 0; i < entities.size(); i++) {
		for (size_t j = 0; j < entities.size(); j++) {
			if (i == j) break;
			if (this->checkPosition(entities[i], entities[j]) &&
				this->checkEntityType(entities[i], entities[j])) {
				std::cout << "Collision" << std::endl;
				entities[i]._removeEntity = true;
				entities[j]._removeEntity = true;
			}
		}
	}
}

bool GameEngine::checkPosition(GameEntity &a, GameEntity &b) const noexcept
{
	if (a.getPosX() == b.getPosY() && a.getPosY() == b.getPosY())
        return true;
	else return false;
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
