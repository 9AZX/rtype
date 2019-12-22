/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Mob
*/

#include "Mob.hpp"

Mob::Mob()
{
}

void Mob::ia()
{
    if (this->_loopCount % 10 == 0)
        rand() % 2 == 0 ? this->move(0, 15) : this->move(0, -15);
    if (this->_loopCount % 5 == 0)
        this->_isShooting = rand() % 2 == 0 ? true : false;
}

float Mob::getPosX() const
{
    return this->_posX;
}

float Mob::getPosY() const
{
    return this->_posY;
}

e_type Mob::getType() const
{
    return this->_type;
}