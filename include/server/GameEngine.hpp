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
	bool isGameInProgress() const noexcept;
	void setGameStart(bool) noexcept;

private:
	bool _gameIP = false;
};

#endif /* !_GAME_ENGINE_HPP_ */
