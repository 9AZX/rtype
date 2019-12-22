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
    ~Mob() = default;

    void ia();

    void move(float x, float y) final;
    bool positionLimits(float x, float y) const final;

    float getPosX() const final;
    float getPosY() const final;
    e_type getType() const final;

protected:
    int _loopCount = 0;
    bool _isShooting = false;

private:
};

#endif /* !MOB_HPP_ */
