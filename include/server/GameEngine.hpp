/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEngine
*/

#ifndef _GAME_ENGINE_HPP_
#define _GAME_ENGINE_HPP_

#include "GameEntity.hpp"
#include <vector>

#define SPRITE_DIM_X 34
#define SPRITE_DIM_Y 17

using namespace Entity;

class GameEngine
{
public:
	GameEngine();
	~GameEngine() = default;

public:
	void checkCollisions(std::vector<GameEntity> &) noexcept;
	bool checkPosition(GameEntity &, GameEntity &) const noexcept;
	bool checkEntityType(GameEntity &, GameEntity &) const noexcept;
	void mobIA(GameEntity &) noexcept;
};

#endif /* !_GAME_ENGINE_HPP_ */
