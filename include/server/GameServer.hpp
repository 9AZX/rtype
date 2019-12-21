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
#include "GameEntity.hpp"
#include "GameEngine.hpp"

typedef std::chrono::milliseconds ms;

using namespace Entity;

class GameServer
{
public:
    GameServer();
    ~GameServer();

    void gameLoop();

protected:
    std::unique_ptr<GameEngine> _gameEngine;
    std::vector<GameEntity> _entities;
private:
};

#endif /* !GAMESERVER_HPP_ */
