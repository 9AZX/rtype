/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Mob
*/

#ifndef MOB_HPP_
#define MOB_HPP_

#include "IEntity.hpp"

using namespace Entity;

class Mob : public IEntity
{
public:
    Mob();
    ~Mob();
    void Ia();

    void move(float x, float y) final;
    void path(int path);
    void shootingTime();

    float getPosX() const final;
    float getPosY() const final;
    e_type getType() const final;

protected:
    int _healthPoints;
    int _movements = 0;
    int _lastMovements = 0;
    int _lastShoot = 0;

private:
};

#endif /* !MOB_HPP_ */
