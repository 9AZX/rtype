/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#define PORT 54000
#define IP_ADDR "192.168.0.5"

#include <stdlib.h>
#include <memory>
#include <iostream>
#include <SFML/Network.hpp>

class Network {
	public:
		Network();
		~Network();

        void bindSocket();
        void sendData(const char data[]);
        char *receiveData();
	protected:
        sf::UdpSocket _socket;
	private:
};

#endif /* !NETWORK_HPP_ */
