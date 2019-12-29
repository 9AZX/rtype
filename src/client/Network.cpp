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
    sf::IpAddress recipient = IP_ADDR;

    if (this->_socket.send(packet, recipient, 4242) != sf::Socket::Done)
        return;
}

bool Network::receiveData()
{
    sf::IpAddress sender;
    unsigned short port;

    if (this->_socket.receive(this->_packet, sender, port) != sf::Socket::Done) {
        return false;
    }
    std::cout << "Receive from " << sender << " on port " << port << " this size " << _packet.getDataSize() << std::endl;
    return true;
}