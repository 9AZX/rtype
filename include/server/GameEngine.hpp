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
#include "GameServer.hpp"

using namespace Entity;

class GameEngine : public GameServer {
public:
    GameEngine();
    ~GameEngine() = default;

    void checkCollisions();
    bool checkPosition(size_t i, size_t j) const;
    bool checkEntityType(size_t i, size_t j) const;
    void mobIA(size_t i);

protected:
private:
};

#endif /* !GAMEENGINE_HPP_ */
