/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Functions for the server class.
** @Author: Cédric Hennequin
** @Date:   21-11-2019 23:45:32
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 21-12-2019 17:08:40
*/

#include "Server.hpp"

Server::Server(unsigned short port) : NetworkUDP(port)
{
	this->_run = true;
	this->bind();
	this->block(true);
}

void Server::network()
{
	sf::Packet packet;
	sf::IpAddress remoteAddress;
	unsigned short remotePort = 0;

	do {
		this->listen(packet, remoteAddress, remotePort);
		#if defined(SERVER_DEBUG_RECV) && SERVER_DEBUG_RECV == true
		this->networkDebug(remoteAddress, remotePort);
		#endif
	} while (this->_run);
}

#if defined(SERVER_DEBUG_RECV) && SERVER_DEBUG_RECV == true
void Server::networkDebug(const sf::IpAddress &addr, const unsigned short port)
{
	std::cout << "Receive from: \"" << addr.toString() << '\"' << std::endl;
	std::cout << "With port: \"" << port << '\"' << std::endl;
}
#endif
