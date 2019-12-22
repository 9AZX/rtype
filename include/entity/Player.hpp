/*
** EPITECH PROJECT, 2019
** Player
** File description:
** description
** @Author: Cédric Hennequin
** @Date:   28-11-2019 17:28:06
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 22-12-2019 17:27:55
*/

#ifndef	_PLAYER_HPP_
#define _PLAYER_HPP_

#include <string>
#include "IEntity.hpp"

#define	PLAYER_DEFAULT_PORT	7777

using namespace Entity;

class Player : public IEntity
{
public:
	Player();
	~Player();

public:
	std::string _ip = "127.0.0.1";
	unsigned short _port = PLAYER_DEFAULT_PORT;
	std::atomic<bool> _connected;
	std::atomic<int> _id;
	std::atomic<int> _livesNb;
};

#endif	/* !_PLAYER_HPP_ */
