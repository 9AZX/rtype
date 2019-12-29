/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEntity
*/

#ifndef _GAME_ENTITY_HPP_
#define _GAME_ENTITY_HPP_

#include "IEntity.hpp"

using namespace Entity;

#define ENTITY_WIDTH 102
#define ENTITY_HEIGHT 51

class GameEntity : public IEntity
{
public:
	GameEntity();
	~GameEntity() = default;

public:
	const std::atomic<int> &getId() const noexcept final;
	const std::atomic<float> &getPosX() const noexcept final;
	void setPosX(const float x) noexcept final;
	const std::atomic<float> &getPosY() const noexcept final;
	void setPosY(const float y) noexcept final;
	const std::atomic<int> &getType() const noexcept final;
	void setType(type type) noexcept final;
	void move(const float x, const float y) noexcept final;
	bool limits(const float x, const float y) const noexcept final;
	bool getRemoveEntity() const noexcept;
	void setRemoveEntity() noexcept;
	void ia() noexcept;

private:
	std::atomic<float> _posX;
	std::atomic<float> _posY;
	std::atomic<int> _entityId;
	std::atomic<int> _type;
	std::atomic<bool> _removeEntity;
	int _loopCount = 0;
	int _moveCount = 0;
	int _direction = -1;
	int _nbMovements = 0;
	bool _isShooting = false;
	
};

#endif /* !_GAME_ENTITY_HPP_ */
