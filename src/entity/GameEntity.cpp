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
    if (!this->positionLimits(this->_posX + x, this->_posY)) {
        this->_posX += x;
        this->_posY += y;
    }
}

bool GameEntity::positionLimits(float x, float y) const
{
    if (x > 1920 || x < 0 || y > 1920 || y < 0)
        return true;
    return false;
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