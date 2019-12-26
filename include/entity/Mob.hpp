/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Mob
*/

#ifndef MOB_HPP_
#define MOB_HPP_

#include "GameEntity.hpp"

using namespace Entity;

class Mob : public GameEntity
{
public:
	Mob() = default;
	~Mob() = default;

public:
	void ia() override;
	void path(int path);
	void shootingTime();

private:
	int _healthPoints;
	int _movements = 0;
	int _lastMovements = 0;
	int _lastShoot = 0;
	int _loopCount = 0;
	bool _isShooting = false;
};

#endif /* !MOB_HPP_ */
