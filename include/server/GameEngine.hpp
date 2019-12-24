/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEngine
*/

#ifndef	_GAME_ENGINE_HPP_
#define	_GAME_ENGINE_HPP_

#include <vector>
#include "GameServer.hpp"

using namespace Entity;

class GameEngine : public GameServer
{
public:
	GameEngine();
	~GameEngine() = default;

public:
	void checkCollisions();
	bool checkPosition(size_t i, size_t j) const;
	bool checkEntityType(size_t i, size_t j) const;
	void mobIA(size_t i);
};

#endif	/* !_GAME_ENGINE_HPP_ */
