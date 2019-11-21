/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Functions for the Server class.
** @Author: Cédric Hennequin
** @Date:   21-11-2019 14:52:13
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 21-11-2019 16:20:26
*/

#include <iostream>
#include "Server.hpp"

Server::Server(unsigned short port): _port(port)
{
}

Server::~Server()
{
	if (this->isParent()) {
		this->kill();
	}
}

void Server::setPort(unsigned short port) noexcept
{
	this->_port = port;
}

unsigned short Server::getPort() const noexcept
{
	return this->_port;
}

void Server::run()
{
	this->fork();
	if (!this->isParent()) {
		this->launch();
	}
	return;
}

void Server::launch()
{
	std::cout << std::endl << "Server run..." << std::endl;
}
