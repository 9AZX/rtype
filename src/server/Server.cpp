/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Functions for the server class.
** @Author: Cédric Hennequin
** @Date:   21-11-2019 23:45:32
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 18-12-2019 14:53:29
*/

#include <iostream>
#include "Server.hpp"

Server::Server(unsigned short port) : NetworkUDP(port)
{
}

void Server::network()
{
	sf::Packet packet;
	sf::IpAddress remoteAddress;
	unsigned short remotePort = 0;

	do {
		this->listen(packet, remoteAddress, remotePort);
		if (remoteAddress.toString() != "0.0.0.0") {
			std::cout << "Receive from: \"" << remoteAddress.toString();
			std::cout << '\"' << std::endl << "With port: \"";
			std::cout << remotePort << '\"' << std::endl;
		}
	} while (this->_run);
}
