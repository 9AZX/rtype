/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Header for the Server class.
** @Author: Cédric Hennequin
** @Date:   21-11-2019 23:44:41
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 28-12-2019 23:22:06
*/

#ifndef	_SERVER_HPP_
#define	_SERVER_HPP_

#define	SERVER_DEBUG_RECV	false

#include <vector>
#include <thread>
#include <atomic>
#include <utility>
#if defined(SERVER_DEBUG_RECV) && SERVER_DEBUG_RECV == true
#include <iostream>
#endif
#include "NetworkUDP.hpp"
#include "GameServer.hpp"

class Server: public NetworkUDP
{
public:
	Server() = default;
	Server(unsigned short port);
	~Server() = default;

public:
	void network();
#if defined(SERVER_DEBUG_RECV) && SERVER_DEBUG_RECV == true
	void networkDebug(const sf::IpAddress &addr, const unsigned short port);
#endif
	void sendToPlayers();

private:
	void extract(sf::Packet &packet);

public:
	std::vector< std::thread> _threads;
	std::atomic<bool> _run;
	GameServer _game;
};

#endif	/* !_SERVER_HPP_ */
