/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Functions for the Server class.
** @Author: Cédric Hennequin
** @Date:   21-11-2019 14:52:13
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 21-11-2019 23:38:19
*/

#include "Instance.hpp"

Instance::Instance(unsigned short port): _port(port)
{
}

Instance::~Instance()
{
	if (this->isParent()) {
		this->kill();
	}
}

void Instance::setPort(unsigned short port) noexcept
{
	this->_port = port;
}

unsigned short Instance::getPort() const noexcept
{
	return this->_port;
}

void Instance::run()
{
	this->fork();
	if (!this->isParent()) {
		this->launch();
	}
}

void Instance::launch()
{
	while (true) {
		//
	}
}
