/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Missile
*/

#ifndef MISSILE_HPP_
#define MISSILE_HPP_

#include "IEntity.hpp"

using namespace Entity;

class Missile : public IEntity
{
public:
    Missile(bool isAlly);
    ~Missile() = default;

    bool positionLimits(float x, float y) const final;

protected:
    bool _isAlly;

private:
};

#endif /* !MISSILE_HPP_ */