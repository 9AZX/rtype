/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Game
*/

#ifndef _GAME_SERVER_HPP_
#define _GAME_SERVER_HPP_

#include <time.h>
#include <chrono>
#include <ctime>
#include <thread>
#include <vector>
#include <SFML/Network.hpp>
#include "GameEngine.hpp"
#include "Player.hpp"

using ms = std::chrono::milliseconds;

class GameServer
{
public:
	GameServer();
	~GameServer() = default;

public:
	void gameLoop();
	void addPlayer(sf::Packet &packet, sf::IpAddress &address) noexcept;
	void playerMove(sf::Packet &packet, sf::IpAddress &address) noexcept;
	void removeDestroyedEntities(size_t);
	void mobGeneration() noexcept;

public:
	std::unique_ptr<GameEngine> _gameEngine = nullptr;
	std::vector<std::unique_ptr<Player>> _players = {};
	std::vector<std::unique_ptr<GameEntity>> _entities = {};
};

#endif /* !_GAME_SERVER_HPP_ */
