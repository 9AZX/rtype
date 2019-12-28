/*
** EPITECH PROJECT, 2019
** Player
** File description:
** description
** @Author: Cédric Hennequin
** @Date:   28-11-2019 17:28:06
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 28-12-2019 15:34:45
*/

#ifndef	_PLAYER_HPP_
#define _PLAYER_HPP_

#include <string>
#include "GameEntity.hpp"

#define	PLAYER_DEFAULT_PORT	7777
#define	PLAYER_DEFAULT_LIVES	4

using namespace Entity;

class Player : public GameEntity
{
public:
	Player();
	Player(const std::string &ip, const unsigned short port);
	~Player() = default;

public:
	void setIpAddress(const std::string &address) noexcept;
	const std::string &getIpAddress() const noexcept;
	void setPort(const unsigned short port) noexcept;
	const std::atomic<unsigned short> &getPort() const noexcept;
	void setConnected(const bool connected) noexcept;
	const std::atomic<bool> &isConnected() const noexcept;
	void setId(const int id) noexcept;
	const std::atomic<int> &getId() const noexcept;
	void setLives(const int lives) noexcept;
	const std::atomic<int> &getLives() const noexcept;
	void ia();

private:
	std::string _ip = "127.0.0.1";
	std::atomic<unsigned short> _port;
	std::atomic<bool> _connected;
	std::atomic<int> _id;
	std::atomic<int> _lives;
};

#endif	/* !_PLAYER_HPP_ */
