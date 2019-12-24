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

void GameEngine::checkCollisions()
{
	for (size_t i = 0; i < this->_entities.size(); i++) {
		for (size_t j = 0; j < this->_entities.size(); j++) {
			if (i == j) break;
			if (this->checkPosition(i, j) &&
				this->checkEntityType(i, j)) {
				std::cout << "Collision" << std::endl;
				this->_entities[i]._removeEntity = true;
				this->_entities[j]._removeEntity = true;
			}
		}
	}
}

bool GameEngine::checkPosition(size_t i, size_t j) const
{
	if (this->_entities[i].getPosX() == this->_entities[j].getPosY()
		&& this->_entities[i].getPosY() == this->_entities[j].getPosY()) {
			return true;
	} else return false;
}

bool GameEngine::checkEntityType(size_t i, size_t j) const
{
	if (this->_entities[i].getType() != this->_entities[j].getType())
		return true;
	return false;
}

void GameEngine::mobIA(size_t i)
{
	if (this->_entities[i].getType() >= type::MOB1) {
		this->_entities[i].ia();
	}
}
