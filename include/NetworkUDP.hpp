/*
** EPITECH PROJECT, 2019
** NetworkUDP
** File description:
** Header for the network class.
** @Author: Cédric Hennequin
** @Date:   22-11-2019 00:12:01
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 28-11-2019 16:07:18
*/

#ifndef	_NETWORK_UDP_HPP_
#define	_NETWORK_UDP_HPP_

#include <SFML/Network.hpp>

#define NETWORK_BIND_ERR	"An error occured during the bind."

class NetworkUDP
{
public:
	NetworkUDP() = default;
	NetworkUDP(unsigned short port);
	virtual ~NetworkUDP();

public:
	void setPort(unsigned short port) noexcept;
	unsigned short getPort() const noexcept;
	void bind();
	void listen();

private:
	sf::UdpSocket _socket;
	unsigned short _port = 0;
	sf::Socket::Status _status = sf::Socket::Status::NotReady;
};

#endif	/* !_NETWORK_UDP_HPP_ */
