/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEntity
*/

#include "GameEntity.hpp"

GameEntity::GameEntity()
{
	this->_posX = 0;
	this->_posY = 0;
}

const std::atomic<float> &GameEntity::getPosX() const noexcept
{
	return this->_posX;
}

void GameEntity::setPosX(const float x) noexcept
{
	this->_posX = x;
}

const std::atomic<float> &GameEntity::getPosY() const noexcept
{
	return this->_posY;
}

void GameEntity::setPosY(const float y) noexcept
{
	this->_posY = y;
}

const std::atomic<int> &GameEntity::getType() const noexcept
{
	return this->_type;
}

void GameEntity::setType(type type) noexcept
{
	this->_type = type;
}

void GameEntity::move(const float x, const float y) noexcept
{
	if (this->limits(this->_posX + x, this->_posY + y)) {
		return;
	}
	this->_posX = this->_posX + x;
	this->_posY = this->_posY + y;
}

bool GameEntity::limits(const float x, const float y) const noexcept
{
	return (x > 1920 || x < 0) || (y > 1080 || y < 0);
}
