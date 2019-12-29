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
    this->_socket.setBlocking(false);
}

void Network::sendData(sf::Packet &packet)
{
    if (this->_socket.send(packet, this->_serverIp, this->_serverPort) != sf::Socket::Done)
        return;
}

bool Network::receiveData()
{
    sf::IpAddress sender;
    unsigned short port;

    if (this->_socket.receive(this->_packet, sender, port) != sf::Socket::Done) {
        return false;
    }
    return true;
}

void Network::setServerInfo(std::string ip, unsigned short port)
{
    this->_serverIp = ip;
    this->_serverPort = port;
}