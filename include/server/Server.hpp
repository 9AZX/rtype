/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Header with all server methods.
** @Author: Cédric Hennequin
** @Date:   19-11-2019 16:11:34
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 21-11-2019 12:49:38
*/

#ifndef	_SERVER_HPP_
#define	_SERVER_HPP_

#include "Fork.hpp"

class Server: public Fork
{
public:
	Server() = default;
	~Server() = default;

private:
	unsigned short _port = 0;
};

#endif	/* !_SERVER_HPP_ */
