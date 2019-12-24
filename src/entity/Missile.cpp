/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Missile
*/

#include "Missile.hpp"

Missile::Missile(bool isAlly) : _isAlly(isAlly)
{
}

bool GameEntity::positionLimits(float x, float y) const
{
    if (x > 1920 || x < 0 || y > 1920 || y < 0) {
        this->_removeEntity = true;
        return true;
    }
    return false;
}