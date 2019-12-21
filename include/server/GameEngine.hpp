/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEngine
*/

#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

#include <iostream>
#include <vector>
#include "GameEntity.hpp"

using namespace Entity;

class GameEngine {
public:
    GameEngine();
    ~GameEngine() = default;

    void checkCollisions(std::vector<GameEntity> entities);
    bool checkPosition(GameEntity a, GameEntity b) const;
    bool checkEntityType(GameEntity a, GameEntity b) const;

protected:
private:
};

#endif /* !GAMEENGINE_HPP_ */
