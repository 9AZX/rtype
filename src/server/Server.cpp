/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Functions for the server class.
** @Author: Cédric Hennequin
** @Date:   21-11-2019 23:45:32
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 16-12-2019 14:10:45
*/

#include <iostream>
#include "Server.hpp"

Server::Server(unsigned short port) : NetworkUDP(port)
{
}

void Server::network()
{
	sf::Packet packet;
	unsigned short remotePort;
	sf::IpAddress remoteAddress;

	do {
		this->listen(packet, remoteAddress, remotePort);
		std::cout << "Receive from: \"" << remoteAddress.toString();
		std::cout << '\"' << std::endl;
	} while (this->_run);
}
