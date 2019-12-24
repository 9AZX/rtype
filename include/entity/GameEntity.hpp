/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEntity
*/

#ifndef	_GAME_ENTITY_HPP_
#define	_GAME_ENTITY_HPP_

#include "IEntity.hpp"

using namespace Entity;

class GameEntity : public IEntity
{
public:
	GameEntity();
	~GameEntity() = default;

public:
	const std::atomic<float> &getPosX() const noexcept final;
	void setPosX(const float x) noexcept final;
	const std::atomic<float> &getPosY() const noexcept final;
	void setPosY(const float y) noexcept final;
	const std::atomic<int> &getType() const noexcept final;
	void setType(type type) noexcept final;
	void move(const float x, const float y) noexcept final;
	bool limits(const float x, const float y) const noexcept final;

private:
	std::atomic<float> _posX;
	std::atomic<float> _posY;
	std::atomic<int> _entityId;
	std::atomic<int> _type;
};

#endif	/* !_GAME_ENTITY_HPP_ */
