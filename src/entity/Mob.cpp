/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Mob
*/

#include <cstdlib>
#include "Mob.hpp"

void Mob::Ia()
{
	int num = std::rand() % 2;

	if (this->_lastMovements + 15 == this->_movements) {
		if (this->getPosY() <= 0) {
			this->setPosY(500);
		}
		this->_lastMovements = this->_movements;
		this->path(num);
		this->shootingTime();
	}
	_movements += 1;
}

void Mob::shootingTime()
{
	int num = std::rand() % 2;

	if ((this->_movements >= this->_lastShoot + 100) && num == 1) {
		this->_lastShoot += 100;
	}
}

void Mob::path(int path)
{
	if (path == 1 && this->getPosY() <= 1080) {
		this->setPosY(this->getPosY() + 10);
	}
	else {
		if (this->getPosY() >= 0) {
			this->setPosY(this->getPosY() - 10);
		}
	}
}
