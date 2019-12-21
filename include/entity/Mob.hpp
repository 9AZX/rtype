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

protected:
    int _healthPoints;

private:
};

#endif /* !MOB_HPP_ */
