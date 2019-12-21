/*
** EPITECH PROJECT, 2019
** Player
** File description:
** description
** @Author: Cédric Hennequin
** @Date:   28-11-2019 17:28:06
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 01-12-2019 14:02:01
*/

#ifndef	_PLAYER_HPP_
#define _PLAYER_HPP_

#include <string>
#include "IEntity.hpp"

using namespace Entity;

class Player : public IEntity
{
public:
	Player();
	~Player();

private:
	std::string _ip = "";
	std::atomic<bool> _connected;
	std::string _name;

    std::atomic<int> _livesNb;
};

#endif	/* !_PLAYER_HPP_ */
