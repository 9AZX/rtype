/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Header for the Server class.
** @Author: Cédric Hennequin
** @Date:   21-11-2019 23:44:41
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 18-12-2019 15:07:11
*/

#ifndef	_SERVER_HPP_
#define	_SERVER_HPP_

#include <vector>
#include <thread>
#include <atomic>
#include <utility>

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

public:
	std::vector< std::thread> _threads;
	std::atomic<bool> _run;
	GameServer _game;
};

#endif	/* !_SERVER_HPP_ */
