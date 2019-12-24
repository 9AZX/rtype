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
	if (this->_loopCount % 10 == 0) {
		this->move(0, std::rand() % 2 == 0 ? 15 : -15);
	}
	if (this->_loopCount % 5 == 0) {
		this->_isShooting = std::rand() % 2 == 0 ? true : false;
	}
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
