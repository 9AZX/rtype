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
#include "Pos.hpp"

using namespace Entity;

namespace Entity
{
	class Player : public Pos
	{
	public:
		Player();
		~Player() = default;

	private:
		std::string _ip = "";
		std::atomic<bool> _connected;
	};
}
#endif	/* !_PLAYER_HPP_ */
