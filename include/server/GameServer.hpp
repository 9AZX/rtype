/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Game
*/

#ifndef GAMESERVER_HPP_
#define GAMESERVER_HPP_

#include <time.h>
#include <chrono>
#include <ctime>
#include <thread>
#include <vector>
#include "IEntity.hpp"

typedef std::chrono::milliseconds ms;

using namespace Entity;

class GameServer
{
public:
    GameServer();
    ~GameServer();

    void gameLoop();
    void checkCollisions();
    bool checkPosition(size_t i, size_t j) const;
    bool checkEntityType(size_t i, size_t j) const;

protected:
    std::vector<IEntity> _entities;
private:
};

#endif /* !GAMESERVER_HPP_ */
