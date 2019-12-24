/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Player
*/

#include "Player.hpp"

Player::Player()
{
	this->setPort(PLAYER_DEFAULT_PORT);
	std::atomic_init(&this->_connected, false);
	std::atomic_init(&this->_id, -1);
	std::atomic_init(&this->_lives, PLAYER_DEFAULT_LIVES);
}

Player::Player(const std::string &ip, const unsigned short port)
{
	this->_ip = ip;
	this->setPort(port);
	std::atomic_init(&this->_connected, false);
	std::atomic_init(&this->_id, -1);
	std::atomic_init(&this->_lives, PLAYER_DEFAULT_LIVES);
}

void Player::setIpAddress(const std::string &address) noexcept
{
	this->_ip = address;
}

const std::string &Player::getIpAddress() const noexcept
{
	return this->_ip;
}

void Player::setPort(const unsigned short port) noexcept
{
	this->_port = port;
}

const std::atomic<unsigned short> &Player::getPort() const noexcept
{
	return this->_port;
}

void Player::setConnected(const bool isConnected) noexcept
{
	this->_connected = isConnected;
}

const std::atomic<bool> &Player::isConnected() const noexcept
{
	return this->_connected;
}

void Player::setId(const int id) noexcept
{
	this->_id = id;
}

const std::atomic<int> &Player::getId() const noexcept
{
	return this->_id;
}

void Player::setLives(const int lives) noexcept
{
	this->_lives = lives;
}

const std::atomic<int> &Player::getLives() const noexcept
{
	return this->_lives;
}
