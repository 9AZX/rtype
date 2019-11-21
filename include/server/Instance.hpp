/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Header with all server methods.
** @Author: Cédric Hennequin
** @Date:   19-11-2019 16:11:34
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 21-11-2019 23:37:22
*/

#ifndef	_SERVER_HPP_
#define	_SERVER_HPP_

#include "Fork.hpp"

#define	SERVER_NEW_INSTANCE	"New server instance run (on pid: "

class Instance: public Fork
{
public:
	Instance() = default;
	Instance(unsigned short port);
	~Instance();

public:
	void setPort(unsigned short port) noexcept;
	unsigned short getPort() const noexcept;
	void run();
	void launch();

private:
	unsigned short _port = 0;
};

#endif	/* !_SERVER_HPP_ */
