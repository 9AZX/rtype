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

Mob::~Mob()
{
}

void Mob::Ia()
{
    if (this->_lastMovements + 15 == this->_movements)
    {
        if (this->_posY <= 0)
            this->_posY = 500;
        this->_lastMovements = this->_movements;
        int num = rand() % 2;
        this->path(num);
        this->shootingTime();
    }
    _movements += 1;
}

void Mob::shootingTime()
{
    int num;

    if (this->_movements >= this->_lastShoot + 100)
    {
        num = rand() % 2;
        if (num == 1)
        {
            std::cout << "shoot" << std::endl;
            this->_lastShoot += 100;
        }
    }
}

void Mob::path(int path)
{
    if (path == 1)
    {
        if (this->_posY <= 1080)
            this->_posY += 10;
    }
    if (this->_posY >= 0)
        this->_posY -= 10;
}

void Mob::move(float x, float y)
{
    std::cout << "Move entity " << this->_id << std::endl;

    this->_posX += x;
    this->_posY += y;
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