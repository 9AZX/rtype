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

using namespace Entity;

GameServer::GameServer()
{
	this->_gameEngine = std::make_unique<GameEngine>();
}

void GameServer::gameLoop()
{
	//NTD
}

void GameServer::addPlayer(sf::Packet &packet) noexcept
{
	std::string ip = "";
	unsigned short port = 0;

	packet >> ip;
	packet >> port;
	this->_players.push_back(std::make_unique<Player>(ip, port));
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
		this->_entities.emplace_back(new Mob());
	}
}