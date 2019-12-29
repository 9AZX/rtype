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

#include <stdlib.h>
#include <memory>
#include <iostream>
#include <SFML/Network.hpp>

class Network {
	public:
		Network();
		~Network();

        void bindSocket();
        void sendData(sf::Packet &packet);
        bool receiveData();
		void setServerInfo(std::string, unsigned short);
	protected:
        sf::UdpSocket _socket;
	public:
		sf::Packet _packet;
	private:
		sf::IpAddress _serverIp;
		unsigned short _serverPort = 4242;
};

#endif /* !NETWORK_HPP_ */
