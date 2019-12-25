/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Missile
*/

#ifndef	_MISSILE_HPP_
#define	_MISSILE_HPP_

#include "GameEntity.hpp"

using namespace Entity;

class Missile : public GameEntity
{
public:
	Missile() = default;
	Missile(const bool ally);
	~Missile() = default;

public:
	void setAlly(const bool ally) noexcept;
	const std::atomic<bool> &getAlly() const noexcept;

private:
	std::atomic<bool> _ally;
};

#endif	/* !_MISSILE_HPP_ */
