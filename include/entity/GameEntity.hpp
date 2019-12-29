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

class GameEntity : public IEntity
{
public:
	GameEntity();
	~GameEntity() = default;

public:
	const std::atomic<int> &getId() const noexcept final;
	const std::atomic<int> &getPosX() const noexcept final;
	void setPosX(const int x) noexcept final;
	const std::atomic<int> &getPosY() const noexcept final;
	void setPosY(const int y) noexcept final;
	const std::atomic<int> &getType() const noexcept final;
	void setType(type type) noexcept final;
	void move(const int x, const int y) noexcept final;
	bool limits(const int x, const int y) const noexcept final;
	bool getRemoveEntity() const noexcept;
	void setRemoveEntity() noexcept;
	void ia() noexcept;

private:
	std::atomic<int> _posX;
	std::atomic<int> _posY;
	std::atomic<int> _entityId;
	std::atomic<int> _type;
	std::atomic<bool> _removeEntity;
	int _loopCount = 0;
	bool _isShooting = false;
	
};

#endif /* !_GAME_ENTITY_HPP_ */
