/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Header with all server methods.
** @Author: Cédric Hennequin
** @Date:   19-11-2019 16:11:34
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 23-11-2019 15:50:17
*/

#ifndef _INSTANCE_HPP_
#define _INSTANCE_HPP_

#if !defined(_WIN32) && !defined(_WIN64)
#include "Fork.hpp"
#else
#include <thread>
#include <vector>
#endif

#include "GameServer.hpp"

#define SERVER_NEW_INSTANCE "New server instance run (on pid: "
#define SERVER_PORT_NULL 0

#if defined(_WIN32) || defined(_WIN64)
class Instance
#else
class Instance : public Fork
#endif
{
public:
	Instance() = default;
	Instance(unsigned short port);
	~Instance();

public:
	void setPort(unsigned short port) noexcept;
	unsigned short getPort() const noexcept;
	void run();
#if defined(_WIN32) || defined(_WIN64)
	unsigned int countInstances() const noexcept;
#endif
	void instance();

private:
	unsigned short _port = 0;
#if defined(_WIN32) || defined(_WIN64)
	std::vector<std::thread> _instances;
#endif
	GameServer gameServ;
};

#endif /* !_INSTANCE_HPP_ */
