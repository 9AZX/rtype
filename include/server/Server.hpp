/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Header for the Server class.
** @Author: Cédric Hennequin
** @Date:   21-11-2019 23:44:41
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 23-11-2019 14:04:57
*/

#ifndef	_SERVER_HPP_
#define	_SERVER_HPP_

#include <vector>
#include <thread>

class Server
{
public:
	Server() = default;
	Server(unsigned short port);
	~Server() = default;

private:
	unsigned short _port = 0;
	std::vector<std::thread> _threads;
};

#endif	/* !_SERVER_HPP_ */
