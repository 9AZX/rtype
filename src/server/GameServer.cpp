/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameServer
*/

#include <numeric>
#include "GameServer.hpp"
#include "Mob.hpp"

using namespace Entity;

GameServer::GameServer()
{
}

void GameServer::gameLoop()
{
	while (true)
    {
		// Begin GameLoop
		auto start = std::chrono::system_clock::now();

		// GameEngine
		this->_gameEngine->checkCollisions(this->_entities);

		// Loop over entities
		for (size_t i = 0; i < this->_entities.size(); i++) {
			// Remove destroyed entities
			this->removeDestroyedEntities(i);

			// Mob IA
			this->_gameEngine->mobIA(this->_entities[i]);
		}

		// Players movements

		// Check game over

		// End GameLoop
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed_seconds = end - start;
		ms d = std::chrono::duration_cast<ms>(elapsed_seconds);
		std::this_thread::sleep_for(std::chrono::milliseconds(40) - d);
		//std::cout << "finished loop elapsed time: " << d.count() << "ms\n";
	}
}

void GameServer::addPlayer(__attribute__((unused)) sf::Packet &packet) noexcept
{
	//this->_players.push_back(Player());
}

void GameServer::removeDestroyedEntities(size_t i)
{
	if (this->_entities[i].getRemoveEntity()) {
		// delete this->_entities[i];
		this->_entities.erase(this->_entities.begin() + i);
	}
}
