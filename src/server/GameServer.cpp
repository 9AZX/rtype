/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameServer
*/

#include "GameServer.hpp"

#include <iostream>
#include <numeric>

using namespace Entity;

GameServer::GameServer()
{
    this->_gameEngine = std::make_unique<GameEngine>();
}

GameServer::~GameServer()
{
}

void GameServer::gameLoop()
{
    while (true)
    {
        auto start = std::chrono::system_clock::now();

        // Begin GameLoop

        // GameEngine
        this->_gameEngine->checkCollisions(this->_entities);

        // Mob IA
    
        // Check game over

        // End GameLoop

        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        ms d = std::chrono::duration_cast<ms>(elapsed_seconds);
        std::this_thread::sleep_for(std::chrono::milliseconds(40) - d);
        std::cout << "finished loop elapsed time: " << d.count() << "ms\n";
    }
}