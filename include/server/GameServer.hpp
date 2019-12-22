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
#include "Player.hpp"

using namespace Entity;

using ms = std::chrono::milliseconds;

class GameServer
{
public:
	GameServer();
	~GameServer();

public:
	void gameLoop();

public:
	std::unique_ptr<GameEngine> _gameEngine;
	std::vector<Player> _players;
	std::vector<GameEntity> _entities;
};

#endif /* !GAMESERVER_HPP_ */
