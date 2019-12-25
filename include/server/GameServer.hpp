/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Game
*/

#ifndef	_GAME_SERVER_HPP_
#define	_GAME_SERVER_HPP_

#include <time.h>
#include <chrono>
#include <ctime>
#include <thread>
#include <vector>
#include <SFML/Network.hpp>
#include "GameEntity.hpp"
#include "Player.hpp"

using namespace Entity;

using ms = std::chrono::milliseconds;

class GameServer
{
public:
	GameServer();
	~GameServer() = default;

public:
	void gameLoop();
	void addPlayer(sf::Packet &packet) noexcept;

public:
	std::unique_ptr<GameEngine> _gameEngine;
	std::vector<Player> _players;
	std::vector<GameEntity> _entities;
};

#endif	/* !_GAME_SERVER_HPP_ */
