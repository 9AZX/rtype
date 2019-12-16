/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Missile
*/

#ifndef MISSILE_HPP_
#define MISSILE_HPP_

#include "IEntity.hpp"

class Missile : public IEntity
{
public:
    Missile();
    ~Missile();

protected:
    bool _isAlly;
private:
};

#endif /* !MISSILE_HPP_ */