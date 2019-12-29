/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameServer
*/

#include <numeric>
#include "GameServer.hpp"
#include <utility>
#include "Mob.hpp"
#include <iostream>

using namespace Entity;

GameServer::GameServer()
{
	this->_gameEngine = std::make_unique<GameEngine>();
}

void GameServer::gameLoop()
{
	//NTD
}

void GameServer::addPlayer(sf::Packet &packet, sf::IpAddress &address) noexcept
{
	unsigned short port = 0;

	packet >> port;
	this->_players.push_back(std::make_unique<Player>(
		address.toString(),
		port
	));
	std::cout << "New player \"" << address.toString() << "\": " << port;
	std::cout << std::endl;
}

void GameServer::playerMove(sf::Packet &packet, sf::IpAddress &address) noexcept
{
	int move = 0;

	packet >> move;
	for (auto const &player : this->_players) {
		if (player->getIpAddress() == address.toString()) {
			switch (move) {
				case 0: // UP
					player->setPosY(player->getPosY() - 20);
					break;
				case 1: // RIGHT
					player->setPosX(player->getPosX() + 20);
					break;
				case 2: // DOWN
					player->setPosY(player->getPosY() + 20);
					break;
				case 3: // LEFT
					player->setPosX(player->getPosX() - 20);
					break;
				default:
					break;
			}
			break;
		}
	}
}

void GameServer::removeDestroyedEntities(size_t i)
{
	if (this->_entities[i]->getRemoveEntity())
	{
		// delete this->_entities[i];
		// this->_entities.erase(this->_entities.begin() + i);
	}
}

void GameServer::mobGeneration() noexcept
{
	int nbMobs = 0;

	for (size_t i = 0; i < this->_entities.size(); i++) {
		if (this->_entities[i]->getType() >= MOB1)
			nbMobs++;
	}
	if (!nbMobs) {
		this->_entities.push_back(std::make_unique<Mob>());
		this->_entities.push_back(std::make_unique<Mob>());
		this->_entities.push_back(std::make_unique<Mob>());
	}
}
