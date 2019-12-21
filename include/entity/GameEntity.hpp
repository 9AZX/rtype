/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEntity
*/

#ifndef GAME_ENTITY_HPP_
#define GAME_ENTITY_HPP_

#include <iostream>
#include "IEntity.hpp"

using namespace Entity;

class GameEntity : public IEntity {
public:
	GameEntity();
	~GameEntity() = default;

    void move(float x, float y) final;

    float getPosX() const final;
    float getPosY() const final;
    e_type getType() const final;

protected:
private:
};

#endif /* !GAME_ENTITY_HPP_ */
