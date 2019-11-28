/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Header for the Server class.
** @Author: Cédric Hennequin
** @Date:   21-11-2019 23:44:41
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 28-11-2019 16:36:19
*/

#ifndef	_SERVER_HPP_
#define	_SERVER_HPP_

#include <vector>
#include <thread>
#include "NetworkUDP.hpp"

class Server: public NetworkUDP
{
public:
	Server() = default;
	Server(unsigned short port);
	~Server() = default;

private:
	std::vector<std::thread> _threads;
};

#endif	/* !_SERVER_HPP_ */
