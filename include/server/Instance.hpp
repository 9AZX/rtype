/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Header with all server methods.
** @Author: Cédric Hennequin
** @Date:   19-11-2019 16:11:34
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 23-11-2019 13:59:43
*/

#ifndef	_INSTANCE_HPP_
#define	_INSTANCE_HPP_

#include "Fork.hpp"

#define	SERVER_NEW_INSTANCE	"New server instance run (on pid: "
#define	SERVER_PORT_NULL	0

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
	void loop();

private:
	unsigned short _port = 0;
};

#endif	/* !_INSTANCE_HPP_ */
