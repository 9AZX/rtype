/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Functions for the server class.
** @Author: Cédric Hennequin
** @Date:   21-11-2019 23:45:32
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 29-12-2019 17:14:06
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
		this->extract(packet, remoteAddress);
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

void Server::extract(sf::Packet &packet, sf::IpAddress &address)
{
	int type = NetworkMethods::PACKET_END;

	do {
		packet >> type;
		switch (type) {
			case NetworkMethods::PACKET_PLAYER_NEW:
				this->_game.addPlayer(packet, address);
				break;
			case NetworkMethods::PACKET_PLAYER_MOVE:
				this->_game.playerMove(packet, address);
				break;
			case NetworkMethods::PACKET_END:
				break;
			default:
				type = NetworkMethods::PACKET_END;
				break;
		};
	} while (type != NetworkMethods::PACKET_END);
}

void Server::sendToPlayers()
{
	sf::Packet packet;
	sf::IpAddress ip;
	unsigned short port;

	if (this->_game._players.size() == 0) {
		return;
	}
	packet << NetworkMethods::PACKET_ENTITY;
	packet << static_cast<int>(this->_game._entities.size());
	for (const auto &entity : this->_game._entities) {
		packet << entity->getType().load() << entity->getId().load();
		packet << entity->getPosX() << entity->getPosY().load();
	}
	packet << NetworkMethods::PACKET_PLAYER;
	packet << static_cast<int>(this->_game._players.size());
	for (const auto &player : this->_game._players) {
		packet << player->getId().load() << player->getPosX();
		packet << player->getPosY().load();
	}
	packet << NetworkMethods::PACKET_END;
	for (const auto &player : this->_game._players) {
		ip = player->getIpAddress();
		port = player->getPort().load();
		this->send(packet, ip, port);
	}
}
