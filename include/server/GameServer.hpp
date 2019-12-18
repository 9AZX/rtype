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

typedef std::chrono::milliseconds ms;

class GameServer
{
public:
    GameServer();
    ~GameServer();

    void gameLoop();

protected:
private:
};

#endif /* !GAMESERVER_HPP_ */
