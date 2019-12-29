/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#define PORT 54000
#define IP_ADDR "127.0.0.1"
#define PORT_SERV 4242

#include <stdlib.h>
#include <memory>
#include <iostream>
#include <SFML/Network.hpp>

class Network
{
public:
	Network();
	~Network();

	void bindSocket();
	void sendData(sf::Packet &packet);
	bool receiveData();
	bool setServerInfo(std::string, std::string);

protected:
	sf::UdpSocket _socket;

public:
	sf::Packet _packet;

private:
	std::string _serverIp;
	unsigned short _serverPort = 4242;
};

#endif /* !NETWORK_HPP_ */
