/*
** EPITECH PROJECT, 2019
** NetworkUDP
** File description:
** Functions for the network class (protocol UDP).
** @Author: Cédric Hennequin
** @Date:   22-11-2019 00:18:37
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 22-12-2019 17:15:01
*/

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
	if (NETWORK_AUTOMATIC_PORT && this->_status == sf::Socket::Error) {
		this->_status = this->_socket.bind(sf::Socket::AnyPort);
	}
	if (this->_status != sf::Socket::Done) {
		throw Exception(NETWORK_BIND_ERR);
	}
	this->_port = this->_socket.getLocalPort();
}

void NetworkUDP::block(const bool state)
{
	this->_socket.setBlocking(state);
}

void NetworkUDP::listen(sf::Packet &packet, sf::IpAddress &remoteAddress,
	unsigned short &remotePort) noexcept
{
	enum sf::Socket::Status type;

	type = this->_socket.receive(packet, remoteAddress, remotePort);
	if (type != sf::Socket::Done) {
		return;
	}
}

bool NetworkUDP::send(sf::Packet &packet, sf::IpAddress &remoteAddress,
	unsigned short &remotePort)
{
	enum sf::Socket::Status type = this->_socket.send(
		packet,
		remoteAddress,
		remotePort
	);

	return type == sf::Socket::Done ? true : false;
}
