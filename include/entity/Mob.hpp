/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Mob
*/

#ifndef MOB_HPP_
#define MOB_HPP_

#include "GameEntity.hpp"
#include <cstdlib>

using namespace Entity;

class Mob : public GameEntity
{
public:
	Mob();
	~Mob() = default;

public:
	void path(int path);
	void shootingTime();

private:
	int _healthPoints;
	int _movements = 0;
	int _lastShoot = 0;
};

#endif /* !MOB_HPP_ */
