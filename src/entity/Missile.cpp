/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Missile
*/

#include "Missile.hpp"

Missile::Missile(const bool ally)
{
	std::atomic_init(&this->_ally, ally);
}

void Missile::setAlly(const bool ally) noexcept
{
	this->_ally = ally;
}

const std::atomic<bool> &Missile::getAlly() const noexcept
{
	return this->_ally;
}
