/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEngine
*/

#ifndef	_GAME_ENGINE_HPP_
#define	_GAME_ENGINE_HPP_

#include <vector>
#include "GameEntity.hpp"

using namespace Entity;

class GameEngine
{
public:
	GameEngine();
	~GameEngine() = default;

public:
	void checkCollisions(std::vector<GameEntity> &entities);
	bool checkPosition(GameEntity &a, GameEntity &b) const;
	bool checkEntityType(GameEntity &a, GameEntity &b) const;
};

#endif	/* !_GAME_ENGINE_HPP_ */
