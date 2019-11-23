/*
** EPITECH PROJECT, 2019
** NetworkUDP
** File description:
** Functions for the network class (protocol UDP).
** @Author: Cédric Hennequin
** @Date:   22-11-2019 00:18:37
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 22-11-2019 00:56:33
*/

#include <iostream>
#include "NetworkUDP.hpp"
#include "Exception.hpp"

NetworkUDP::NetworkUDP(unsigned short port): _port(port)
{
}

NetworkUDP::~NetworkUDP()
{
	this->_socket.unbind();
}

void NetworkUDP::setPort(unsigned short port) noexcept
{
	this->_port = port;
}

unsigned short NetworkUDP::getPort() const noexcept
{
	return this->_port;
}

void NetworkUDP::bind()
{
	this->_status = this->_socket.bind(
		this->_port == 0 ? sf::Socket::AnyPort : this->_port
	);
	if (this->_status != sf::Socket::Done) {
		throw Exception(NETWORK_BIND_ERR);
	}
}
