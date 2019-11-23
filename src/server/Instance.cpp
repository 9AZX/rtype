/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Functions for the Server class.
** @Author: Cédric Hennequin
** @Date:   21-11-2019 14:52:13
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 23-11-2019 15:14:23
*/

#include <memory>
#include "Instance.hpp"
#include "Server.hpp"

Instance::Instance(unsigned short port): _port(port)
{
}

#if	!defined(_WIN32) && !defined(_WIN64)
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
	std::thread threadServer(&Instance::loop, this);

	this->_instances.push_back(std::move(threadServer));
	this->_instances.back().detach();
}
#else
void Instance::run()
{
	this->fork();
	if (!this->isParent()) {
		this->loop();
	}
}
#endif

void Instance::loop()
{
	std::unique_ptr<Server> server(new Server(this->_port));

	while (true) {
		//NTD
	}
}

#if	defined(_WIN32) || defined(_WIN64)
unsigned int Instance::countInstances() const noexcept
{
	return static_cast<unsigned int>(this->_instances.size());
}
#endif
