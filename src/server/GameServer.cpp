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
}

GameServer::~GameServer()
{
}

void GameServer::gameLoop()
{
    while (true)
    {
        auto start = std::chrono::system_clock::now();

        // <GameLoop>
        this->checkCollisions();
        // </GameLoop>

        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        ms d = std::chrono::duration_cast<ms>(elapsed_seconds);
        std::this_thread::sleep_for(std::chrono::milliseconds(40) - d);
        std::cout << "finished loop elapsed time: " << d.count() << "ms\n";
    }
}

void GameServer::checkCollisions()
{
    for (size_t i = 0; i < this->_entities.size(); i++)
    {
        for (size_t j = 0; j < this->_entities.size(); j++)
        {
            if (i == j) break;
            if (this->checkPosition(i, j)) {
                std::cout << "Collision" << std::endl;
            }
        }
    }
}

bool GameServer::checkPosition(size_t i, size_t j) const
{
    if (this->_entities[i].getPosX() == this->_entities[j].getPosY()
        && this->_entities[i].getPosY() == this->_entities[j].getPosY()) {
            return true;
    } else return false;
}

bool GameServer::checkEntityType(size_t i, size_t j) const
{
    if (this->_entities[i].getType() == this->_entities[j].getType()) {
                return true;
    } else return false;
}