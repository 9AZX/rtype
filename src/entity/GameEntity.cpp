/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEntity
*/

#include "GameEntity.hpp"

GameEntity::GameEntity()
{
}

void GameEntity::move(float x, float y)
{
    std::cout << "Move entity " << this->_id << std::endl;

    this->_posX += x;
    this->_posY += y;
}

float GameEntity::getPosX() const
{
    return this->_posX;
}

float GameEntity::getPosY() const
{
    return this->_posY;
}

e_type GameEntity::getType() const
{
    return this->_type;
}