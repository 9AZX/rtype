/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEngine
*/

#ifndef	_GAME_ENGINE_HPP_
#define	_GAME_ENGINE_HPP_

#include "GameEntity.hpp"
#include "GameServer.hpp"

using namespace Entity;

class GameEngine
{
public:
	GameEngine();
	~GameEngine() = default;

public:
	void checkCollisions(std::vector<GameEntity> &);
	bool checkPosition(GameEntity &, GameEntity &) const;
	bool checkEntityType(GameEntity &, GameEntity &) const;
	void mobIA(GameEntity &);
};

#endif	/* !_GAME_ENGINE_HPP_ */
