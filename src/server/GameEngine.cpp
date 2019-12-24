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

void GameEngine::checkCollisions(std::vector<GameEntity> &entities)
{
    for (size_t i = 0; i < entities.size(); i++)
    {
        for (size_t j = 0; j < entities.size(); j++)
        {
            if (i == j) {
				break;
			}
			/*
            if (this->checkPosition(entities[i], entities[j]) &&
                this->checkEntityType(entities[i], entities[j])) {
                std::cout << "Collision" << std::endl;
            }
			*/
        }
    }
}

bool GameEngine::checkPosition(GameEntity &a, GameEntity &b) const
{
	return (a.getPosX() == b.getPosX()) && (a.getPosY() == b.getPosY());
}

bool GameEngine::checkEntityType(GameEntity &a, GameEntity &b) const
{
	return a.getType() != b.getType();
}
