/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Functions for the Server class.
** @Author: Cédric Hennequin
** @Date:   21-11-2019 14:52:13
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 28-12-2019 23:44:52
*/

// TODO: delete after test(s).
#include <iostream>
#include <memory>
#include "Instance.hpp"
#include "Server.hpp"

Instance::Instance(unsigned short port) : _port(port)
{
}

#if !defined(_WIN32) && !defined(_WIN64)
Instance::~Instance()
{
	if (this->isParent()) {
		this->kill();
	}
}
#else
Instance::~Instance()
{
}
#endif

void Instance::setPort(unsigned short port) noexcept
{
	this->_port = port;
}

unsigned short Instance::getPort() const noexcept
{
	return this->_port;
}

#if	defined(_WIN32) || defined(_WIN64)
void Instance::run()
{
	std::thread threadServer(&Instance::instance, this);

	this->_instances.push_back(std::move(threadServer));
	this->_instances.back().detach();
}

unsigned int Instance::countInstances() const noexcept
{
	return static_cast<unsigned int>(this->_instances.size());
}
#else
void Instance::run()
{
	this->fork();
	if (!this->isParent()) {
		this->instance();
	}
}
#endif

void Instance::instance()
{
	std::unique_ptr<Server> server(new Server(this->_port));
	std::thread threadNetwork(&Server::network, server.get());

	server->_threads.push_back(std::move(threadNetwork));
	server->_threads.back().detach();
	while (true) {
		// Begin GameLoop
		auto start = std::chrono::system_clock::now();

		// GameEngine
		server->_game._gameEngine->checkCollisions(server->_game._entities);

		// Loop over entities
		for (size_t i = 0; i < server->_game._entities.size(); i++) {
			// Remove destroyed entities
			server->_game.removeDestroyedEntities(i);

			// Mob IA
			server->_game._gameEngine->mobIA(*server->_game._entities[i]);

			// Mob generation
		}

		// Mob generation
		server->_game.mobGeneration();

		// Players movements

		// Check game over

		// End GameLoop
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed_seconds = end - start;
		ms d = std::chrono::duration_cast<ms>(elapsed_seconds);
		std::this_thread::sleep_for(std::chrono::milliseconds(40) - d);
		//std::cout << "finished loop elapsed time: " << d.count() << "ms\n";

		// Call network.
		server->sendToPlayers();
	}
	server->_game.gameLoop();
}
