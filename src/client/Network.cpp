/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Network
*/

#include "Network.hpp"

Network::Network()
{
}

Network::~Network()
{
}

void Network::bindSocket()
{
    if (this->_socket.bind(PORT) != sf::Socket::Done)
        return;
}

void Network::sendData(const char data[])
{
    sf::IpAddress recipient = IP_ADDR;

    if (this->_socket.send(data, 100, recipient, PORT) != sf::Socket::Done)
        return;
}

char *Network::receiveData()
{
    char *data = (char *)malloc(sizeof(char) * 2048);
    std::size_t received;
    sf::IpAddress sender;
    unsigned short port;


    if (this->_socket.receive(data, 100, received, sender, port) != sf::Socket::Done)
        return NULL;
    std::cout << "Received " << received << " bytes from " << sender << " on port " << port << std::endl;
    return data;
}