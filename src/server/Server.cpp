/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Functions for the server class.
** @Author: Cédric Hennequin
** @Date:   21-11-2019 23:45:32
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 22-12-2019 18:00:15
*/

#include <iostream>
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
		if (packet.getDataSize() <= NETWORK_MIN_SIZE) {
			packet.clear();
			continue;
		}
		this->extract(packet);
		packet.clear();
	} while (this->_run);
}

#if defined(SERVER_DEBUG_RECV) && SERVER_DEBUG_RECV == true
void Server::networkDebug(const sf::IpAddress &addr, const unsigned short port)
{
	std::cout << "Receive from: \"" << addr.toString() << '\"' << std::endl;
	std::cout << "With port: \"" << port << '\"' << std::endl;
}
#endif

void Server::extract(sf::Packet &packet)
{
	int type = NetworkMethods::PACKET_END;

	do {
		packet >> type;
		switch (type) {
			case NetworkMethods::PACKET_PLAYER_NEW:
				break;
			case NetworkMethods::PACKET_END:
				break;
			default:
				type = NetworkMethods::PACKET_END;
				break;
		};
	} while (type != NetworkMethods::PACKET_END);
}
