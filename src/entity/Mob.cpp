/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Mob
*/

#include "Mob.hpp"

Mob::Mob() {
	this->setType(MOB1);
	this->setPosY(500);
	this->setPosX(500);
}

void Mob::shootingTime()
{
	int num = std::rand() % 2;

	if ((this->_movements >= this->_lastShoot + 100) && num == 1)
	{
		this->_lastShoot += 100;
	}
}

void Mob::path(int path)
{
	if (path == 1 && this->getPosY() <= 1080)
	{
		this->setPosY(this->getPosY() + 10);
	}
	else
	{
		if (this->getPosY() >= 0)
		{
			this->setPosY(this->getPosY() - 10);
		}
	}
}
